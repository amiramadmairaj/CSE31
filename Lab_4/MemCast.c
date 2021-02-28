#include <stdio.h>

int main() {
  int i;
  int four_ints[4];
  char * four_c;

  for (i = 0; i < 4; i++)
    four_ints[i] = 2;

  printf("%x\n", four_ints[0]);

  four_c = (char * ) four_ints;

  for (i = 0; i < 4; i++)
    four_c[i] = 'A' + i; // ASCII value of 'A' is 65 or 0x41 in Hex.

  // Add your code for the exercises here:
  printf("\n");
  printf("First element in four_ints (four_ints[0]): %x\n", four_ints[0]);
  printf("\n");
  printf("Secound element in four_ints (four_ints[1]): %x\n", four_ints[1]);
  printf("\n");
  //Print all values in four_ints and four_c
  printf("Printing all the elements contained in four_ints: (PRINTED IN HEX) \n");
  for (i = 0; i < 4; i++) {
    printf("%x\n", four_ints[i]);
  }
  printf("\n");
  printf("Printing all the elements contained in four_c: (PRINTED IN HEX) \n");
  for (i = 0; i < 4; i++) {
    printf("%x\n", four_c[i]);
  }
  printf("\n");
  printf("Printing all the elements (and their addresses) contained in four_ints: (PRINTED IN HEX) \n");
  for (i = 0; i < 4; i++) {
    printf("\nValue: %x\n Address: %p\n", four_ints[i], & four_ints[i]);
  }
  printf("\n");
  printf("Printing all the elements (and their addresses) contained in four_c: (PRINTED IN HEX) \n");
  for (i = 0; i < 4; i++) {
    printf("\nValue: %x\n Address: %p\n", four_c[i], & four_c[i]);
  }

  return 0;
}