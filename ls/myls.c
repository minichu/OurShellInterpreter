#include "myls.h"

int main(int argc, char* argv[])
{
	DIR *dirp;
	struct dirent *direntp;
	struct stat statbuf;
	struct passwd *user_information;
	struct group *group_information;
	int i;
	
	if(argc > 2){
		printf("error : ls error");
		exit(0);
	}

	if((dirp=opendir(".")) == NULL){
		printf("opendir error\n");
		exit(0);
	}

	switch(argc){
	case 1:
		while( (direntp = readdir(dirp)) != NULL){
			if(strcmp(direntp->d_name,".") == 0 || strcmp(direntp->d_name,"..") == 0)
				continue;
			printf("%2s\t",direntp->d_name);
		}
		break;
	}

	putchar('\n');
	closedir(dirp);
	
	exit(0);
}

