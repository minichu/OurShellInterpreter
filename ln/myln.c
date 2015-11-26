#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	if(argc!=3)
	{
		printf("ERROR: format(./myln <source> <destination>).\n");
		exit(1);
	}
	if(open(argv[1],O_RDWR) < 0)
	{
		printf("There is no %s file.\n",argv[1]);
		exit(1);
	}
	if(link(argv[1],argv[2])<0)
		printf("link error.\n");
	else
		printf("link success!!\n");
}
