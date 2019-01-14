#include<iostream>
#include<cstring>
#include<set>
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
    void display(void)const
    {
        cout<<"Name : "<<name<<endl<<"Roll : "<<roll<<endl;
    }
    int get_detail(const int &r)const
    {
        if(r==roll)
            return 1;
        else
            return 0;
    }
    int get_detail(const char *str)const
    {
        if(!strcmp(name,str))
            return 1;
        else
            return 0;
    }
    bool operator<(const student& st) const
    {
        return (roll<st.roll);
    }
};
int main()
{
    student st[2]={student(5,"Vaibhav"),student(3,"VD")};
    set<student> vd;
    for(int i=0;i<2;++i)
        vd.insert(st[i]);
    set<student>::iterator itr;
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
