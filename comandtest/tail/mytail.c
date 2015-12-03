
#include "mytail.h"

#define LINE_CHECK_BYTE_NUM 512

void main(int argc, char *argv[])
{
	FILE *fp = NULL;//make tail
	char c;
	long leng=1;
	char One_Line[512];

	if((fp = fopen(argv[1], "rb")) == NULL)
		fprintf(stderr, "LOG_PATH Open Error\n");

	while(leng++ < LINE_CHECK_BYTE_NUM){
		fseek(fp, -(leng), SEEK_END);
		c = fgetc(fp);

		if(c == '\n'){
			fgets(One_Line, leng, fp);
			printf("One_Line : %s\n", One_Line);
			break;
		}
	}
	//return a;
}
