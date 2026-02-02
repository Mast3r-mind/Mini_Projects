#include<stdio.h>

int main(int argc,char *argv[]) {
	if(argc<4) {
		printf("Not enough elements to perform CUT\n");
		return -1;
	}	
	FILE *fp;
	fp = fopen(argv[3],"r");
	if(fp == NULL) {
		printf("Unable to open the FILE\n");
		return -1;
	}
//	printf("%s %s\n",argv[1],argv[2]);
	
	char buf[50][200],field = argv[1][2];
	int row= 0,i,j,found;
	int opt = field-48;
	//printf("%d\n",opt);
	while(fscanf(fp,"%[^\n]\n",buf[row]) != EOF) {
	//	printf("%s\n",buf[row]);
		row++;
	}
	fclose(fp);
	//printf("%d\n",row);
	
	switch(opt) {
		case 1:
			i=0;
			while(i<row) {
				j=0;
				while(buf[i][j] != argv[2][2] && buf[i][j] != '\0') {
					printf("%c",buf[i][j]);
					j++;
				}
				printf("\n");
				i++;
			}
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			i=0;
			while(i<row) {
				j=0;
				found = 0;
				do {
					if(buf[i][j] == argv[2][2])
						found++;
					j++;
				}
				while(found != (opt-1));
		//		printf("\t%d\n",j);
				while(buf[i][j] != argv[2][2] && buf[i][j] != '\0') {
					printf("%c",buf[i][j]);
					j++;
				}
				printf("\n");
				i++;
			}
			break;
		default :
			printf("Choose the valid option\n");
	}
}


#if 0	
	if(argv[1][2] == '1') {	
		for(i=0;i<row;i++) {
			for(j=0;buf[i][j];j++) {
				if(argv[2][2] == buf[i][j]) {
					printf("\n");
					break;
				}
				printf("%c",buf[i][j]);
			}
		}
	}
	if(argv[1][2] == '2') {
		for(i=0;i<row;i++) {
			for(j=0;buf[i][j];j++) {
				if(buf[i][j] != argv[2][2])
					continue;
				else {
					for(k=j+1;buf[i][k];k++) {
						if(argv[2][2] == buf[i][k]) {
							printf("\n");
							break;
						}
						printf("%c",buf[i][k]);
					}
					break;
				
				}
			}
		}
	}
#endif
