#include "setTheory.h"

Node* findDifference(Node *ptr1,Node *ptr2) {
	Node *result = NULL;
	Node *p1 = ptr1;

	while(p1 != NULL) {
		if(! isMatched(ptr2,p1->iVal)) {
			addElement(&result,p1->iVal);
		}
		p1 = p1->next;
	}
	return result;
}
