#include<iostream>
using namespace std;
int main()
{
    int _size,*m;
    cout<<"Enter Size : ";
    cin>>_size;
    try
    {
        m=new int[_size];
    }
    catch(bad_alloc ba)
    {
        cout<<"Memory Allotment Not Successful !!";
        return 1;
    }
    cout<<"Memory Successfully Alloted !!";
    delete m;
    return 0;
}
