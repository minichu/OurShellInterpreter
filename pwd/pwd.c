#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define		BUFSZ 4096

int main(void)
{
	int fdout;
	char buf[BUFSZ];
	struct stat st;

	getcwd(buf, BUFSZ);
	printf("%s\n",buf);
	
	if(fdout == -1){
		perror("make directory");
		exit(errno);
	}

}
