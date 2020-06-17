#include <stdio.h>

int main() {

  int product;
  int a[7];

  a[0] = 4;
  a[1] = 7;
  a[2] = 9;
  a[3] = 13;
  a[4] = 9;
  a[5] = 2;
  a[6] = 19;
   
 
  product = a[0] * a[1] *a[2]* a[3] * a[4] * a[5] * a[6];
  printf("The product of all elements of the array a is: %d \n", product);

  return 0;
}
