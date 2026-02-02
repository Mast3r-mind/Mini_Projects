#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortfile(char **arr, int linecount) {
    for (;;) {
        int swapped = 0;
        for (int j = 1; j < linecount; j++) {
            if (strcmp(arr[j - 1], arr[j]) > 0) {
                char *t = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = t;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int main() {
    FILE *fileIN, *fileOUT;
    char singleline[500];
    int i, linecount;

    fileIN = fopen("kali.txt", "r");
    if (fileIN == NULL) {
        fprintf(stderr, "cannot open %s\n", "test1.txt");
        return 1;
    }

    linecount = 0;
    while (fgets(singleline, 500, fileIN)) {
        linecount++;
    }

    printf("line count=%d\n", linecount);

    char **arr = malloc(sizeof(*arr) * linecount);
    if (arr == NULL) {
        fprintf(stderr, "memory allocation failure\n");
        return 1;
    }

    rewind(fileIN);
    for (i = 0; i < linecount && fgets(singleline, 500, fileIN) != NULL; i++) {
        arr[i] = strdup(singleline);
	printf("%s\n",arr[i]);
        if (arr[i] == NULL) {
            fprintf(stderr, "memory allocation failure\n");
            return 1;
        }
    }
    fclose(fileIN);

    if (i != linecount) {
        fprintf(stderr, "line count mismatch: i=%d, lilnecount=%d\n",
                i, linecount);
        linecount = i;
    }

    sortfile(arr, linecount);

    for (i = 0; i < linecount; i++) {
        printf("%s", arr[i]);
    }
    fileOUT = fopen("out.txt", "w");
    if (!fileOUT) {
        fprintf(stderr, "cannot open %s\n", "out.txt");
        return 1;
    }
    for (i = 0; i < linecount; i++) {
        fprintf(fileOUT, "%s", arr[i]);
    }
    fclose(fileOUT);

    for (i = 0; i < linecount; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
