#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1("ABC"),s2("XYZ"),s3=s1+s2;
    cout<<s1<<" "<<s2<<" "<<s3<<endl;
    if(s1!=s2)
        cout<<s1<<" is not equals to "<<s2<<endl;
    if(s1>s2)
        cout<<s1<<" is greater than "<<s2<<endl;
    else
        cout<<s2<<" is greater than "<<s1<<endl;
    if(s3==s1+s2)
        cout<<s3<<" is equals to "<<s1+s2<<endl;
    int x=s1.compare(s2);
    if(x==0)
        cout<<s1<<" is equal to <<"<<s2<<endl;
    else if(x>0)
        cout<<s1<<" is greater than <<"<<s2<<endl;
    else
        cout<<s2<<" is greater than "<<s1<<endl;
    return 0;
}
