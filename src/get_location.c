#include "main.h"

char *get_location(char *command){
	
	struct stat buffer;
	if(stat(command, &buffer) == 0){
		return (command);
	}
	
	char *path, *path_copy;
	int command_length, directory_length;

	char *path_token, *file_path;

	path = getenv("PATH");
	path_copy = strdup(path);

	command_length = strlen(command);
	
	path_token = strtok(path_copy, ":");
	while(path_token != NULL){
		directory_length = strlen(path_token);
		file_path = malloc(command_length + directory_length + 2);
		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, command);
		strcat(file_path, "\0");

		if(stat(file_path, &buffer) == 0){
			free(path_copy);
			return (file_path);
		}
		else{
			free(file_path);
			path_token = strtok(NULL, ":");
		}
	}
	
	free(path_copy);
	return "";
}
