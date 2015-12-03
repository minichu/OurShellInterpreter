#include "mymv.h"

int main(int argc, char *argv[]) {
	int fd_des, fd_src;
	char buf;

	if(argc != 3){
		printf("error : Invalid format.\n");
	}

	if((fd_src = open(argv[1], O_RDONLY)) < 0) {
		printf("error : open fail");
		exit(0);
	}

	rename(argv[1], argv[2]);
	return 0;
}
