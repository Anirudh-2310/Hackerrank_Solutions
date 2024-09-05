#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q;
    cin >> Q;
    set<int> s;
    for (int i = 0; i < s.size(); i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }
    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> y >> x;

        switch (y)
        {

        case 1:
        {
            s.insert(x);
            break;
        }
        case 2:
        {
            s.erase(x);
            break;
        }
        case 3:
        {
            set<int>::iterator it = s.find(x);
            if (it == s.end())
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
                break;
            }
        }
        }
    }

    return 0;
}
