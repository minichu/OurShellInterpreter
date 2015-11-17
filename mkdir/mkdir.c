#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define		BUFSZ 4096

int main(int argc, char *argv[])
{
	int fdout;
	char buf[BUFSZ];
	struct stat st;

	if( argc != 2){
		fprintf(stderr, "usage: mkdir\n");
	}

	fdout = open(argv[1], O_CREAT | O_TRUNC | O_DIRECTORY, S_IFDIR);
	
	if(fdout == -1){
		perror("open source");
		exit(errno);
	}

}
