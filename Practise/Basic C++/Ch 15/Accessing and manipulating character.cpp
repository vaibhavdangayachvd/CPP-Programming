#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s("ONE TWO THREEE FOUR");
    for(int i=0;i<s.length();++i)
        cout<<s[i];
    cout<<endl;
    int x1 = s.find("HA");
    cout<<s.substr(x1,3);
    return 0;
}
