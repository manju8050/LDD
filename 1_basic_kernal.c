#include<linux/module.h>    /* Definition of MODULE_* constants */
#include<linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_LICENSE("GPL v2");
MODULE_LICENSE("Dual BSD/GPL");

MODULE_AUTHOR("manju");
MODULE_DESCRIPTION("a sample driver");
MODULE_VERSION("1:0.0");

int myValue, arr_myValue[4];
char *myName;
int cb_myValue = 0;

module_param(myValue,int,S_IRUSR|S_IWUSR);
module_param(myName,charp,S_IRUSR|S_IWUSR);
module_param_array(arr_myValue,int,NULL,S_IRUSR|S_IWUSR);
static int __init hello_world_init(void)  
{

	printk(KERN_INFO"hello world started");
	int i;
	printk(KERN_INFO"myValue=%d\n",myValue);
	printk(KERN_INFO"myName=%s\n",myName);
	for(i=0;i<(sizeof arr_myValue/sizeof (int));i++)
	{
		printk(KERN_INFO"Arr_value[%d]=%d\n",i,arr_myValue[i]);
	}
	
	return 0;
	
}


module_init(hello_world_init);



void __exit hello_world_exit(void)  
{

	printk(KERN_INFO"hello world exit");
	
	
}

module_exit(hello_world_exit)

