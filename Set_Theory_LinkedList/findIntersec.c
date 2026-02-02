#include "setTheory.h"

Node *findIntersec(Node *headptr1,Node *headptr2) {
	Node *result = NULL;
	Node *p1 = headptr1;
	
	while(p1 != NULL) {
		if(isMatched(headptr2,p1->iVal)) {
			addElement(&result,p1->iVal);
		}
		p1 = p1->next;
	}
	return result;
}  
