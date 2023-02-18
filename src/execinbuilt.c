#include "main.h"

void execbuiltin(char **argv){
	if(strncmp(argv[0], "cd", 2) == 0 && strlen(argv[0]) == 2){
		exec_cd(argv);
	}
	else if(strncmp(argv[0], "help", 4) == 0 && strlen(argv[0]) == 4){
		exec_help();
	}	
	else if(strncmp(argv[0], "clear", 5) == 0 && strlen(argv[0]) == 5){
		exec_clear();
	}	
	else if(strncmp(argv[0], "shell", 5) == 0 && strlen(argv[0]) == 5){
		shell_info(argv);
	}	
	else if(strncmp(argv[0], "alias", 5) == 0 && strlen(argv[0]) == 5){
		create_alias(argv);
	}	
	else if(strncmp(argv[0], "unalias", 7) == 0 && strlen(argv[0]) == 7){
		remove_alias(argv);
	}	
	else if(strncmp(argv[0], "history", 7) == 0 && strlen(argv[0]) == 7){
		exec_history(argv);
	}
	else{
		printf("shell: %s: command not found\n",argv[0]);
	}	
}

void exec_cd(char **argv){
	char cwd[61];
	if(getcwd(cwd, 60) == NULL){
        	perror("shell: can not get current workdir");
		return;
        }	
	
	else if(argv[1] != 0 && argv[2] != 0){
		perror("shell: cd: too many arguments");
	}
	
	else if((argv[1] == NULL) || (strcmp(argv[1], "~") == 0)){
		char homedir[25];
		sprintf(homedir, "/home/%s", getenv("USER"));
		printf("%s\n",homedir);
		if(chdir(homedir) != 0){
			perror("shell: cd: HOME directory not set");
		}
	}
	
	else if(argv[1] != 0 && strcmp(argv[1], "-") == 0){
		if(chdir(getenv("OLDPWD")) != 0){
			perror("shell: cd: OLDPWD not set");
		}	
	}
	
	else if(chdir(argv[1]) != 0){
		perror("shell: cd: No such file or directory");
	}
	setenv("OLDPWD",cwd,1);
}

void exec_help(){
	printf("These shell commands are defined internally.\n");
}

void exec_clear(){
	system("tput clear");
}

void exec_alias(char **argv){	
	if(isBuiltIn(argv[0])){
		execbuiltin(argv);
		return;
	}
	
	char *command = get_location(argv[0]);
	pid_t pid = fork();
	if(pid == 0){	
		if(execve(command, argv, NULL) == -1){
			perror("shell: alias: command execution error");
		};
		exit(0);
	}
	else{
		wait(NULL);
	}
}

void create_alias(char **argv){
	if(argv[1] == 0){
		print_alias();
	}
	else if(argv[1] != 0){
		add_alias(argv);
	}
	else{
		perror("shell: alias: command execution error");
	}
}

void remove_alias(char **argv){
	if(argv[1] == 0){
		print_alias();
	}
	else if(argv[1] != NULL){
		if(!del_alias(argv)){
			printf("shell: unalias: alias %s not found\n", argv[1]);
		}
	}
	else{
		perror("shell: unalias: command execution error");
	}
}

void exec_history(char **argv){
	if(argv[1] != 0){
		perror("shell: history: too may arguments");
		return;
	}
	display_history();
}

void shell_info(char **argv){
	if(argv[1] == 0){
		printf("Shell - command line utility\n");
	}
	else if(strncmp(argv[1],"--help",6) == 0 && strlen(argv[1]) == 6){
		printf("Shell - cmd tool similar to bash, sh, csh with minimal features\n");
		printf("Use Builtins such as\n");
		printf("\tcd - change directory\n");
		printf("\tclear - to clear the console\n");
		printf("\talias - to set a shortcut for commands\n");
		printf("\tunalias - to remove the shortcut for commands\n");
		printf("\thistory - to view th history of commands used\n");
		printf("\thelp - builtin help manual for shell\n");
	}
	else if(strncmp(argv[1],"--version",9) == 0 && strlen(argv[1]) == 9){
		printf("Shell version v1.0.1\n");
	}
	else{
		printf("Invalid arguments use --help to know more\n");
	}
}
