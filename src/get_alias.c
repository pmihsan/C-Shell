#include "main.h"

int MAX = 20;
static int count = 2;

alias shell_aliases[20] = {
	{"l", "ls --color=auto -l"},
	{"ll", "ls -l -h"},
	{NULL, NULL},
};

bool isAlias(char *CMD){
	int c = 0, i;
	char **args;
	while(c < MAX){
		if(shell_aliases[c].alias_name == NULL){
			c++;
			continue;
		}
		if(strcmp(CMD, shell_aliases[c].alias_name) == 0){
			int len = strlen(shell_aliases[c].cmd_name);
			char *cmd = malloc(sizeof(char) * len);
			strcpy(cmd, shell_aliases[c].cmd_name);	
			char *cmd_copy = strdup(cmd);			

			/*
			char *cmd_copy = malloc(sizeof(char) * len);
			strcpy(cmd_copy, shell_aliases[c].cmd_name);		
			*/
		
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
			
			free(cmd);
			free(cmd_copy);
			
			exec_alias(args);	
			free(args);
			return true;
		}
		c++;
	}
	return false;
}

void add_alias(char **argv){
	char *alias_cmd = strtok(argv[1],"=");
	char *actual_cmd = strtok(NULL,"\"");
	
	shell_aliases[count].alias_name = alias_cmd;
	shell_aliases[count].cmd_name = actual_cmd;
	count++;
	shell_aliases[count].alias_name = NULL;
	shell_aliases[count].cmd_name = NULL;
}

bool del_alias(char **argv){
	int c = 0;
	while(c < MAX){
		if(shell_aliases[c].alias_name == NULL){
			c++;
			continue;
		}
		if(strcmp(argv[1], shell_aliases[c].alias_name) == 0){
			shell_aliases[c].alias_name = NULL;
			shell_aliases[c].cmd_name = NULL;
			return true;
		}
		c++;
	}
	return false;
}

void print_alias(){
	int c = 0;
	while(c < MAX){
		if(shell_aliases[c].alias_name == NULL){
			c++;
			continue;
		}
		printf("alias %s='%s'\n",shell_aliases[c].alias_name,shell_aliases[c].cmd_name);
		c++;
	}
}
