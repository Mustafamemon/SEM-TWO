#include <iostream>
#include <string>
using namespace std;

int main() {
    string s,s1;
	  cin>>s;
    cin>>s1;
    cout<<s.length()<<" "<<s1.length()<<"\n";
    cout<<s+s1;
    char temp=s[0];
    s[0]=s1[0];
    s1[0]=temp;
    cout<<s<<" "<<s1;
    return 0;
}
