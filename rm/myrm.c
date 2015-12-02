#include "myrm.h"

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("ERROR: format (./myrm<filename>).\n");
		exit(1);
	}

	if(open(argv[1],O_RDWR)<0)
	{
		printf("There is no %s file.\n",argv[1]);
	}
	if(unlink(argv[1])<0)
		printf("ERROR: Unlink Failed.\n");
	else
		printf("Delete success.\n");
}
