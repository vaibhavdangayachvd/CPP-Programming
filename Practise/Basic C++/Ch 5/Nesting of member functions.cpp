#include<iostream>
#include<string>
using namespace std;
class binary
{
private:
    string num;
    int check(void);
    void display(void);
    void convert(void);
public:
    void get_complement(void);
};
void binary::get_complement(void)
{
    cout<<"Enter a binary number : ";
    cin>>num;
    if(check())
    {
        convert();
        display();
    }
    else
        cout<<"\nNumber is not binary !!!\n";
}
int binary::check(void)
{
    for(int i=0;i<num.length();++i)
    {
        if(num.at(i)!='0' && num.at(i)!='1')
            return 0;
    }
    return 1;
}
void binary::convert(void)
{
    for(int i=0;i<num.length();++i)
    {
        if(num.at(i)=='0')
            num.at(i)='1';
        else
            num.at(i)='0';
    }
}
inline void binary::display(void){cout<<"\nOnes Complement is : "<<num<<endl;}
int main()
{
    binary num;
    num.get_complement();
    return 0;
}
