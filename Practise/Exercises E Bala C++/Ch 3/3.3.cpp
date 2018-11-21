#include<iostream>
using namespace std;
int main()
{
    int _size;
    cout<<"Enter size : ";
    cin>>_size;
    for(int i=0;i<_size;++i)
    {
        for(int j=0;j<=i;++j)
            cout<<i+1<<" ";
        cout<<endl;
    }
    return 0;
}
