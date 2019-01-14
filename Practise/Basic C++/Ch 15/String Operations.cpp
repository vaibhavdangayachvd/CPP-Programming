#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1;
    string s2("Vaibhav"),s3(s2);
    s1=s2;
    string s4("Dangayach");
    s3=s1+" "+s4;
    cout<<(s2>s4);
    return 0;
}
