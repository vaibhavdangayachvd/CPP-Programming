#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class books
{
    int success,failed;
    char** name;
    char** author;
    char** publisher;
    int *price;
    int *quantity;
    int num;
    void update_price(int);
public:
    books(void);
    int ser(char[],char[]);
    void buy(char[],char[],int);
};
books::books(void)
{
    num=4;
    success=failed=0;
    price=new int[80];
    quantity=new int[80];
    name=new char*[80];
    author=new char*[80];
    publisher=new char*[80];
    for(int i=0;i<num;++i)
    {
        name[i]=new char(80);
        author[i]=new char(80);
        publisher[i]=new char(80);
    }
    name[0]="Vaibhav";
    author[0]="Vaibhav";
    publisher[0]="Vaibhav";
    price[0]=100;
    quantity[0]=1000;

    name[1]="Harsh";
    author[1]="Harsh";
    publisher[1]="Harsh";
    price[1]=200;
    quantity[1]=2000;

    name[2]="Vishal";
    author[2]="Vishal";
    publisher[2]="Vishal";
    price[2]=300;
    quantity[3]=3000;

    name[3]="Sonali";
    author[3]="Sonali";
    publisher[3]="Sonali";
    price[3]=400;
    quantity[3]=4000;
}
int books::ser(char n[],char a[])
{
    for(int i=0;i<num;++i)
    {
        if(!strcmp(name[i],n) && !strcmp(author[i],a))
            return i;
    }
    return -999;
}
void books::buy(char n[],char a[],int q)
{
    int loc;
    if((loc=ser(n,a))==-999)
    {
        cout<<"\nWrong Input !!!";
        return;
    }
    if(q>quantity[loc])
    {
        cout<<"Order Size not available !!";
        ++failed;
        return;
    }
    cout<<"Price : "<<price[loc]<<endl<<"Quantity : "<<q<<endl<<"Total Amount = "<<price[loc]*q;
    quantity[loc]-=q;
    update_price(loc);
}
void books::update_price(int loc)
{
    price[loc]*=2;
    cout<<"\nUpdated Price : "<<price[loc];
    cout<<"\nUpdated Quantity : "<<quantity[loc];
}
int main()
{
    books store1;
    store1.buy("Vaibhav","Vaibhav",100);
    return 0;
}
