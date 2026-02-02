#include <shellHeader.h>

void redirOut(char **argv,char *fileName,char *opt) {
	int fd;
	if(strcmp(opt,">")==0)
		fd = open(fileName,O_WRONLY | O_CREAT | O_TRUNC,00644);
	if(strcmp(opt,">>")==0)
		fd = open(fileName,O_WRONLY | O_APPEND);
	if(strcmp(opt,"<")==0) 
		fd = open(fileName,O_RDONLY); 
	if(fd <0) {
		perror("OPEN");
		return;
	}
	pid_t pid = fork();
	if(pid < 0) {
		perror("fork");
		return;
	}
	if(pid == 0) {
		if(strcmp(opt,"<")==0) 
			dup2(fd,0);
		else 
			dup2(fd,1);

		execvp(argv[0],argv);
	}
	waitpid(pid,NULL,0);
}
