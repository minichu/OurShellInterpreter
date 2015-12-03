#include "myrmdir.h"

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
