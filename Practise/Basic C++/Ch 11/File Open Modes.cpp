#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
    char name[20];
    char ch;
    cout<<"Enter name : ";
    cin>>name;
    fstream fp;
    fp.open("Name.txt",fstream::out);
    fp.close();
    fp.open("Name.txt",ios::out|ios::in);
    for(int i=0;i<strlen(name);++i)
        fp.put(name[i]);
    fp.seekg(0);
    while(fp)
    {
        ch=fp.get();
        cout<<ch;
    }
    fp.close();
    return 0;
}
