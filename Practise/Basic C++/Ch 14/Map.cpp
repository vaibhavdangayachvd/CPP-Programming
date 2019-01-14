#include<iostream>
#include<map>
#include<string>
using namespace std;
typedef map<string,int> phonemap;
int main()
{
    string name;
    phonemap phone;
    int number;
    cout<<"Enter three set of name and number : "<<endl;
    for(int i=0;i<3;++i)
    {
        cin>>name>>number;
        phone[name]=number;
    }
    phone["Vaibhav"]=4;
    phone.insert(pair<string,int>("Harsh",7));
    int n=phone.size();
    cout<<"Size of map : "<<n<<endl;
    phonemap::iterator itr;
    for(itr=phone.begin();itr!=phone.end();++itr)
        cout<<(*itr).first<<" "<<(*itr).second<<endl;
    cout<<endl;
    cout<<"Enter Name : ";
    cin>>name;
    number=phone[name];
    cout<<"Number : "<<number<<endl;
    return 0;
}
