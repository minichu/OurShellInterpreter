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
	nowhistory = histail;
	
	fflush(NULL);

	// 프롬프트를 띄우고 명령 입력을 대기
	curpath = (char *)getenv("PWD");
	printf("[%s@%s]$ ", userinfo->pw_name, curpath);
	sprintf(path, "[%s@%s]$ ", userinfo->pw_name, curpath);

	// 명령 입력을 받음
	while((c = fgetc(stdin)))
	{
		// enter key를 입력받으면 입력 종료
		if(c == 10)
		{
			fputc('\n', stdout);
			break;
		}

		// Ctrl+D를 입력받으면 입력 종료
		if(c == 4)
		{
			fputc('\n', stdout);
			return 0;
		}
		
		// backspace key를 제외한 입력 무시
		if((c <= 26) && (c != 8))
			break;
			
		switch(c)
		{
			// backspace key를 입력받을 때 처리
			case 8:
				if(n == 0)
					break;

				fputc('\b', stdout);
				fputc(' ', stdout);
				fputc('\b', stdout);
				command[--n] = (char)0;
				break;
	
			// ^[ (esc) 기호이면서
			case 27:
				// [ 기호가 아니면 switch문 탈출
				if((c = fgetc(stdin)) != 91)
					break;

				// [ 기호가 들어왔다면
				switch(fgetc(stdin))
				{
					// ^[[A 기호, 즉 key가 up일 때 history 내용 출력
					case 65:
						nowhistory = nowhistory->prev;
						if(nowhistory != hishead)
						{
							fprintf(stdout, "\r%80s", " ");
							fprintf(stdout, "\r%s%s", path,
							 nowhistory->value);
							strcpy(command,
							 nowhistory->value);
							n = strlen(command);
						}
						else
						{
							nowhistory = hishead->next;
						}
						break;
					// ^[[B 기호, 즉 key가 down일 때 history 내용 출력
					case 66:
						nowhistory = nowhistory->next;
						if(nowhistory != histail)
						{
							fprintf(stdout, "\r%80s", " ");
							fprintf(stdout, "\r%s%s", path,
							 nowhistory->value);
							strcpy(command,
							 nowhistory->value);
							n = strlen(command);
						}
						else
						{
							fprintf(stdout, "\r%80s", " ");
							fprintf(stdout, "\r%s", path);
							n = 0;
						}
						break;
					// ^[[C 기호, 즉 key가 right일 때 아무 처리 안함
					case 67:
						break;
					// ^[[D 기호, 즉 key가 left일 때 아무 처리 안함
					case 68:
						break;
				}
				break;
		
			// 그 외 일반적인 문자이면
			default:
				fputc(c, stdout);
				command[n++] = (char)c;
				break;
		}
	}
	command[n] = '\0';

	// 아무런 입력이 없었으면 프롬프트 다시 띄움
	if(strlen(command) == 0)
		return 0;
	
	// 공백만 포함된 문자열이면 프롬프트 다시 띄움
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

