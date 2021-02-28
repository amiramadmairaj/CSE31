#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void printArr(int *a, int size, char *name){
	//Your code here
   
for(int i=0;i<sizeof(name);i++){
        printf("%c",*(name+i)); //prints out 

    }

 printf(" array’s contents: ");
    for(int i=0;i<size;i++){
        printf("%d ",*(a+i));
    }
    printf("\n");
}

int* arrCopy(int *a, int size){
int *copy;
copy = (int*) malloc (sizeof(int)*size);
for(int i=0; i<size; i++){
    *(copy+i)=(*(a+i));
}
return copy;
}

int main(){
    int n;
    int *arr;
    int *arr_copy;
    int i;
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &n);

    //Dynamically create an int array of n items
    //Your code here
arr = (int *)malloc(sizeof(int)*n); //malloc: dynamic memory allocation

    //Ask user to input content of array
	//Your code here
    for(int i=0; i<n; i++){
    printf("Enter array element #%d: ",i+1);
    scanf("%d", arr+i);
    }

/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n, "Original");

	//Copy array
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n, "Copied");

    printf("\n");

    return 0;
}