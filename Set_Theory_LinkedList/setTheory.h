#include<stdio.h>
#include<stdlib.h>

typedef struct set {
	int iVal;
	struct set *next;
}Node;


void addElement(Node **,int);
void printSet(Node *);
Node* findUnion(Node *,Node *);
Node* findIntersec(Node *,Node *);
Node* findDifference(Node *,Node *);
int isMatched(Node *,int);
