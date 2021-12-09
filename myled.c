#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/uaccess.h>
#include<linux/io.h>
#include <linux/delay.h>
MODULE_AUTHOR("Ryuichi Ueda and Hayato Nomura");
MODULE_DESCRIPTION("driver for LED control");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");
static dev_t dev;
static struct cdev cdv;
static struct class *cls = NULL;
static volatile u32 *gpio_base = NULL;
static int gpio[8] = {17, 25,9, 16,  21,12,27,22};

static void LED(int x){
	switch(x){
		case 0:	
			gpio_base[7] = 1 << gpio[0];		
			gpio_base[7] = 1 << gpio[1];		
			gpio_base[7] = 1 << gpio[2];		
			gpio_base[7] = 1 << gpio[3];		
			gpio_base[7] = 1 << gpio[4];		
			gpio_base[7] = 1 << gpio[5];		
			gpio_base[10] = 1 << gpio[6];
			break;
		case 1:	
			gpio_base[10] = 1 << gpio[0];		
			gpio_base[7] = 1 << gpio[1];		
			gpio_base[7] = 1 << gpio[2];		
			gpio_base[10] = 1 << gpio[3];		
			gpio_base[10] = 1 << gpio[4];		
			gpio_base[10] = 1 << gpio[5];		
			gpio_base[10] = 1 << gpio[6];
			break;

		case 2:	
			gpio_base[7] = 1 << gpio[0];		
			gpio_base[7] = 1 << gpio[1];		
			gpio_base[10] = 1 << gpio[2];		
			gpio_base[7] = 1 << gpio[3];		
			gpio_base[7] = 1 << gpio[4];		
			gpio_base[10] = 1 << gpio[5];		
			gpio_base[7] = 1 << gpio[6];
			break;
		case 3:	
			gpio_base[7] = 1 << gpio[0];		
			gpio_base[7] = 1 << gpio[1];		
			gpio_base[7] = 1 << gpio[2];		
			gpio_base[7] = 1 << gpio[3];		
			gpio_base[10] = 1 << gpio[4];		
			gpio_base[10] = 1 << gpio[5];		
			gpio_base[7] = 1 << gpio[6];
			break;
		case 4:	
			gpio_base[10] = 1 << gpio[0];		
			gpio_base[7] = 1 << gpio[1];		
			gpio_base[7] = 1 << gpio[2];		
			gpio_base[10] = 1 << gpio[3];		
			gpio_base[10] = 1 << gpio[4];		
			gpio_base[7] = 1 << gpio[5];		
			gpio_base[7] = 1 << gpio[6];
			break;
		case 5:	
			gpio_base[7] = 1 << gpio[0];		
			gpio_base[10] = 1 << gpio[1];		
			gpio_base[7] = 1 << gpio[2];		
			gpio_base[7] = 1 << gpio[3];		
			gpio_base[10] = 1 << gpio[4];		
			gpio_base[7] = 1 << gpio[5];		
			gpio_base[7] = 1 << gpio[6];
			break;
		case 6:	
			gpio_base[7] = 1 << gpio[0];		
			gpio_base[10] = 1 << gpio[1];		
			gpio_base[7] = 1 << gpio[2];		
			gpio_base[7] = 1 << gpio[3];		
			gpio_base[7] = 1 << gpio[4];		
			gpio_base[7] = 1 << gpio[5];		
			gpio_base[7] = 1 << gpio[6];
			break;
		case 7:	
			gpio_base[7] = 1 << gpio[0];		
			gpio_base[7] = 1 << gpio[1];		
			gpio_base[7] = 1 << gpio[2];		
			gpio_base[10] = 1 << gpio[3];		
			gpio_base[10] = 1 << gpio[4];		
			gpio_base[7] = 1 << gpio[5];		
			gpio_base[10] = 1 << gpio[6];
			break;
		case 8:	
			gpio_base[7] = 1 << gpio[0];		
			gpio_base[7] = 1 << gpio[1];		
			gpio_base[7] = 1 << gpio[2];		
			gpio_base[7] = 1 << gpio[3];		
			gpio_base[7] = 1 << gpio[4];		
			gpio_base[7] = 1 << gpio[5];		
			gpio_base[7] = 1 << gpio[6];
			break;
		case 9:	
			gpio_base[7] = 1 << gpio[0];		
			gpio_base[7] = 1 << gpio[1];		
			gpio_base[7] = 1 << gpio[2];		
			gpio_base[7] = 1 << gpio[3];		
			gpio_base[10] = 1 << gpio[4];		
			gpio_base[7] = 1 << gpio[5];		
			gpio_base[7] = 1 << gpio[6];
			break;
		case 10:	
			gpio_base[10] = 1 << gpio[0];		
			gpio_base[10] = 1 << gpio[1];		
			gpio_base[10] = 1 << gpio[2];		
			gpio_base[10] = 1 << gpio[3];		
			gpio_base[10] = 1 << gpio[4];		
			gpio_base[10] = 1 << gpio[5];		
			gpio_base[10] = 1 << gpio[6];
			break;
	}
}
static void Hello(void){

		gpio_base[10] = 1 << gpio[0];		
		gpio_base[7] = 1 << gpio[1];		
		gpio_base[7] = 1 << gpio[2];		
		gpio_base[10] = 1 << gpio[3];		
		gpio_base[7] = 1 << gpio[4];		
		gpio_base[7] = 1 << gpio[5];		
		gpio_base[7] = 1 << gpio[6];
		msleep(700);
		LED(10);
		msleep(200);
		gpio_base[7] = 1 << gpio[0];		
		gpio_base[10] = 1 << gpio[1];		
		gpio_base[10] = 1 << gpio[2];		
		gpio_base[7] = 1 << gpio[3];		
		gpio_base[7] = 1 << gpio[4];		
		gpio_base[7] = 1 << gpio[5];		
		gpio_base[7] = 1 << gpio[6];
		msleep(700);
		LED(10);
		msleep(200);
		gpio_base[10] = 1 << gpio[0];		
		gpio_base[10] = 1 << gpio[1];		
		gpio_base[10] = 1 << gpio[2];		
		gpio_base[7] = 1 << gpio[3];		
		gpio_base[7] = 1 << gpio[4];		
		gpio_base[7] = 1 << gpio[5];		
		gpio_base[10] = 1 << gpio[6];
		msleep(700);
		LED(10);
		msleep(200);
		gpio_base[10] = 1 << gpio[0];		
		gpio_base[10] = 1 << gpio[1];		
		gpio_base[10] = 1 << gpio[2];		
		gpio_base[7] = 1 << gpio[3];		
		gpio_base[7] = 1 << gpio[4];		
		gpio_base[7] = 1 << gpio[5];		
		gpio_base[10] = 1 << gpio[6];
		msleep(700);
		LED(10);
		msleep(200);
		gpio_base[7] = 1 << gpio[0];		
		gpio_base[7] = 1 << gpio[1];		
		gpio_base[7] = 1 << gpio[2];		
		gpio_base[7] = 1 << gpio[3];		
		gpio_base[7] = 1 << gpio[4];		
		gpio_base[7] = 1 << gpio[5];		
		gpio_base[10] = 1 << gpio[6];
		msleep(700);
		LED(10);
		msleep(200);
		gpio_base[10] = 1 << gpio[0];		
		gpio_base[10] = 1 << gpio[1];		
		gpio_base[10] = 1 << gpio[2];		
		gpio_base[10] = 1 << gpio[3];		
		gpio_base[10] = 1 << gpio[4];		
		gpio_base[10] = 1 << gpio[5];		
		gpio_base[10] = 1 << gpio[6];
		msleep(700);		

}

