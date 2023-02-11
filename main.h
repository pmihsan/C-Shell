#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/stat.h>

void execmd(char **argv);
char *get_location(char *command);

bool isBuiltIn(char *command);
bool isAlias(char *command);
int get_len(char *string);

void exec_cd(char **argv);
void exec_help(char **argv);
void exec_clear(char **argv);
void exec_alias(char **argv);
