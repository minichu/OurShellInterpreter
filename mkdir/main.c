#include <stdio.h>

int main(int argc, char *argv[])
{
	if( argc != 2){
		fprintf(stderr, "usage: mkdir\n");
	}
	mymkdir(argc, argv);
	return;
}
