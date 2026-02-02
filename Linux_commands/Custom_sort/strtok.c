#include<stdio.h>

int main() {
	FILE *fp;
	fp = fopen("kali.txt","r");
	if(fp == NULL) {
		fprintf(stderr,"Unable to open the file\n");
		return -1;
	}
	char bu
}
