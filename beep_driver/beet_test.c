#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
 
main()
{
	int fd,i,lednum;
 
	fd = open("/dev/beep_driver",O_RDWR);
	if(fd<0)
	{
		perror("open /dev/beep_driver fail \n");
		return ;
	}
	
	sleep(10);
	close(fd);
}