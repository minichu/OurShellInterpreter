int main(int argc, char *argv[])
{
	char command[MAXSIZE] = {0};
	char *com_temp;
	char *buff;
	char *buff_tmp;
	char **argvp;
	char *token;
	char c;

	int status;
	int com_count = 1;
	int buff_count = 0;
	int i=0, n=0;

	memset(abspath, 0, sizeof(abspath));
	background = 0;
	work_num =1;

	if(argc != 1)
	{
		perror("usage : mysh");
		exit(-1);
	}

	userinfo = getpwuid(getuid());
	
	getcwd(abspath, MAXSIZE);

	memset(shell, 0, sizeof(shell));

	init_list();

	sig_init_list();
	
	signal(SIGINT, SIG_IGN);

	set_keypress();
}
