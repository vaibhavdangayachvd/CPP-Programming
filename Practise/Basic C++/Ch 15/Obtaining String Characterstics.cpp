#include<iostream>
#include<string>
using namespace std;
void display(string &str)
{
    cout<<"Size : "<<str.size()<<endl;
    cout<<"Length : "<<str.length()<<endl;
    cout<<"Capacity : "<<str.capacity()<<endl;
    cout<<"Maximum Size : "<<str.max_size()<<endl;
    cout<<"Empty : "<<(str.empty()?"Yes":"No")<<endl<<endl;
}
int main()
{
    string str;
    cout<<"Initial Status :- "<<endl;
    display(str);
    cout<<"Enter a string : ";
    cin>>str;
    cout<<"Status Now :-"<<endl;
    display(str);
    str.resize(30);
    cout<<"Status After resizing :-"<<endl;
    display(str);
    return 0;
}
