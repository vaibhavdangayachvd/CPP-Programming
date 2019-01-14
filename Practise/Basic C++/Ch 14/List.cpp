#include<iostream>
#include<list>
#include<cstdlib>
using namespace std;
void display(list<int> &a);
int main()
{
    list<int> vd;
    list<int> hd(5);
    for(int i=0;i<5;++i)
        vd.push_back(i+1);
    list<int>::iterator itr;
    for(itr=hd.begin();itr!=hd.end();++itr)
        cin>>*itr;
    hd.sort();
    vd.merge(hd);
    display(vd);
    return 0;
}
void display(list<int> &a)
{
    list<int>::iterator itr;
    for(itr=a.begin();itr!=a.end();++itr)
        cout<<*itr<<" ";
    cout<<endl;
}
