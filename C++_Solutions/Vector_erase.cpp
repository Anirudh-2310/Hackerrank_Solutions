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
    int x;
    for(int i=0;i<N;i++)
    {
        cin>>x;
        arr.push_back(x);
    }
    int q,a,b;
    cin>>q>>a>>b;
    arr.erase(arr.begin()+q-1);
    arr.erase(arr.begin()+a-1,arr.begin()+b-1);
    cout<<arr.size()<<'\n';
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<' ';
    }
    return 0;
}
