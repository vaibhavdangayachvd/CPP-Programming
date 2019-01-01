#include<iostream>
using namespace std;
int main()
{
    int _count=0;
    char c;
    c=cin.get();
    while(c!='\n')
    {
        ++_count;
        cout.put(c);
        c=cin.get();
    }
    cout<<"\nCount = "<<_count;
    return 0;
}
