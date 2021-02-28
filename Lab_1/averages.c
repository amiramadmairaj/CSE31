#include<stdio.h>

int main() {

  int count_pos = 0; int pos_sum = 0; int count_neg = 0; int neg_sum = 0; //initalize sum variables and count variables
  int num = 1; //user input initialized to 1, just so it can enter while condition 

  while (num != 0) //runs until 0 is entered
  {
    printf("Please enter an integer :");
    scanf("%d", & num);

    if (num < 0) //if negative number
    {
      neg_sum = neg_sum + num; //keep track of sum
      count_neg++; //counts number of negative elements 
    } else if (0 < num) //if positive number
    {
      pos_sum = pos_sum + num; //keep track of sum
      count_pos++; //counts number of positive elements
    }
  }
  
  //printing output
  if (count_pos != 0) {
    int pos_avg = pos_sum / count_pos;
    printf("Positve average :%d\n", pos_avg);
  }
  if (count_neg != 0) {
    int neg_avg = neg_sum / count_neg;
    printf("Negative average :%d\n", neg_avg);
  }
  return 0;
}

//OLD GARBAGE CODE TO SHOW THINKING PROCESS:
// #include <stdio.h>

// int avg_pos(int n){
// int pos; int sumpos;
//      sumpos += n;


//    int pos_avg = sumpos / n;

// return pos_avg;
//      }



//  int avg_neg(int n){
// int neg; int sumneg;
//      sumneg += n;

//    int neg_avg = sumneg / n;


// return neg_avg;
// }

// int main()
//      {
//          int num;

// while (num!=0){
// printf("Please enter an integer: ");
//     scanf("%d", &num);
// if (num>=1){
// avg_pos(num);
// }


// else if (num<=-1) {
// avg_neg(num);
// }
// }

// int pos_average; int neg_average;
// pos_average= pos_avg; 
// neg_average= neg_avg;
// if (pos_average>0)
// printf("Positive average: \n");
// if (neg_average<0)
// printf("Negitive average: \n");
// return 0;
// }
