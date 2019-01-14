#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &a);
int main()
{
    vector<int> vd(10);
    vector<int>::iterator itr = vd.begin();
    *itr=0;
    itr=vd.end()-1;
    *itr=9;
    for(itr=vd.begin()+1;itr!=vd.end()-1;++itr)
        *itr=1;
    display(vd);
    return 0;
}
void display(vector<int> &a)
{
    for(int i=0;i<a.size();++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
