#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;
class books
{
    int _count;
    char **name;
    int *code;
    float *cost;
public:
    books(void);
    void show(void);
    ~books();
};
void books::show(void)
{
    cout.fill('-');
    cout<<setiosflags(ios::left);
    cout<<setw(15)<<"Name"<<setw(10)<<"Code";
    cout<<resetiosflags(ios::left);
    cout<<setiosflags(ios::right);
    cout<<setw(8)<<"Cost"<<endl<<endl;
    cout<<resetiosflags(ios::right);
    for(int i=0;i<_count;++i)
    {
        cout<<setiosflags(ios::left);
        cout<<setw(15)<<name[i];
        cout<<setw(10)<<code[i];
        cout<<resetiosflags(ios::left);
        cout<<setiosflags(ios::showpoint);
        cout<<setiosflags(ios::fixed);
        cout<<setw(8)<<setprecision(2)<<cost[i]<<endl;
        cout<<resetiosflags(ios::fixed);
        cout<<resetiosflags(ios::showpoint);
    }
    cout.fill(' ');
}
books::books(void)
{
    name=new char*[80];
    code=new int[80];
    cost=new float[80];
    char tname[20];
    cout<<"Enter number of books you want do add : ";
    cin>>_count;
    cout<<endl;
    for(int i=0;i<_count;++i)
    {
        cout<<"Enter book["<<i+1<<"] name : ";
        cin.sync();
        cin.getline(tname,20);
        name[i]=new char[strlen(tname)+1];
        strcpy(name[i],tname);
        cout<<"Enter book["<<i+1<<"] code : ";
        cin>>code[i];
        cout<<"Enter book["<<i+1<<"] price : ";
        cin>>cost[i];
        cout<<endl;
    }
}
books::~books()
{
    for(int i=0;i<_count;++i)
        delete name[i];
    delete name,cost,code;
}
int main()
{
    books b;
    b.show();
    return 0;
}
