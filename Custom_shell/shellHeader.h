/*
 *Making my own simple shell by using fork, exec, pipe and dup system calls.
 *
 *notes :
 *	Here "+" is referred as pipe symbol
 *	Here ">" is referred as output redirection symbol  
 *	Here ">>" is referred as output redirection append symbol  
 *	Here "<" is referred as input redirection symbol
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_SIZE 512
#define clear() printf("\033[H\033[J") //for clear the screen

void sysCom(char **);//for single commands with options
void extCom(char **,char **);//for piped commands
void redirOut(char **,char *,char *);//for redirection purpose
