#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
void display(vector<int> &a);
int main()
{
    int arr[5],c=0;
    list<int> vd;
    for(int i=1;i<=10;i++)
    {
        if(i%2)
            arr[c++]=i;
        else
            vd.push_back(i);
    }
    vector<int> hd(10);
    merge(arr,arr+5,vd.begin(),vd.end(),hd.begin());
    display(hd);
    return 0;
}
void display(vector<int> &a)
{
    for(int i=0;i<a.size();++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
