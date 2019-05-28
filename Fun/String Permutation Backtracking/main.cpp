#include<iostream>
#include<string>
void swap_char(std::string &s,int beg,int last)
{
    char a;
    a=s[beg];
    s[beg]=s[last];
    s[last]=a;
}
void permute(std::string s,int beg=0)
{
    if(beg==s.length()-1)
    {
        std::cout<<s<<std::endl;
        return;
    }
    for(int i=beg;i<s.length();++i)
    {
        swap_char(s,beg,i);
        permute(s,beg+1);
        swap_char(s,i,beg);
    }
}
int main()
{
    permute("ABC");
    return 0;
}
