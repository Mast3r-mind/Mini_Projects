#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARR_MAX 500

void fileSort(char **buf,int row) {
	for (;;) {
        	int flag = 0;
        	for (int j = 1; j < row; j++) {
            		if (strcmp(buf[j - 1], buf[j]) > 0) {
                		char *t = buf[j - 1];
                		buf[j - 1] = buf[j];
                		buf[j] = t;
                		flag = 1;
            		}
        	}
        if (flag == 0)
            break;
    }

}

int main(int argc,char *argv[]) {
	if(argc<4) {
		printf("Not enough arguments to perform SORT\n");
		return -1;
	}

	char field = argv[1][2],arr[ARR_MAX];
	int opt = field-48,row = 0,i;
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
		printf("Unable to allocate memory\n");
		return -1;
	}
	rewind(fp);
	i = 0;
	while(fgets(arr,ARR_MAX,fp) != NULL) {
		buf[i] = strdup(arr);
	//	printf("%s",buf[i]);
		i++;
	}
	fileSort(buf,row);
	
	for(i=0;i<row;i++) {
		printf("%s",buf[i]);
	}

	return 0;
}
#if 0
		cnt = 0;
		//printf("%s\n",buf[i]);
		while(buf[i][j] != '\n') {
			if(buf[i][j] == argv[2][2]) 
				cnt++;
			j++;
		}
		//printf("Count = %d\n",cnt);
		
		i++;
	}
	//printf("%d\n",row);
	i = 0;
	while(i<row) {
		found = 0,j=0;
		while(found != (opt-1)) {
			if(buf[i][j] == argv[2][2]) {
				found++;
			}
		}
	}


	return 0;	
}
#endif		
