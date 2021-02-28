#include <stdio.h>

#include <stdlib.h>

// int ** matMult(int ** a, int ** b, int size) {
//   int i, j;
//   int ** product = (int ** ) malloc(size * sizeof(int * ));
//   //setting aside memory for product
//   for (i = 0; i < size; i++) {
//     *(product + i) = (int * ) malloc(size * sizeof(int));
//     for (j = 0; j < size; j++) {
//       *( * (product + i) + j) = 0;
//     }
//   }
//   for (i = 0; i < size; i++) {
//     for (j = 0; j < size; j++) {
//       *( * (product + i) + j) = ( * ( * (a + i) + j)) * ( * ( * (b + i) + j)); //multiply together here
//     }
//   }
//   return product;

// }



int ** matMult(int ** a, int ** b, int size) {

  int i, j, k;
  int ** product = (int ** ) malloc(size * sizeof(int * ));
    for ( i = 0; i < size; i++){
     *(product + i) = (int * ) malloc(size * sizeof(int));
        for ( j = 0; j <size; j++){
           *( * (product + i) + j) = 0;
            for ( k = 0; k < size; k++){
                 *( * (product + i) + j) = *( * (product + i) + j) + ( * ( * (a + i) + k)) * ( * ( * (b + k) + j));
        }
      }
    }
        return product;
}











void printArray(int ** arr, int n) {
  // (2) Implement your printArray function here
  int i = 0, j = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", *( * (arr + i) + j));
    }
    printf("\n");

  }
  printf("\n\n");

}

int main() {
  int n = 0;
  int ** matA, ** matB, ** matC;
  // (1) Define 2 (n x n) arrays (matrices). 
  printf("Please enter a value for n:");
  scanf("%d", & n);
  int i = 0, j = 0;

  matA = (int ** ) malloc(n * sizeof(int * ));
  //setting aside memory for matA
  for (i = 0; i < n; i++) {
    *(matA + i) = (int * ) malloc(n * sizeof(int));

    for (j = 0; j < n; j++) {
      *( * (matA + i) + j) = i;
    }
  }
  matB = (int ** ) malloc(n * sizeof(int * ));
  //setting aside memory for matB
  for (i = 0; i < n; i++) {
    *(matB + i) = (int * ) malloc(n * sizeof(int));

    for (j = 0; j < n; j++) {
      *( * (matB + i) + j) = i;
    }
  }

  // (3) Call printArray to print out the 2 arrays here.
  printArray(matA, n);
  printArray(matB, n);

  // (5) Call matMult to multiply the 2 arrays here.
  matC = matMult(matA, matB, n);

  // (6) Call printArray to print out resulting array here.
  printArray(matC, n);

  return 0;
}