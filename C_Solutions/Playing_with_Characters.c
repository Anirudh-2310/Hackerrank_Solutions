#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    char ch;
    char str[10];
    char sen[20];
    scanf("%c\n%s\n%[^\n]s",&ch,str,sen);
    printf("%c\n%s\n%s",ch,str,sen);
    return 0;
}
