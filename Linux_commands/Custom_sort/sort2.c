#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARR_MAX 500

void sortField(int row,char fub[row][30]) {
	char t[30];
	int i,j;
	for (i=0;i<row-1;i++) {
        	for (j=i+1; j < row; j++) {
            		if (strcmp(fub[i], fub[j]) > 0) {
                	strcpy(t,fub[i]);
                	strcpy(fub[i],fub[j]);
                	strcpy(fub[j],t);
            		}
        	}
    	}

}

void sortFile(int row,char **buf,char fub[row][30]) {
	int i,j;
	for(i=0;i<row;i++) {
		for(j=0;j<row;j++) {
			if(strstr(buf[j],fub[i])) {
				printf("%s",buf[j]);
				break;
			}continue;
		}
	}
}
int main(int argc,char *argv[]) {
	if(argc<4) {
		printf("Not enough arguments to perform SORT\n");
		return -1;
	}

	char field = argv[1][2],arr[ARR_MAX],fub[20][30];
	int opt = field-48,row = 0,i,j,k,found;
	printf("Field :%d\n",opt);
	FILE *fp;
	fp = fopen(argv[3],"r");
	if(fp == NULL) {
		printf("Unable to open the file\n");
		return -1;
	}
	while(fgets(arr,ARR_MAX,fp)) {
	//	printf("%s",arr);
		row++;
	}
	printf("Line count :%d\n",row);

	char **buf = malloc(sizeof(*buf) * row);
	if(buf == NULL) {
		printf("Unable to allocate memory for buf\n");
		return -1;
	}

	rewind(fp);
	i = 0;
	while(fgets(arr,ARR_MAX,fp) != NULL) {
		buf[i] = strdup(arr);
	//	printf("%s",buf[i]);
		i++;
	}
	fclose(fp);
	i = 0;
	while(i<row) {
		found = 0,j=0;
		do {
			if(buf[i][j] == argv[2][2])
				found++;
				j++;
		}
		while(found != (opt-1));
		k=0;
		while(buf[i][j] != argv[2][2] && buf[i][j] != '\0' && buf[i][j] != '\n') {
                	fub[i][k] = buf[i][j];
                        j++;
			k++;
                }
		fub[i][k] = '\0';
               // printf("\n");

                i++;
	}
	sortField(row,fub);
	sortFile(row,buf,fub);

}
