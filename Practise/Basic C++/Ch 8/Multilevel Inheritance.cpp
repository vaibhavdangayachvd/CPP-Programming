#include<iostream>
using namespace std;
class student
{
protected:
    int roll;
public:
    void set_roll(int n=0){roll=n;}
    int get_roll(void){return roll;}
};
class marks:public student
{
protected :
    int sc;
    int mt;
public:
    void set_marks(int s,int m){sc=s,mt=m;}
    void put_marks(void)
    {
        cout<<"Marks science : "<<sc<<endl<<"Marks Maths : "<<mt<<endl;
    }
};
class result:public marks
{
    int result;
public:
    void display(void)
    {
        result=mt+sc;
        put_marks();
        cout<<"Result : "<<result<<endl;
    }
};
int main()
{
    result s1;
    s1.set_roll(3);
    s1.set_marks(4,10);
    s1.display();
    return 0;
}
