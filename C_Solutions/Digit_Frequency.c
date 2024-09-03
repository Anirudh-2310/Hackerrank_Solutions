#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[1001];
    int i,a[] ={0,0,0,0,0,0,0,0,0,0};
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++){
        if('0'<=s[i] && s[i]<='9'){
            a[s[i]-'0']+=1;
        }
    }      
    for(i=0;i<10;i++)
        printf("%d ",a[i]);  
    return 0;
}
