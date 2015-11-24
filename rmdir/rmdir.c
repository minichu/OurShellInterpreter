#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int fdout;

	if( argc != 2){
		fprintf(stderr, "usage: rmdir\n");
	}

	fdout = rmdir(argv[1]);
	
	if(fdout == -1){
		perror("remove directory");
		exit(errno);
	}

}
