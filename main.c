#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	char	command[MAXSIZE] = {0};	// 인자로 받은 명령어들
	char	*com_tmp;		// command 저장하는 임시 문자열
	char	*buff;			// 여러 명령어 중 하나를 저장
	char	*buff_tmp;			// buff를 저장하는 임시 문자열
	char 	**argvp;			// 명령어를 분리하여 저장할 포인터 배열
	char	*token;			// 토큰
	char	c;			// 입력받은 문자 하나

	int	status;			// process status
	int	com_count = 1;		// 명령어 개수
	int	buff_count = 0;		// 명령어가 몇 개의 인자로 이루어져 있는지 저장
	int	i=0, n=0;			// 임시 변수

	memset(abspath, 0, sizeof(abspath));	// mysh가 위치한 절대 경로
	background = 0;			// 백그라운드인지 여부를 체크
	work_num = 1;			// 작업 번호
	if(argc != 1)
	{
		perror("usage : mysh");
		exit(-1);
	}	

	while(1)
	{
		// 프롬프트 띄우고 명령 입력 받음
		if(getcommand(command)==0)
			continue;

		// 입력받은 명령어 history에 저장
		add_list(command);
		
		// command를 임시 문자열 com_tmp에 저장, 에러시 다시 프롬프트 띄움
		if((com_tmp = (char *)malloc(strlen(command)+1)) == NULL)
		{
			perror("Can't allocate command's temp string variable");
			continue;
		}
		else
		{
			strcpy(com_tmp, command);
		}
		
		// command에 저장된 명령어 개수 세기(com_tmp를 이용)
		if(strtok(com_tmp, ";") != NULL)
			for(com_count = 1; strtok(NULL, ";") != NULL; com_count++);
		
		
		
		/////////////////////////////////////////////////////////////////////
		//
		// [ command의 개수만큼 수행 ]
		// 
		for(i=1; i<=com_count; i++)
		{
			
			/////////////////////////////////////////////////////////////////////
			//
			//  각 command를 공백으로 다시 구분하여 argvp 이중 포인터 배열에 저장
			//
			// com_tmp를 다시 사용하기 위하여 command를 다시 저장해 둠
			strcpy(com_tmp, command);
			
			// i 위치에 해당하는 명령을 token으로 분리
			token = strtok(com_tmp, ";");
			for(n = 1; n < i; n++)
				token = strtok(NULL, ";");
				
			// 분리한 token을 buff와 buff_tmp에 저장해 둠
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
			
			// buff_tmp에 저장된 토큰의 수를 셈
			if(strtok(buff_tmp, " ") != NULL)
				for(buff_count = 1; strtok(NULL, " ") != NULL; buff_count++);
			
			// 각 토큰을 가리키는 포인터들이 들어갈 인자 배열 만듬
			if((argvp = (char **)malloc((buff_count+1)*sizeof(char *))) == NULL)
			{
				free(buff);
				free(buff_tmp);
				perror("Can't allocate argvp string variable");
				continue;
			}
			
			// 토큰을 가리키는 포인터들을 인자 배열에 넣음
			*argvp = strtok(buff, " ");
			for(n = 1; n < buff_count; n++)
			{
				*(argvp + n) = strtok(NULL, " ");
				
				// 인자 중에 백그라운드 표시가 있으면 체크하고 &는
				// argvp에 포함시키지 않음
				if(strcmp(*(argvp +n), "&") == 0)
				{
					background = 1;
					buff_count -= 1;
				}
			}
			*(argvp + buff_count) = NULL;
			//
			//
			/////////////////////////////////////////////////////////////////////
			
			
			/////////////////////////////////////////////////////////////////////
			//
			// [ 쉘 / 환경 변수 치환 ]
			//
			// argvp(인자)에 환경변수 또는 alias된 인자가 포함되어 있는지
			// 검사한 뒤 원래 대로 바꾸어줌
			convargvp(argvp);
			//
			//
			/////////////////////////////////////////////////////////////////////


			/////////////////////////////////////////////////////////////////////
			//
			// [ 쉘 내부 명령어 처리 ]
			//
			// 각 명령어에 따른 실행
			// 명령어를 실행 했으면 continue하여 다음 command받고
			// 내부 명령어가 아니였다면 다음 처리를 함
			// 단 리다이렉션 또는 파이프일 경우엔 fork후 사용해야 하므로 건너뜀
			if(!ispipe(argvp))
				if(incmdproc(argvp))
					continue;

			if(forkproc(argvp) == 0)
				continue;
			else
				break;

			
		}

		
	}

	reset_keypress();
	
	return 0;
}

