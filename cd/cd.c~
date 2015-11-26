#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define		BUFSZ 4092

int main(int argc, char *argv[]){
	char buf[BUFSZ];

	if(argc != 2){
		printf("ERROR : change directory\n");
		exit(0);
	}

	printf("%s\n\n\n",argv[1]);

	chdir((const char *)argv[1]);

	if(chdir(argv[1]) < 0){
		printf("Fail : change directory\n");
		exit(0);
	}

	chdir(argv[1]);
}
