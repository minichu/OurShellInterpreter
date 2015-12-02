#include "mycd.h"

#define		BUFSZ 4092

void main(int argc, char *argv[]){
	char buf[BUFSZ];

	if(argc != 2){
		printf("ERROR : change directory\n");
		exit(0);
	}

	if(chdir(argv[1]) < 0){
	printf("Fail : change directory\n");
		exit(0);
	}

	chdir(argv[1]);
}
