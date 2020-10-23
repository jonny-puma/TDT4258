/*
 * This is a demo Linux kernel module.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/cdev.h>
#include <linux/device.h>



#include "efm32gg.h"

/* Function declarations */
static int gamepad_open(struct inode *inode , struct file *filp );
static int gamepad_release(struct inode *inode , struct file *filp );
static ssize_t gamepad_read(struct file *filp, char user *buff, size_t count , loff_t *offp );
static ssize_t gamepad_write(struct file *filp , const char user *buff, size_t count , loff_t *offp );
static irqreturn_t interrupt_handler(int irq, void* dev_id, struct pr_regs* regs);
static int gamepad_fasync(int fd, struct file *filp, int mode);

/* Define */
#define GPIO_EVEN_IRQ_LINE 17
#define GPIO_ODD_IRQ_LINE 18
#define NAME "gamepad"
#define COUNT 1


/* Static variables */
static dev_t dev_no;
struct cdev gamepad_cdev;
struct class *cl;
struct fasync_struct *async_queue;

static struct file_operations gamepad_fops = { 
	.owner = THIS_MODULE,
	.read = gamepad_open_read,
	.write = gamepad_write,
	.open = gamepad_open,
	.release = gamepad_release,
	.fasync = gamepad_fasync
};


/*
 * template_init - function to insert this module into kernel space
 *
 * This is the first of two exported functions to handle inserting this
 * code into a running kernel
 *
 * Returns 0 if successfull, otherwise -1
 */

static int __init gamepad_init(void)
{
	printk(KERN_INFO "Driver init\n");

	int res = alloc_chrdev_radion(&dev_no, 0, COUNT, NAME);

	if (res){
		printk(KERN_INFO "Failed to allocate\n");
		return -1;
	}

	if (request_mem_region(GPIO_PC_MODEL, 1, NAME) == NULL){
		printk(KERN_INFO "Request GPIO_PC_MODEL failed\n");
		return -1;
	}
	if (request_mem_region(GPIO_PC_DOUT, 1, NAME) == NULL){
		printk(KERN_INFO "Request GPIO_PC_DOUT failed\n");
		return -1;
	}
	// Might be the only region we actually need?
	if (request_mem_region(GPIO_PC_DIN, 1, NAME) == NULL){
		printk(KERN_INFO "Request GPIO_PC_DIN failed\n");
		return -1;
	}


	cdev_init(&gamepad_cdev, &gamepad_fops);
	gamepad_cdev.owner = THIS_MODULE;
	res = cdev_add(&gamepad_cdev, dev_no, COUNT);
	if (res){
		printk(KERN_NOTICE "Error adding cdev");
	}

	cl = class_create(THIS_MODULE, NAME);
	dev_no_create(cl, NULL, dev_no, NULL, NAME);

	// Similar to previous exercises
	iowrite32(0x33333333, GPIO_PC_MODEL);
    iowrite32(0xFF, GPIO_PC_DOUT);
    iowrite32(0x22222222, GPIO_EXTIPSELL);

	request_irq(GPIO_EVEN_IRQ_LINE, (irq_handler_t)interrupt_handler, 0, NAME, &gamepad_cdev);
	request_irq(GPIO_ODD_IRQ_LINE, (irq_handler_t)interrupt_handler, 0, NAME, &gamepad_cdev);

	// Enable interrupts
	iowrite32(0xFF, GPIO_EXTIFALL);
    iowrite32(0x00FF, GPIO_IEN);
    iowrite32(0xFF, GPIO_IFC);

	printk(KERN_INFO "Gamepad driver successfully loaded.\n");
	return 0;
}

/*
 * template_cleanup - function to cleanup this module from kernel space
 *
 * This is the second of two exported functions to handle cleanup this
 * code from a running kernel
 */

static void __exit template_cleanup(void)
{
	printk("Short life for a small module...\n");

	// Disable interrupts
	iowrite32(0x0000, GPIO_IEN);

	free_irq(GPIO_EVEN_IRQ_LINE, &gamepad_cdev);
	free_irq(GPIO_ODD_IRQ_LINE, &gamepad_cdev);

	release_mem_region(GPIO_PC_MODEL, 1);
	release_mem_region(GPIO_PC_DOUT, 1);
	release_mem_region(GPIO_PC_DIN, 1);

	device_destroy(cl, dev_no);
	class_destroy(cl);
	cdev_del(&gamepad_cdev);
	unregister_chrdev_region(dev_no, COUNT);
}

/* user program opens the driver */
static int gamepad_open(struct inode *inode , struct file *filp)
{
	printk(KERN_INFO "Driver opened\n");
	return 0;
}

/* user program closes the driver */
static int gamepad_release(struct inode *inode , struct file *filp)
{
	printk(KERN_INFO "Driver released\n");
	return 0;
}

/* user program reads from the driver */
static ssize_t gamepad_read(struct file *filp, char user *buff, size_t count , loff_t *offp)
{
	printk(KERN_INFO "Driver read\n");
	return 1; 
}

/* user program writes to the driver */
static ssize_t gamepad_write(struct file *filp , const char user *buff, size_t count , loff_t *offp)
{
	printk(KERN_INFO "Driver write\n");
	return 1;
}


static irqreturn_t interrupt_handler(int irq, void* dev_id, struct pr_regs* regs){
	printk(KERN_ALERT "Handling interrupt\n");
	iowrite32(ioread32(GPIO_IF), GPIO_IFC);
	// ASYNC SHIT
	if(async_queue){
		kill_fasync(&async_queue, SIGIO, POLL_IN);
	}
	return IRQ_HANDLED;
}


module_init(gamepad_init);
module_exit(gamepad_cleanup);

MODULE_DESCRIPTION("Small module, demo only, not very useful.");
MODULE_LICENSE("GPL");

