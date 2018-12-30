#include<iostream>
using namespace std;
class student
{
    int roll;
public:
    void set_roll(int r){roll=r;}
    int get_roll(void){return roll;}
};
class marks:virtual public student
{
protected:
    int maths,science;
public:
    void set_marks(int m,int s){maths=m,science=s;}
    void show_marks(void)
    {
        cout<<"Marks Maths : "<<maths<<endl;
        cout<<"Marks Science : "<<science<<endl;
    }
};
class sports:virtual public student
{
protected:
    int score;
public:
    void set_score(int s){score=s;}
    void show_score(void)
    {
        cout<<"Sports Weight : "<<score<<endl;
    }
};
class result:public sports,public marks
{
    int total;
public:
    void show_result(void)
    {
        total=maths+science+score;
        cout<<"Roll Number : "<<get_roll()<<endl;
        show_marks();
        show_score();
        cout<<"Total = "<<total<<endl;
    }
};
int main()
{
    result s1;
    s1.set_roll(1);
    s1.set_marks(10,10);
    s1.set_score(10);
    s1.show_result();
    return 0;
}
