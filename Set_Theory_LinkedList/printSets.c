#include "setTheory.h"

void printSet(Node * ptr) {
	if(ptr == NULL) {
		printf("No elements found in set\n");
		return;
	}
	while(ptr != NULL) {
		printf("%d  ",ptr->iVal);
		ptr = ptr->next;
	}
	printf("\n");	
}



