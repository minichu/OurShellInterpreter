#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE		2000

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
		perror("usage : mysh");
		exit(-1);
	}	

	while(1)
	{

		if((com_tmp = (char *)malloc(strlen(command)+1)) == NULL)
		{
			perror("Can't allocate command's temp string variable");
			continue;
		}
		else
		{
			strcpy(com_tmp, command);
		}

		if(strtok(com_tmp, ";") != NULL)
			for(com_count = 1; strtok(NULL, ";") != NULL; com_count++);

		for(i=1; i<=com_count; i++)
		{
			
			strcpy(com_tmp, command);

			token = strtok(com_tmp, ";");
			for(n = 1; n < i; n++)
				token = strtok(NULL, ";");

			if((buff = (char *)malloc(strlen(token)+1)) == NULL)
			{
				perror("Can't allocate buff string variable");
				continue;
			}
			else
			{
				if((buff_tmp = (char *)malloc(strlen(token)+1)) == NULL)
				{
					perror("Can't allocate buff_tmp string variable");
					continue;
				}
				strcpy(buff, token);
				strcpy(buff_tmp, token);
			}

			if(strtok(buff_tmp, " ") != NULL)
				for(buff_count = 1; strtok(NULL, " ") != NULL; buff_count++);

			if((argvp = (char **)malloc((buff_count+1)*sizeof(char *))) == NULL)
			{
				free(buff);
				free(buff_tmp);
				perror("Can't allocate argvp string variable");
				continue;
			}

			*argvp = strtok(buff, " ");
			for(n = 1; n < buff_count; n++)
			{
				*(argvp + n) = strtok(NULL, " ");
				

			}
			*(argvp + buff_count) = NULL;

			
		}

		
	}

	reset_keypress();
	
	return 0;
}

