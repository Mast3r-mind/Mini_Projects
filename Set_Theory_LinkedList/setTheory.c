#include "setTheory.h"


int main() {
	int len1,len2,opt,num,i,j;

	printf("Enter the lenghth of set 1:");
	scanf("%d",&len1);
	printf("Enter the lenghth of set 2:");
	scanf("%d",&len2);

	Node *headptr1 = NULL;
	Node *headptr2 = NULL;
	Node *list_U = NULL;
	Node *list_I = NULL;
	Node *list_D = NULL;	

	printf("Enter %d elements of Set 1: \n",len1);
	for(i=1;i<=len1;i++) {
		int temp;
		scanf("%d",&temp);
		addElement(&headptr1,temp);
	}
	printf("Enter %d elements of Set 2: \n",len2);
	for(i=1;i<=len2;i++) {
		int temp;
		scanf("%d",&temp);
		addElement(&headptr2,temp);
	}

	printf("Elements of Set 1 is :\n");
	printSet(headptr1);
	printf("Elements of Set 2 is :\n");
	printSet(headptr2);
	
	i = 4;
	while(i>0) {
		printf("\n**************SET OPERATIONS***************\n");
		printf("\n1.Union     2.Intersection     3.Difference\n");
		printf("\nEnter your choice : ");
		scanf("%d",&opt);

		printf("___________________________________________\n");
		switch(opt) {
			case 1:
				list_U = findUnion(headptr1,headptr2);
				printf("\nUnion of Set-1 and Set-2 is :\n");
				printSet(list_U);	
				break;
			case 2:
				list_I = findIntersec(headptr1,headptr2);
				if(list_I == 0) {
					printf("Set-1 and Set-2 are Disjoint sets\n");
					break;
				}
				printf("\nIntersection of Set-1 and Set-2 is :\n");
				printSet(list_I);
				break;
			case 3:
				printf("\n1.Set1-Set2\t2.Set2-Set1\n");
				printf("Enter your choice\n");
				scanf("%d",&num);
				if(num == 1) {
					list_D = findDifference(headptr1,headptr2);
					printf("\nDifference of Set-1 and Set-2 is :\n");
					printSet(list_D);
				}
				else if(num == 2){
					list_D = findDifference(headptr2,headptr1);
					printf("\nDifference of Set-2 and Set-1 is :\n");
					printSet(list_D);	
				}
				else {
					printf("Enter a valid option\n");
					++i;
				}
				break;
			default:
				printf("Select a valid option\n");
				++i;
		}
		i--;
		printf("___________________________________________\n");
	}
	return 0;
}
