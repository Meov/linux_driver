#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/ioport.h>
 
static struct resource beep_resource[] =
{
	[0] ={
		.start = 0x114000a0,
		.end =  0x114000a0 + 0x4,
		.flags = IORESOURCE_MEM,
	},
 
	[1] ={
		.start = 0x139D0000,
		.end =  0x139D0000 + 0x14,
		.flags = IORESOURCE_MEM,
	}
};
 
static void beep_device_release(struct device *dev)
{
	printk("beep device release\n");
	return ;
}
 
static struct platform_device hello_device=
{
    .name = "beep",
    .id = -1,
    .dev.release = beep_device_release,
    //.num_resources = ARRAY_SIZE(beep_resource),
    //.resource = beep_resource,
};
 
static int beep_init(void)
{
	printk("======================>beep_device_init");
	return platform_device_register(&hello_device);
}
 
static void beep_exit(void)
{
	printk("======================>beep_device_exit");
	platform_device_unregister(&hello_device);
	return;
}
 
MODULE_LICENSE("GPL");
module_init(beep_init);
module_exit(beep_exit);