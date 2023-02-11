#include "main.h"

void execmd(char **argv){
	char *command = NULL;
	char *actual_command = NULL;

	if(argv){

		command = argv[0];
		if(isBuiltIn(command)){
			execbuiltin(argv);
			return;
		}
		if(isAlias(command)){
			return;
		}
		actual_command = get_location(command);
		
		if(actual_command == NULL){
			printf("shell: %s: command not found\n",argv[0]);
			return;
		}
		
		pid_t pid = fork();
		if(pid == 0){
			if(execve(actual_command, argv, NULL) == -1){
				perror("shell: command execution error");
			};
			exit(0);
		}
		else{
			wait(NULL);
		}
	}
}
