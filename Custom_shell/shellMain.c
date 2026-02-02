#include <shellHeader.h>

int main() {
        char buff[MAX_SIZE];
        char *argv[20];
        char *argv1[20];
        int argc;
        int argc1;

        clear();
	printf("Welcome to %s's shell\n",getenv("USER"));
        while(1) {
                printf("kali-bash >> ");
                fgets(buff,MAX_SIZE,stdin);
                size_t len = strlen(buff);
                if(buff[len-1] == '\n')
                        buff[len-1] = '\0';
                //printf("%s\n",buff);

                if(len == 0)
                        break;
                if(strcmp(buff,"exit") == 0)
                        exit(0);

                int i=0,j=0;
                char *plus = "+";
                char *rdir = ">";
                char *append = ">>";
                char *irdir = "<";
                char *token,*file = NULL,*opt = NULL;
                token = strtok(buff," ");
                while(token != NULL && i<20) { 
                        argv[i] = token;            //storing each strings in a pointer of a array of pointers
                        token = strtok(NULL," ");
			if((strcmp(argv[i],rdir)==0) || (strcmp(argv[i],append)==0) || (strcmp(argv[i],irdir)==0)) {
				opt = argv[i];
				//printf("%s\n",opt);
				file = token;
				//printf("%s\n",file);
				break;
			}
                        if(strcmp(argv[i],plus)==0) {  //chect if "+"(pipe) found
                                //printf("+ detected\n");
                                while(token != NULL && j<(20-i)) {
                                        argv1[j]=token; //if pipe found the store next set of strings in another array of pointes.
                                        token = strtok(NULL," ");
                                        j++;
                                }
                                break;
                        }
                        i++;
                }
                argv[i] = NULL; //set last pointers an NULL
                argv1[j] = NULL; //set last pointers an NULL
                argc =i;     
                argc1 =j; 

		if((argv1[0] == NULL) && (opt == NULL))
                	sysCom(argv);
		else if(opt != NULL) {
		 	redirOut(argv,file,opt);
			//printf("%s\t%s\n",opt,file);
		}
		else
                	extCom(argv,argv1);
        }
        return 0;
}