static ssize_t led_write(struct file* flip, const char* buf, size_t count, loff_t* pos){
	char c;
	int i,j;
	int cu=0;
	if(copy_from_user(&c,buf,sizeof(char)))
		return -EFAULT;
//	printk(KERN_INFO"receive %c\n",c);
	if(c == '0') Hello();
	else if(c == '1') cu = 1;
	else if(c == '2') cu = 2;
	else if(c == '3') cu = 3;
	else if(c == '4') cu = 4;
	else if(c == '5') cu = 5;
	else if(c == '7') cu = 7;
	else if(c == '8') cu = 8;
	else if(c == '9') cu = 9;
	else if(c != '0') cu = 0;
		
		for(i=cu;i>=0;i--){
			msleep(1000);
			 LED(i);		
		}
		LED(10);
		for( j=0;j<=10;j++){

			gpio_base[7] = 1 << 22;
			msleep(100);
			gpio_base[10] = 1 << 22;
			msleep(100);	
		}	
	
	return 1;
}

static struct file_operations led_fops = {
	.owner = THIS_MODULE,
	.write = led_write,
};
static int __init init_mod(void)
{
	int retval;
	int i;
	retval = alloc_chrdev_region(&dev, 0, 1, "myled");
	if(retval < 0){
		printk(KERN_ERR" alloc_chrdev_region failed.\n");
		return retval;
	}
	printk(KERN_INFO"%s is loaded.major:%d\n",__FILE__,MAJOR(dev));

	cdev_init(&cdv, &led_fops);
	retval = cdev_add(&cdv, dev, 1);
	if(retval < 0){
		printk(KERN_ERR" cdev_add failed. major:%d, minor:%d\n",MAJOR(dev),MINOR(dev));
		return retval;

	}
	cls= class_create(THIS_MODULE,"myled");
	if(IS_ERR(cls)){
		printk(KERN_ERR"class_create failed");
		return PTR_ERR(cls);
	}
	device_create(cls, NULL, dev, NULL, "myled%d",MINOR(dev));
	gpio_base = ioremap_nocache(0xfe200000, 0xA0);
	for(i = 0; i < 8; i++){
		const u32 led =gpio[i];
		const u32 index = led/10;
		const u32 shift = (led%10)*3;
		const u32 mask = ~(0x7 << shift);
		gpio_base[index] = (gpio_base[index] & mask) | (0x1 << shift);
 	}
	return 0;
}
static void __exit cleanup_mod(void)
{
	cdev_del(&cdv);
	device_destroy(cls,dev);
	class_destroy(cls);
	unregister_chrdev_region(dev,1);
	printk(KERN_INFO"%s is unloaded major:%d\n",__FILE__,MAJOR(dev));
}



module_init(init_mod);
module_exit(cleanup_mod);

