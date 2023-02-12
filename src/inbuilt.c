#include "main.h"

//config file initialized to => ./.shell_config/.shell_history
char *dirname = ".shell_config/";
char *res = ".shell_config/.shell_history";

bool isBuiltIn(char *cmd){
	char builtins[][30] = {"cd", "help", "alias", "history", "clear", '\0'};
	int i = 0;
	while(builtins[i] != NULL && strlen(builtins[i]) != 0 ){
		if(strncmp(cmd, builtins[i], strlen(builtins[i])) == 0) {
			return true;
		}
		i++;
	}
	return false;
}

int get_len(char *s){
	int c = 0;
	while(s[c] != '\0'){
		c++;
	}
	return c;
}

void setup_config(){
	DIR* dir = opendir(dirname);
	if((dir == NULL) && mkdir(dirname,0755) != 0){
		perror("shell: config: file not stored");
	}		
}

void update_history(char *his){
	FILE *fp = fopen(res, "a");
	if(fp != NULL){
		fprintf(fp, "%s", his);
	}
	fclose(fp);
}

void display_history(){
	char *buffer;
	int i = 0;
	ssize_t read;
	int len = 0;
	FILE *fp = fopen(res, "r");
	if(fp != NULL){
		while((read = getline(&buffer, &len, fp)) != -1){
			printf(" %d %s",++i,buffer);
		}
	}
	fclose(fp);
}
