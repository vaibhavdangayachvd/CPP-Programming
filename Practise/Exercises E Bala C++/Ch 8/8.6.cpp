#include<iostream>
using namespace std;
class staff
{
    static int count_;
protected:
    int code;
    string name;
public:
    staff(const string &name);
    void show_name(void);
    void show_code(void);
};
int staff::count_;
staff::staff(const string &n)
{
    name=n;
    code=++count_;
}
void staff::show_name(void)
{
    cout<<"Name : "<<name<<endl;
}
void staff::show_code(void)
{
    cout<<"Code : "<<code<<endl;
}
class teacher
{
    string subject;
    string publication;
    staff t;
public:
    teacher(const string &n,const string &s,const string &p):t(n),subject(s),publication(p){}
    void show_subject(void);
    void show_publication(void);
    friend ostream& operator<<(ostream &dout,teacher &t);
};
void teacher::show_subject(void)
{
    cout<<"Subject : "<<subject<<endl;
}
void teacher::show_publication(void)
{
    cout<<"Publication : "<<publication<<endl;
}
ostream& operator<<(ostream &dout,teacher &t)
{
    t.t.show_name();
    t.t.show_code();
    t.show_subject();
    t.show_publication();
    return dout;
}
class officer
{
    string grade;
    staff o;
public:
    officer(const string &n,const string &g):o(n),grade(g){}
    void show_grade(void);
    friend ostream& operator<<(ostream &dout,officer &o);
};
void officer::show_grade(void)
{
    cout<<"Grade : "<<grade<<endl;
}
ostream& operator<<(ostream &dout,officer &o)
{
    o.o.show_name();
    o.o.show_code();
    o.show_grade();
    return dout;
}
class typist
{
protected:
    int speed;
    staff t;
public:
    typist(const string &n,const int &s);
    void show_speed(void);

};
typist::typist(const string &n,const int &s):t(n),speed(s){}
void typist::show_speed(void)
{
    cout<<"Speed : "<<speed<<endl;
}
class regular:public typist
{
    int salary;
public:
    regular(const string &n,const int &sp,const int &sa):typist(n,sp),salary(sa){}
    void show_salary(void);
    friend ostream& operator<<(ostream &dout,regular &r);
} ;
void regular::show_salary(void)
{
    cout<<"Salary : "<<salary<<endl;
}
ostream& operator<<(ostream &dout,regular &s)
{
    s.t.show_name();
    s.t.show_code();
    s.show_speed();
    s.show_salary();
    return dout;
}
class casual:public typist
{
    int daily_wage;
public:
    casual(const string &n,const int &s,const int &w):typist(n,s),daily_wage(w){}
    void show_daily_wage(void);
    friend ostream& operator<<(ostream &dout,casual &c);
};
void casual::show_daily_wage(void)
{
    cout<<"Daily Wage : "<<daily_wage<<endl;
}
ostream& operator<<(ostream &dout,casual &c)
{
    c.t.show_name();
    c.t.show_code();
    c.show_speed();
    c.show_daily_wage();
    return dout;
}
int main()
{

    teacher teacher1("Vaibhav","C++","BPB Publications");
    officer officer1("Pawan","Commander");
    regular regular1("Harsh",100,10000);
    casual casual1("Vishal",80,1000);
    cout<<teacher1<<endl;
    cout<<officer1<<endl;
    cout<<regular1<<endl;
    cout<<casual1<<endl;
}
