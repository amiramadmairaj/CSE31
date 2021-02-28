#include <stdio.h>

int main() {
  int x = 0, y = 0, *px, *py; //#3

  int arr[10];
  for (int i = 0; i < 10; i++) {
    arr[i] = i;
  }

  printf("x= %d\ny= %d\narr[0]= %d", x, y, arr[0]);
  printf("\nAddress of x= %p\nAddress of y= %p", &x, &y); //#4
  //#5
  px= &x; 
  py= &y; 
  printf("\nAddress of *px= %p\nAddress of *py= %p", px, py); 
  printf("\nValues found at *px= %d\nValues found at *py= %d\n", *px, *py);
  printf("\n");


  for (int i = 0; i < 10; i++) { //#6
    printf("The contents of arr: %d\n", *(arr + i));
  }
printf("\nValue of Arr[0]: %d", arr[0]); //#7
printf("\nValue of Arr: %d",*arr);

printf("\nAddress of Arr[0]: %p", &arr[0]); //#8
printf("\nAddress of Arr: %p\n",&arr);
  return 0;

}