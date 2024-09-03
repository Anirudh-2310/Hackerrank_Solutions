#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin>>N;
    vector<int>arr;
    int a;
    for(int i=0;i<N;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<' ';
    }
    return 0;
}
