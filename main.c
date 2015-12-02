#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAXSIZE		2000



int getcommand(char *command)
{
	int n=0, space_chk=0;
	char path[MAXSIZE] = {0};
	char c;
	
	fflush(NULL);

	while((c = fgetc(stdin)))
	{
		if(c == 10)
		{
			fputc('\n', stdout);
			break;
		}

		if(c == 4)
		{
			fputc('\n', stdout);
			return 0;
		}
		
		if((c <= 26) && (c != 8))
			break;

			
		switch(c)
		{
			case 8:
				if(n == 0)
					break;

				fputc('\b', stdout);
				fputc(' ', stdout);
				fputc('\b', stdout);
				command[--n] = (char)0;
				break;
		
			default:
				printf("input: %s",&c);
				//fputc(c, stdout);
				command[n++] = (char)c;
				break;
		}
	}
	command[n] = '\0';

	if(strlen(command) == 0)
		return 0;
	
	for(n=0; n<strlen(command); n++)
		if(command[n] != ' ' && command[n] != '\t')
			return 1;
	
	return 0;
}


int main(int argc, char *argv[])
{

	char	command[MAXSIZE] = {0};	
	char	*com_tmp;		
	char	*buff;			
	char	*buff_tmp;			
	char 	**argvp;			
	char	*token;			
	char	c;			

	int	status;			
	int	com_count = 1;		
	int	buff_count = 0;		
	int	i=0, n=0;			

	if(argc != 1)
	{
		perror("usage : Our Shell Interpreter");
		exit(errno);
	}	

	while(1)
	{
		if(getcommand(command)==0)
			continue;
	}
	return 0;
}

