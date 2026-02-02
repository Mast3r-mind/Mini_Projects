#include "setTheory.h"

int isMatched(Node *ptr,int data) {
        Node *temp = ptr;
        int flag = 0;
        while(temp != NULL) {
                if(temp->iVal == data) {
                        flag = 1;
                        break;
                }
                temp = temp->next;
        }
        return flag;
}

