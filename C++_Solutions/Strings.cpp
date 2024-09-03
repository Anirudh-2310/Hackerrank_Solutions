#include <iostream>
#include <string>

using namespace std;

int main() {
	// Complete the program
    string s1,s2,s3;
    cin>> s1 >> s2 ;
    int length_s1=s1.size();
    int length_s2=s2.size();
    cout << length_s1 << " " << length_s2 <<"\n";
    s3 = s1+s2;
    cout<< s3 <<"\n";
    char c1=s1[0];
    char c2=s2[0];
    s1[0]=c2;
    s2[0]=c1;
    cout<<s1<<" "<<s2;
    return 0;
}
