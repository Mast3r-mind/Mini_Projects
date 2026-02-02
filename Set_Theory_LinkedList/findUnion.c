#include "setTheory.h"

Node* findUnion(Node *headptr1,Node *headptr2) {
	if(headptr1 == 0 && headptr2 == 0) {
		printf("Set is Empty..,Come again with the valid Sets!\n");
		exit(0);
	}
	Node *result = NULL;
	Node *p1 = headptr1,*p2 = headptr2;
	while(p1 != NULL) {
		addElement(&result,p1->iVal);
		p1=p1->next;
	}
	while(p2 != NULL) {
		if(! isMatched(result,p2->iVal))
			addElement(&result,p2->iVal);
		p2 = p2->next;
	}

	return result;
}

