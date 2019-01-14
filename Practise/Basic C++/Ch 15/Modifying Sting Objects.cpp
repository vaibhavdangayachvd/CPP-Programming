#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1=("12345"),s2=("abcde");
    cout<<s1<<" "<<s2<<endl;
    s1.insert(4,s2);
    cout<<s1<<" "<<s2<<endl;
    s1.erase(4,5);
    cout<<s1<<" "<<s2<<endl;
    s2.replace(0,5,s1);
    cout<<s1<<" "<<s2<<endl;
    return 0;
}
