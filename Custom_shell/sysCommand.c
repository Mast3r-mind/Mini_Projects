#include <shellHeader.h>

void sysCom(char **argv) {
        int pid = fork(); //create a child process
        if(pid == -1){
                perror("fork");
                return;
        }
        if(pid == 0) {
                execvp(argv[0],argv); //execute the command in child process
	}
        waitpid(pid,NULL,0); //wait for the child to execute and terminate.

}
