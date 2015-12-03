#include "mypwd.h"

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
