#include "main.h"

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
	if(d == 2) return;

	//config file initialized to => $HOME/.shell_config/.shell_history
	char *dirname = getenv("HOME");
	if(dirname == NULL) dirname = "/tmp";
	
	strcat(dirname, "/shell_config");
	
	DIR* dir = opendir(dirname);
	if((dir == NULL) && mkdir(dirname,0755) != 0){
		perror("shell: config: file not stored");
	}
	closedir(dir);	
	d = 2;	
}	

void update_history(char *his){
	char *home = getenv("HOME");
	if(home == NULL) home = "/tmp";

	if(f == 1) strcat(home, "/.shell_history");

	FILE *fp = fopen(home, "a");
	if(fp != NULL){
		fprintf(fp, "%s", his);
	}
	fclose(fp);
	f = 2;
}

void display_history(){
	char *home = getenv("HOME");
	if(home == NULL) home = "/tmp";

	if(f == 1) strcat(home, "/.shell_history");
	
	char *buffer;
	int i = 0;
	ssize_t read;
	
	int len = 0;
	FILE *fp = fopen(home, "r");
	if(fp != NULL){
		while((read = getline(&buffer, &len, fp)) != -1){
			printf(" %d %s",++i,buffer);
		}
	}
	fclose(fp);
	f == 2;
}
