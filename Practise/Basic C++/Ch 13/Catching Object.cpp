#include<iostream>
#include<cstring>
using namespace std;
class error
{
    int id;
    char *desc;
public:
    error(const int &i,const char *d)
    {
        id=i;
        desc=new char[strlen(d)+1];
        strcpy(desc,d);
    }
    void display(void)
    {
        cout<<"Error No : "<<id<<endl<<"Description : "<<desc<<endl;
    }
};
int main()
{
    int i=5;
    try
    {
        if(i==5)
            throw error(1,"It is 5");
    }
    catch(error a)
    {
        a.display();
    }
    return 0;
}
