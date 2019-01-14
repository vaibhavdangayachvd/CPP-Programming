#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &a);
int main()
{
    vector<int> vd;
    cout<<"Size : "<<vd.size()<<endl;
    cout<<"Enter 5 elements : ";
    for(int i=0;i<5;++i)
    {
        int x;
        cin>>x;
        vd.push_back(x);
    }
    cout<<"Vector : ";
    display(vd);
    cout<<"Size : "<<vd.size()<<endl;
    vector<int>::iterator itr = vd.begin();
    vd.insert(itr,1,0);
    vd.erase(vd.begin()+1,vd.begin()+3);
    display(vd);
    return 0;
}
void display(vector<int> &a)
{
    for(int i=0;i<a.size();++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
