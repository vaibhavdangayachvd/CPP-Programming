#include<iostream>
using namespace std;
int main()
{
    int price[4]={2,2,3,4};
    char *name[4]={"Vaibhav","Shivam","Vishal","Mohit"};
    cout.width(6);
    cout<<"Name";
    cout.width(16);
    cout<<"Price\n\n";
    for(int i=0;i<4;++i)
    {
        cout.width(8);
        cout.setf(ios::leftjst   ,ios::floatfield);
        cout<<name[i];
        cout.width(10);
        cout<<price[i];
        cout<<endl;
    }
    return 0;
}
