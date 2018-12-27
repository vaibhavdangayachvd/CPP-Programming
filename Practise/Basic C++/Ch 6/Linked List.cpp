#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
struct node
{
    int num;
    struct node *next;
};
typedef struct node node;
class linked
{
    node *head;
public:
    linked(void){head=NULL;}
    void ins(int num);
    void del(int num);
    void display(void);
    friend linked mer(linked list1,linked list2);
};
void linked::display(void)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->num<<" ";
        ptr=ptr->next;
    }
}
void linked::ins(int num)
{
    node *temp=new node;
    temp->num=num;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        return;
    }
    node *ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=temp;
    cout<<"\nInserted !!!";
}
void linked::del(int num)
{
    if(head==NULL)
    {
        cout<<"\nList is empty !!!";
        return;
    }
    node *ptr=head,*prev=NULL;
    while(ptr->num!=num)
    {
        prev=ptr;
        ptr=ptr->next;
        if(ptr==NULL)
            break;
    }
    if(ptr==NULL)
        cout<<"\nValue not found !!";
    else
    {
        if(prev==NULL)
            head=head->next;
        else
            prev->next=ptr->next;
         delete ptr;
         cout<<"\nDeleted !!";
    }
}
linked mer(linked list1,linked list2)
{
    linked list3;
    node *ptr;
    ptr=list1.head;
    while(ptr!=NULL)
    {
        list3.ins(ptr->num);
        ptr=ptr->next;
    }
    ptr=list2.head;
    while(ptr!=NULL)
    {
        list3.ins(ptr->num);
        ptr=ptr->next;
    }
    return list3;
}
int main()
{
    linked list1,list2,list3;
    list1.ins(1),list1.ins(2),list1.ins(3);
    list2.ins(4),list2.ins(5),list2.ins(6);
    list3=mer(list1,list2);
    list3.display();
    return 0;
}
