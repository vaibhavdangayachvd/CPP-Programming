#include<iostream>
using namespace std;
class person
{
    string name;
    int age;
public:
    person(string n,int a){name=n,age=a;};
    void display(void){cout<<"Name : "<<name<<endl<<"Age : "<<age<<endl;}
    person& greater_(person &p1);
};
person& person::greater_(person &p1)
{
    if(p1.age>age)
        return p1;
    else
        return *this;
}
int main()
{
    person p1("Vaibhav",20),p2("Harsh",17);
    person &p3=p1.greater_(p2);
    p3.display();
    return 0;
}
