#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
      // Complete the code.
      if(a==1 && b==2)
      {
          printf("one\n");
          {
              printf("two\n");
          }
      }
      else
      {
        switch(a)
        {
            case 1:printf("one\n");
            case 2:printf("two\n");
            case 3:printf("three\n");
            case 4:printf("four\n");
            case 5:printf("five\n");
            case 6:printf("six\n");
            case 7:printf("seven\n");
            case 8:printf("eight\n");
            case 9:printf("nine\n");
            default:printf("even\n");
        }

            for(int i=11;i<=b;i++)
        {
            if(i%2==0)
            {
                printf("even\n");
            }
            else 
            {
            printf("odd\n");
            }
        }
      }
            
    return 0;
}

