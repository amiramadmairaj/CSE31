
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	
	// Insert extra code here
	printf("\n head= %p \n head->iValue= %d \n head->fValue= %f \n head->next= %p \n", head, head->iValue, head->fValue, head->next);
    printf("\n &head= %p \n &head->iValue= %p \n &head->fValue= %p \n &head->next= %p \n", &head, &head->iValue, &head->fValue, &head->next);

	return 0;
}