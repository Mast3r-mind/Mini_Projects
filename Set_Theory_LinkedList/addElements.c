#include "setTheory.h"

void addElement(Node **hptr,int temp) {
	Node *new,*last;
	new = (Node *)malloc(sizeof(Node));
	new->iVal = temp;
	new->next = 0;
	if(*hptr == 0) {
		*hptr = new;
	}
	else {
		last = *hptr;
		while(last->next) 
			last = last->next;
		last->next = new;
	}
}
