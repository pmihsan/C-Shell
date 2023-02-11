#include "main.h"

typedef struct aliases {
	char *alias_name;
	char *cmd_name;
} alias;

//ALIAS
alias shell_aliases[] = {
	{"l", "ls --color=auto -l"},
	{"ll", "ls -l -h"},
	{NULL, NULL},
};

bool isAlias(char *CMD){
	int c = 0, i;
	char **args;
	while(shell_aliases[c].alias_name != NULL){
		if(strcmp(CMD, shell_aliases[c].alias_name) == 0){
			int len = strlen(shell_aliases[c].cmd_name);
			char *cmd = malloc(sizeof(char) * len);
			strcpy(cmd, shell_aliases[c].cmd_name);	
			
			char *cmd_copy = malloc(sizeof(char) * len);
			strcpy(cmd_copy, shell_aliases[c].cmd_name);		
			
			char *token = strtok(cmd, " ");
			int num_tokens = 0;
			while(token != NULL){
				num_tokens++;
				token = strtok(NULL, " ");
			}		

			num_tokens++;

			args = malloc(sizeof(char *) * num_tokens);
 
                	token = strtok(cmd_copy, " ");
                  	for(i=0; token != NULL;i++){
                        	args[i] = malloc(sizeof(char) * strlen(token));
                        	strcpy(args[i], token);
                        	token = strtok(NULL, " ");
                  	}
                 	args[i] = NULL;

			/*for(i=0;args[i] != NULL;i++){
				printf("%s\n",args[i]);
			}*/

			exec_alias(args);	
			return true;
		}
		c++;
	}
	return false;
}
