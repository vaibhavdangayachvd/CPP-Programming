#include<iostream>
#include<cstring>
using namespace std;
class strings
{
    char*str;
    int len;
public:
    strings(){len=0,str=0;}
    strings(const char *s);
    strings(const strings &s);
    void operator=(const strings &s);
    ~strings(){delete str;}
    friend strings operator+(const strings &a,const strings &b);
    friend istream& operator>>(istream &din,strings &s);
    friend ostream& operator<<(ostream &dout,strings &s);
};
strings::strings(const char *s)
{
    len=strlen(s);
    str=new char[len+1];
    strcpy(str,s);
}
strings::strings(const strings &s)
{
    len=s.len;
    str=new char[len+1];
    strcpy(str,s.str);
}
void strings::operator=(const strings &s)
{
    len=s.len;
    str=new char[len+1];
    strcpy(str,s.str);
}
strings operator+(const strings &a,const strings &b)
{
    strings temp;
    temp.len=(a.len+b.len+1);
    temp.str=new char[temp.len+1];
    strcpy(temp.str,a.str);
    strcat(temp.str," ");
    strcat(temp.str,b.str);
    return temp;
}
istream& operator>>(istream &din,strings &s)
{
    char name[30];
    din>>name;
    delete s.str;
    s.len=strlen(name);
    s.str=new char[s.len+1];
    strcpy(s.str,name);
    return din;
}
ostream& operator<<(ostream &dout,strings &s)
{
    dout<<s.str;
    return dout;
}
int main()
{
    strings first="Vaibhav",last="Dangayach",full;
    full=first+last;
    cout<<full<<endl;
    return 0;
}
