#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

# define	BUFSZ 4096

int main(int argc, char *argv[])
{
	DIR *dp;

	int fdin, fdout;
	char buf[BUFSZ];
	int nb;
	
	struct dirent *dt;
	struct stat st;
	

	if( argc != 3){
		fprintf(stderr, "usage: mycp source dest\n");
		exit(0);
	}

	fdin = open(argv[1], O_RDONLY);
	if(fdin == -1){
		perror("open source");
		exit(errno);
	}

	fstat(fdin, &st);
	
	fdout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, st.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
	if(fdout == -1){
		perror("open source");
		exit(errno);
	}

	while( (nb = read(fdin, buf, BUFSZ)) >0 ){
		write(fdout, buf, nb);
	}

	
	close(fdin);
	close(fdout);
	
	return 0;
}
