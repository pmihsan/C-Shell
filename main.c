#include "main.h"

int main(int argc, char* argv[]){

	char *black = "\033[0;30m";
	char *red = "\033[0;31m";
	char *green = "\033[0;32m";
	char *yellow = "\033[0;33m";
	char *blue = "\033[0;34m";
	char *purple = "\033[0;35m";
	char *cyan = "\033[0;36m";
	char *white = "\033[0;367m";
	char *end = "\033[0m";

	char *user = getenv("USER");
	char *prompt = "shell";
	char cwd[256];
	cwd[255] = '\0';
	char *lineptr = NULL;

	char *lineptr_copy = NULL;
	const char *delim = " \n";

	size_t n = 0;
	ssize_t nchars_read;

	char *token;
	int num_tokens = 0, i = 0;

	(void)argc;
	
	setup_config();

	while(1){
		if(getcwd(cwd, 255) == NULL){
			perror("shell: can not get current workdir");
		}
		printf("(%s%s%s%s@%s%s%s%s)-[%s%s%s] %s$%s ",green,user,end,yellow,end,cyan,prompt,end,blue,cwd,end,yellow,end);
		nchars_read = getline(&lineptr, &n, stdin);
		
		if(nchars_read == 1 && strcmp(lineptr, "\n") == 0) {
			continue;			
		}
		
		if(strncmp(lineptr, "exit", 4) == 0){
			update_history(lineptr);
			printf("exit\n");
			return (1);
		}

		if(nchars_read == -1){
			printf("Exiting shell...\n");
			return (-1);
		}
		
		update_history(lineptr);

		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if(lineptr_copy == NULL){
			perror("shell: memory allocation error");
        		return (-1);
		}
		strcpy(lineptr_copy, lineptr);

		token = strtok(lineptr, delim);
		while(token != NULL){
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		argv = malloc(sizeof(char *) * num_tokens);
		
		token = strtok(lineptr_copy, delim);	
		for(i=0; token != NULL;i++){
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		/*for(i=0;argv[i] != NULL;i++){
			printf("%s\n",argv[i]);
		}*/

		execmd(argv);

		free(argv);
		/*printf("%s\n",lineptr);*/	
	}

	free(lineptr_copy);
	free(lineptr);
	return (0);
}
