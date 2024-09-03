#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        unsigned int N,S,P,Q;
        unsigned int count=1;
        cin>> N >>S>>P>>Q;
        unsigned int prev=S; 
        for(int i=1;i<N;i++)
        {
            S= (S*P+Q)%(unsigned int)pow(2,31);
            count += (S!=prev) ? 1 : 0;
            prev=S;
            
        }    
        cout<<count;
       
return 0;
}
