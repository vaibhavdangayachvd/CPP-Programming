#include<iostream>
using namespace std;
class bca
{
private:
    int roll;
    string name;
public:
    bca(int roll,string name);
    void display(void);
};
bca::bca(int r,string n)
{
    roll=r;
    name=n;
}
inline void bca::display(void)
{
    cout<<"Roll Number : "<<roll<<"\nName : "<<name;
}
int main()
{
    bca a(1,"Vaibhav");
    a.display();
    return 0;
}
