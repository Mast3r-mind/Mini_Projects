#include<stdio.h>
#include<string.h>


int main(int argc,char *argv[]) {
	if(argc<3) {
		printf("USAGE : ./Grep  filename  word\n");
		return -1;
	}
	int i,j,cnt=0,wlen;
	char buf[100][200];
	FILE *fp;
	switch(argc) {
		case 3:
			fp = fopen(argv[1],"r");
			if(fp == NULL) {
				printf("Unable to open file\n");
				return -1;
			}
			i =0;
			while(fscanf(fp,"%[^\n]\n",buf[i]) != EOF) {
				if(strstr(buf[i],argv[2])) {
					printf("%s\n",buf[i]);
					i++;
				}
			}
			fclose(fp);
			break;
		case 4:
			fp = fopen(argv[2],"r");
			if(fp == NULL) {
				printf("Unable to open file\n");
				return -1;
			}
			wlen = strlen(argv[3]);
			if(strcmp(argv[1],"-c")==0) {
				i=0;
				while(fscanf(fp,"%[^\n]\n",buf[i]) != EOF) {
					for(j=0;buf[i][j]!='\0';j++) {
						if(strstr(&buf[i][j],argv[3]) == &buf[i][j]) {
							cnt++;
							j += wlen-1;
						}
					}
					i++;
				}	
				printf("Word present %d times\n",cnt);
				fclose(fp);
			}
			if(strcmp(argv[1],"-n") ==0) {
				i=0;
				while(fscanf(fp,"%[^\n]\n",buf[i]) != EOF) {
					if(strstr(buf[i],argv[3])) {
						printf("Line no: %d\t%s\n",i+1,buf[i]);
					}
					i++;
				}
			fclose(fp);	
			}
			break;
	}
}

