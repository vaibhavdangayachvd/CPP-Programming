#include<iostream>
#include<cstring>
using namespace std;
class first
{
protected:
    char *fir;
public:
    first(char *f);
    virtual ~first(){cout<<"base dest"<<endl;delete fir;}
    virtual void show(void)=0;
};
first::first(char *f)
{
    fir=new char[strlen(f)+1];
    strcpy(fir,f);
}
class last:public first
{
    char *las;
public:
    last(char *f,char *l);
    void show(void){cout<<"Name : "<<fir<<" "<<las<<endl;}
    ~last(){cout<<"derived dest"<<endl;delete las;}
};
last::last(char *f,char *l):first(f)
{
      las=new char[strlen(l)+1];
      strcpy(las,l);
}
int main()
{
    char f[20]="Vaibhav";
    char l[20]="Dangayach";
    first *ptr=new last(f,l);
    ptr->show();
    delete ptr;
}
