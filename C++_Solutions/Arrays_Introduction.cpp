#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a[1000],n,x;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n/2;i++)
    {
        x=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=x;
    }
    for(int i=0;i<n;i++)
    {
        cout << a[i] <<" ";
    }
    
    return 0;
}
