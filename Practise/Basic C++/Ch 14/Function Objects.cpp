#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{
    int arr1[]={2,3,5,1,4};
    int arr2[]={2,3,5,1,4};
    sort(arr1,arr1+5,greater<int>());
    sort(arr2,arr2+5);
    for(int i=0;i<5;++i)
        cout<<arr1[i]<<" ";
    cout<<endl;
    for(int i=0;i<5;++i)
        cout<<arr2[i]<<" ";
    cout<<endl;
    int arr3[10];
    merge(arr1,arr1+5,arr2,arr2+5,arr3);
    for(int i=0;i<10;++i)
        cout<<arr3[i]<<" ";
    cout<<endl;
    return 0;
}
