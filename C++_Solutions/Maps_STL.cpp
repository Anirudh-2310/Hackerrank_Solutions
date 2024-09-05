#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q;
    cin >> Q;
    map<string, int> m;
    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        switch (q)
        {
        case 1:
        {
            string X;
            int Y;
            cin >> X >> Y;
            map<string, int>::iterator it = m.find(X);
            if (it == m.end())
                m.insert(make_pair(X, Y));
            else
                it->second += Y;
            break;
        }
        case 2:
        {
            string X;
            cin >> X;
            m.erase(X);
            break;
        }
        case 3:
        {
            string X;
            cin >> X;
            map<string, int>::iterator it = m.find(X);
            if (it == m.end())
                cout << "0" << endl;
            else
                cout << it->second << endl;
            break;
        }
        }
    }

    return 0;
}
