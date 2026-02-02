#include <shellHeader.h>

void extCom(char **argv,char **argv1) {
        int pfd[2];
        if(pipe(pfd) == -1) { //create a pipe for write and read
                perror("pipe");
                return;
        }
        pid_t p1 = fork(); //create a child process for first command
        if(p1 < 0) {
                perror("fork");
                return;
        }
        if(p1 == 0) {   
                dup2(pfd[1],1);
                close(pfd[0]);
                close(pfd[1]);
                execvp(argv[0],argv);
        }

        pid_t p2 = fork();
        if(p2 < 0 ) {
        	perror("fork");
        	return;
       	}
        if (p2 == 0) {
         	dup2(pfd[0],0);
        	close(pfd[0]);
        	close(pfd[1]);
         	execvp(argv1[0],argv1);
     	}

	close(pfd[0]);
	close(pfd[1]);

        waitpid(p1,NULL,0);
        waitpid(p2,NULL,0);
      
}
