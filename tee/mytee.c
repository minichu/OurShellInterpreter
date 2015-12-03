#include "mytee.h"

#define		BUFSZ 4096

int main(int argc, char *argv[])
{
	int fd;
	char buf[BUFSZ];
	int nb;

	if(argc != 2){
		fprintf(stderr, "usage: mytee source dest\n");
		exit(0);
	}
	
	fd = open(argv[1], O_WRONLY | O_CREAT, 0666);
	
	if(fd == -1){
		perror("open source");
		exit(errno);
	}

	while((nb = read(0,buf,BUFSZ)) >0){
		write(fd, buf, nb);
		write(1, buf, nb);
	}
	close(fd);
	return 0;

}
