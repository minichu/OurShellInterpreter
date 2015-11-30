#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define		BUFSZ 4096


mymkdir(int argc, char *argv[])
{
	int fdout;
	char buf[BUFSZ];

	if( argc != 2){
		fprintf(stderr, "usage: mkdir\n");
	}

	getcwd(buf, BUFSZ);
	fdout = mkdir(argv[1], 0777);
	
	if(fdout == -1){
		perror("make directory");
		exit(errno);
	}

}
