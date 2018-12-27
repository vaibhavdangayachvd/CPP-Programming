#include<iostream>
#include<cstring>
using namespace std;
class myString
{
    char *ch;
public:
    myString(){ch=0;}//Default Constructor
    myString(const char *c);//Type Conversion Function
    myString(const myString &c);//Copy Constructor
    operator=(const myString &c);//Overload = copy constructor
    friend istream&operator>>(istream &din,myString &c);//Overloaded >>
    friend ostream&operator<<(ostream &dout,const myString &c);//Overloaded<<
    int operator==(const myString &c);//Overloaded ==
    ~myString(void){delete ch;}//Destructor
};
myString::myString(const char *c)
{
    delete(ch);
    ch=new char[strlen(c)+1];
    strcpy(ch,c);
}
myString::myString(const myString &c)
{
    delete(ch);
    ch=new char[strlen(c.ch)+1];
    strcpy(ch,c.ch);
}
myString::operator=(const myString &c)
{
    delete(ch);
    ch=new char[strlen(c.ch)+1];
    strcpy(ch,c.ch);
}
int myString::operator==(const myString &c)
{
    if(ch==NULL || c.ch==NULL)
        return 0;
    if(!(strcmp(ch,c.ch)))
        return 1;
    else
        return 0;
}
istream&operator>>(istream &din,myString &c)
{
    char ch[30];
    din>>ch;
    c.ch=new char[strlen(ch)+1];
    strcpy(c.ch,ch);
    return din;
}
ostream&operator<<(ostream &dout,const myString &c)
{
    dout<<c.ch;
    return dout;
}
int main()
{
    myString p1,p2;
    cout<<"Enter String 1 : ";
    cin>>p1;
    cout<<"Enter String 2 : ";
    cin>>p2;
    if(p1==p2)
        cout<<p1<<" = "<<p2<<endl;
    else
        cout<<p1<<" != "<<p2<<endl;
    return 0;
}
