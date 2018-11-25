#include<iostream>
#include<iomanip>
using namespace std;
void print(const int *arr);
int main()
{
    int *arr=new int[10];
    for(int i=0;i<10;++i)
        *(arr+i)=i;
    print(arr);
    return 0;
}
void print(const int *arr)
{
    int a;
    for(int i=0;i<10;++i)
    {
        switch(i)
        {
        case 0:
            cout<<arr[i];
            break;
        default:
            cout<<setw(2)<<arr[i];
        }
    }
}
