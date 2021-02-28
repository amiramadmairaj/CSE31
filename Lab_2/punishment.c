#include <stdio.h>

int main() {

  int ErrorLocation = 0; int numOfPunishments;
  int i = 1; //initalize variables

  //This code block scans user for user input on number of punishment phrases 
  printf("Enter the number of repetitions for the punishment phrase: \n");
  scanf("%d", & numOfPunishments);
  //Determines invalid values (if num of punishment is less than 0 (ie. negative))
  if (numOfPunishments < 0) {
    printf("You entered an invalid value for the number of repetitions! \n");
    scanf("%d", & numOfPunishments);
  }

  //If numOfPunishment satisfies the requirement above ask for where to include typo
  if (numOfPunishments > 0) {
    printf("Enter the repetition count when you wish to introduce a typo: \n");
    scanf("%d", & ErrorLocation);
    //Determines invalid values (if ErrorLocation is beyond the number of punishments or if Error location happens at 0 or negative location)
    if (ErrorLocation <= 0 || ErrorLocation > numOfPunishments) {
      printf("You entered an invalid value for the number of repetitions! \n");
      scanf("%d", & ErrorLocation);
    }
    //If ErrorLocation satisfies the requiremnt above, continue to print "punishment"
    if (ErrorLocation > 0 || numOfPunishments > ErrorLocation) {
      while (i < numOfPunishments) {
        if (i == ErrorLocation) {
          printf("C programmming lnguage is the bet! ");
        } else {
          printf("C programming language is the best! ");
        }
        i++; //increment for while loop to move forward to next line
      }
    }
    printf("\n"); //new line 
  }
  return 0;
}