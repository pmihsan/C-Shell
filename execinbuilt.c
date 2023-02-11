#include "main.h"

void execbuiltin(char **argv){
	if(strncmp(argv[0], "cd", 2) == 0){
		exec_cd(argv);
	}
	else if(strncmp(argv[0], "help", 4) == 0){
		exec_help(argv);
	}	
	else if(strncmp(argv[0], "clear", 5) == 0){
		exec_clear(argv);
	}	
	else if(strncmp(argv[0], "alias", 5) == 0){
		//create_alias(argv);
	}	
}

void exec_cd(char **argv){
	if(argv[1] != 0 && argv[2] != 0){
		perror("shell: cd: too many arguments");
	}

	if(argv[1] == 0 || strcmp(argv[1], "~") == 0){
		if(chdir(getenv("HOME")) != 0){
			perror("shell: cd: HOME directory not set");
		}	
	}
	else if(strcmp(argv[1], "-") == 0){
		if(chdir(getenv("OLDPWD")) != 0){
			perror("shell: cd: OLDPWD not set");
		}	
	}
	else if(chdir(argv[1]) != 0){
		perror("shell: cd: No such file or directory");
	}
}

void exec_help(char **argv){
	printf("These shell commands are defined internally.\n");
	/*if(argv[1] != 0){
		if(execve(argv[0], "--help", NULL) == -1){
			perror("shell: help: command execution error");
		};
		return;
	}
	if(execve(argv[0], NULL, NULL) == -1){
		perror("shell: help: command execution error");
	};*/
}

void exec_clear(char **argv){
	system("tput clear");
	/*char *cmd = get_location(argv[0]);
	char *term = getenv("TERM");
	
	if(execve(cmd, NULL, NULL) == -1){
		perror("shell: clear: command execution error");
	};*/
}

void exec_alias(char **argv){	
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
