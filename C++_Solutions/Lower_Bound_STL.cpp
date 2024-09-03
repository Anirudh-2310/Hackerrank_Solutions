#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,q,x;
    cin >> n;
    vector<int> arr;
    for(int i=0 ; i<n ; i++)
    {
        cin >> x;
        arr.push_back(x); 
    } 
        cin >> q;
    for(int i=0 ; i<q ;i++)
    {
        cin >> x;
        auto low = lower_bound(arr.begin(),arr.end(),x);
       if(arr[low-arr.begin()]==x){
           cout << "Yes " <<  low-arr.begin()+1 << '\n';
       }
       else cout << "No " <<  low-arr.begin()+1 << '\n';
    }
    return 0;
}
