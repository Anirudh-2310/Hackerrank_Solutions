#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n,i,j,a;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
      for(i=0;i<2*n-1;i++)
      {
          for(j=0;j<2*n-1;j++)
          {
              //Using Ternary Operator
              a = ( i < j ) ? i : j;
              a = (a < 2*n-1-i) ? a : 2*n-2-i;
              a = (a < 2*n-2-j)? a : 2*n-2-j;
              printf("%d ",n-a);
              
          }
          printf("\n");
      }
    return 0;
}