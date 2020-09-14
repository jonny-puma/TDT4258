# Example Makefile
#
# Exercise 1, TDT4258

.PHONY: baseline efficient
baseline efficient :
	$(MAKE) -C $@
	mv $@/ex1.bin $@.bin
	-eACommander.sh -r --address 0x00000000 -f "$@.bin" -r


.PHONY: clean
clean : 
	$(MAKE) -C baseline clean
	$(MAKE) -C efficient clean
	rm baseline.bin efficient.bin


