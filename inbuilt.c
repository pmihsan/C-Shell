#include "main.h"

bool isBuiltIn(char *cmd){
	char builtins[5][30] = {"cd", "help", "alias", "clear", '\0'};
	
	int i = 0;
	int len;
	while( (len = get_len(builtins[i])) != 0){
		if(strncmp(cmd, builtins[i], len) == 0) {
			return true;
		}
		len = get_len(builtins[i]);
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
