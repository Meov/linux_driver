

#obj-m := comip-powerkey.o

#all :
#	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
#clean:
#	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean


ifneq  ($(KERNELRELEASE),)
obj-m:= comip-powerkey.o
$(info "2nd")
else
KDIR := /lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
all:
	$(info "1st")
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -f *.ko *.o *.symvers *.mod.c *.mod.o *.order
endif