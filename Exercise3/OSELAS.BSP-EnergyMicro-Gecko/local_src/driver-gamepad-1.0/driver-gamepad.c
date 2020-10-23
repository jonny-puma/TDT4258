/*
 * This is a demo Linux kernel module.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

/*
 * template_init - function to insert this module into kernel space
 *
 * This is the first of two exported functions to handle inserting this
 * code into a running kernel
 *
 * Returns 0 if successfull, otherwise -1
 */

static int __init template_init(void)
{
	printk("Hello World, here is your module speaking\n");
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
}

/* user program opens the driver */
static int my_open (struct inode *inode , struct file *filp );

/* user program closes the driver */
static int my_release (struct inode *inode , struct file *filp );

/* user program reads from the driver */
static ssize_t my_read (struct file *filp, char user *buff, size_t count , loff_t *offp );

/* user program writes to the driver */
static ssize_t my_write (struct file *filp , const char user *buff, size_t count , loff_t *offp );


static struct file_operations my_fops = { 
	.owner = THIS MODULE,
	.read = my_read,
	.write = my_write,
	.open = my_open,
	.release = my_release 
};

struct class ∗cl; dev t devno;
...
cl = class create (THIS MODUL sE, ”my class name”); device create(cl, NULL, devno, NULL, ”my class name”);

module_init(template_init);
module_exit(template_cleanup);

MODULE_DESCRIPTION("Small module, demo only, not very useful.");
MODULE_LICENSE("GPL");

