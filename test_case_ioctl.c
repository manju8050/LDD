#include <stdio.h>   //printf scanf
#include <unistd.h>   // standard symbol constant and types -getpid
#include <fcntl.h>   // it is use for file control operation //open

#include <stdlib.h>   //for exit function
#include <sys/types.h>  //open close
#include<sys/ioctl.h>   // ioctl
#include <errno.h>
extern int errno;

#define MY_MAGIC 'a'
#define WR_VALUE _IOW(MY_MAGIC,'a',int32_t*)
#define RD_VALUE _IOR(MY_MAGIC,'b',int32_t*)
#define MY_IOCTL_MAX_CMD 2

int main()
{
	int fd;
    	int32_t value, number;	
	
	printf("[%d] - Opening device my_cdrv\n", getpid() );
	
	fd = open( "/dev/my_Ioctl_driver", O_RDWR );
	
	if( fd < 0 ) 
	{
		int er = errno;
		printf("%d\n",er);
		printf("\n\nDevice could not be opened\n\n");
		perror("Error\n");
		
		return 1;
	}
	printf("Device opened with ID [%d]\n", fd);
	
	   
	printf("Enter the Value to send\n");
	scanf("%d",&number);
	printf("Writing Value to Driver\n");
	
	int wr=ioctl(fd, WR_VALUE, (int32_t*) &number);
	if(wr<0)
	{
		int er = errno;
		printf("%d\n",er);
		perror("Error\n");
	}
	


	printf("Reading Value from Driver\n");
	int rd=ioctl(fd, RD_VALUE, (int32_t*) &value);
	if(rd<0)
	{
		int er = errno;
		printf("%d\n",er);
		perror("Error\n");
	
	}
	
	printf("Value is %d\n", value);

	printf("Closing Driver\n");
	
	close(fd);
	
	
	
	exit(0);
}

----------------------------------------------------------------------
---------------------------------------------------------------------

#define	EPERM		 1	/* Operation not permitted */
#define	ENOENT		 2	/* No such file or directory */
#define	ESRCH		 3	/* No such process */
#define	EINTR		 4	/* Interrupted system call */
#define	EIO		 5	/* I/O error */
#define	ENXIO		 6	/* No such device or address */
#define	E2BIG		 7	/* Argument list too long */
#define	ENOEXEC		 8	/* Exec format error */
#define	EBADF		 9	/* Bad file number */
#define	ECHILD		10	/* No child processes */
#define	EAGAIN		11	/* Try again */
#define	ENOMEM		12	/* Out of memory */
#define	EACCES		13	/* Permission denied */
#define	EFAULT		14	/* Bad address */
#define	ENOTBLK		15	/* Block device required */
#define	EBUSY		16	/* Device or resource busy */
#define	EEXIST		17	/* File exists */
#define	EXDEV		18	/* Cross-device link */
#define	ENODEV		19	/* No such device */
#define	ENOTDIR		20	/* Not a directory */
#define	EISDIR		21	/* Is a directory */
#define	EINVAL		22	/* Invalid argument */
#define	ENFILE		23	/* File table overflow */
#define	EMFILE		24	/* Too many open files */
#define	ENOTTY		25	/* Not a typewriter */
#define	ETXTBSY		26	/* Text file busy */
#define	EFBIG		27	/* File too large */
#define	ENOSPC		28	/* No space left on device */
#define	ESPIPE		29	/* Illegal seek */
#define	EROFS		30	/* Read-only file system */
#define	EMLINK		31	/* Too many links */
#define	EPIPE		32	/* Broken pipe */
#define	EDOM		33	/* Math argument out of domain of func */
#define	ERANGE		34	/* Math result not representable */
 

------------------------------------------------------------------------------
------------------------------------------------------------------------------