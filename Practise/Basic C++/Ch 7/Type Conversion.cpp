#include<iostream>
using namespace std;
class invent1
{
    int code;
    int items;
    float price;
public:
    invent1(int a,int b,float c)
    {
        code=a,items=b,price=c;
    }
    void putdata(void)
    {
        cout<<"Code : "<<code<<endl;
        cout<<"Items : "<<items<<endl;
        cout<<"Value : "<<price<<endl;
    }
    int getcode(void){return code;}
    int getitems(void){return items;}
    float getprice(void){return price;}
    operator float(void){return(items*price);}
    /*
    operator invent2(void)
    {
        invent2 temp;
        temp.code=code;
        temp.value=price*items;
        return temp;
    }*/
};
class invent2
{
    int code;
    float value;
public:
    invent2(void){code=0,value=0;}
    invent2(int x,float y){code=x,value=y;}
    void putdata(void)
    {
        cout<<"Code : "<<code<<endl;
        cout<<"Value : "<<value<<endl;
    }
    invent2(invent1 p)
    {
        code=p.getcode();
        value=p.getitems()*p.getprice();
    }
};
int main()
{
    invent1 s1(100,5,140.0);
    invent2 d1;
    float total_value;
    total_value=s1;
    d1=s1;
    cout<<"Product Details :invent 1 type"<<endl;
    s1.putdata();
    cout<<"Stock Value"<<endl<<"Value = "<<total_value<<endl<<endl;
    cout<<"Product Details Invent 2 Type"<<endl;
    d1.putdata();
    return 0;
}
