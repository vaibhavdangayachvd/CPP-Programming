#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream fout;
    fout.open("List1.txt");
    cout<<"Enter Sorted Numbers : ";
    for(int i=0;i<5;++i)
    {
        int temp;
        cin>>temp;
        fout<<temp<<endl;
    }
    fout.close();
    fout.open("List2.txt");
    cout<<"Enter Sorted Numbers : ";
    for(int i=0;i<5;++i)
    {
        int temp;
        cin>>temp;
        fout<<temp<<endl;
    }
    fout.close();
    ifstream f1("List1.txt"),f2("List2.txt");
    fout.open("Sorted.txt");
    int temp1,temp2;
    f1>>temp1;
    f2>>temp2;
    while(!f1.eof() && !f2.eof())
    {
        if(temp1<temp2)
        {
            fout<<temp1<<endl;
            f1>>temp1;
        }
        else
        {
            fout<<temp2<<endl;
            f2>>temp2;
        }
    }
    while(f1)
    {
        f1>>temp1;
        fout<<temp1<<endl;
    }
    while(f2)
    {
        f2>>temp2;
        fout<<temp2<<endl;
    }
    fout.close();
    f1.close();
    f2.close();
    return 0;
}
