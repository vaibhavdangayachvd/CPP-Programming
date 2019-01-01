#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char dev[40];
    cin.getline(dev,30);
    for(int i=strlen(dev);i>0;--i)
    {
        cout.write(dev,i);
        cout<<endl;
    }
    return 0;
}
