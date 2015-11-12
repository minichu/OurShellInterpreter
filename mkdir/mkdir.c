#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int fdin, fdout;
	char buf[BUFSZ];
	int nb;

	if( argc != 3){
		fprintf(stderr, "usage: mkdir\n");
	}

	fdin = open(argv[1], O_RDONLY);
	if(fdin == -1){
		perror("open source");
		exit(errno);
	}

	fdout
