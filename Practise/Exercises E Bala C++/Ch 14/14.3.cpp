#include<iostream>
#include<cstring>
#include<list>
using namespace std;
class student
{
    int roll;
    char *name;
public:
    student(const int &r,const char *n)
    {
        roll=r;
        name=new char[strlen(n)+1];
        strcpy(name,n);
    }
    void display(void)
    {
        cout<<"Name : "<<name<<endl<<"Roll : "<<roll<<endl;
    }
    int get_detail(int r)
    {
        if(r==roll)
            return 1;
        else
            return 0;
    }
    int get_detail(char *str)
    {
        if(!strcmp(name,str))
            return 1;
        else
            return 0;
    }
};
int main()
{
    student st[2]={student(5,"Vaibhav"),student(3,"VD")};
    list<student> vd;
    for(int i=0;i<5;++i)
        vd.push_back(st[i]);
    list<student>::iterator itr;
    for(itr=vd.begin();itr!=vd.end();++itr)
    {
        if(itr->get_detail("Vaibhav"))
        {
            itr->display();
            break;
        }
    }
    return 0;
}
