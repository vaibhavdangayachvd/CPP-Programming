#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
const int m=50;
class cart
{
private:
    int product_count;
    int price[m];
    int batch[m];
public:
    void init_count(void){product_count=0;}
    void add_item(void);
    void rem_item(void);
    void display_cart(void);
    void display_bill(void);
};
void cart::add_item(void)
{
    int i;
    for(i=0;i<product_count;++i)
    {
        if(!price[i])
            break;
    }
    cout<<"Enter Batch No : ";
    cin>>batch[i];
    cout<<"Enter Price : ";
    cin>>price[i];
    if(i==product_count)
        ++product_count;
    cout<<"\nItem Added to cart!!";
}
void cart::rem_item(void)
{
    int batch_no;
    cout<<"Enter batch_no to delete : ";
    cin>>batch_no;
    int i;
    for(i=0;i<product_count;++i)
    {
        if(batch[i]==batch_no)
        {
            batch[i]=0;
            price[i]=0;
            break;
        }
    }
    if(i==product_count)
        cout<<"\nItem not found !!";
    else
        cout<<"\nItem Removed from Cart !!";
}
void cart::display_cart(void)
{
    for(int i=0;i<product_count;++i)
        if(batch[i])
            cout<<"Batch No : "<<batch[i]<<" Price : "<<price[i]<<endl;
}
void cart::display_bill(void)
{
    int sum=0;
    for(int i=0;i<product_count;++i)
        sum+=price[i];
    cout<<"Total Bill = "<<sum<<endl;
}
void hold(void)
{
    cout<<"\n\n\tPress Enter to continue...";
    getch();
}
int main()
{
    char option;
    cart c1;
    c1.init_count();
    while(1)
    {
        system("cls");
        cout<<"Choose Option\n\n1 - Add to cart\n";
        cout<<"2 - Rem from cart\n";
        cout<<"3 - Display Cart\n";
        cout<<"4 - Generate Bill\n\n\t";
        cout<<"Backspace - Exit\n";
        option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            c1.add_item();
            hold();
            break;
        case '2':
            c1.rem_item();
            hold();
            break;
        case '3':
            c1.display_cart();
            hold();
            break;
        case '4':
            c1.display_bill();
            hold();
            break;
        case 8:
            return 0;
        }
    }
}
