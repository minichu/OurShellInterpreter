#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	if(argc!=3)
	{
		
		exit(1);
	}
	if(open(argv[1],O_RDWR) < 0)
	{
		
		exit(1);
	}
	if(link(argv[1],argv[2])<0)
		printf("1");
	else
		printf("2");
}
