#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>

#include<sys/types.h>
#include<sys/stat.h>

typedef struct aliases {
	char *alias_name;
	char *cmd_name;
} alias;

void execmd(char **argv);
char *get_location(char *command);

bool isBuiltIn(char *command);
bool isAlias(char *command);
int get_len(char *string);
void setup_config();
void update_history(char *hist);
void display_history();

void create_alias(char **argv);
void print_alias();
void add_alias(char **argv);

void exec_cd(char **argv);
void exec_help();
void exec_clear();
void exec_alias(char **argv);
void exec_history(char **argv);
