#include<iostream>
using namespace std;
class staff
{
    static int count_;
protected:
    int code;
    string name;
public:
    staff(const string name);
    void show_name(void);
    void show_code(void);
};
int staff::count_;
staff::staff(const string n)
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
class education
{
protected:
    string degree;
    int percentage;
public:
    education(const string &d="Unknown",const int &p = 0):degree(d),percentage(p){}
    void set_education(string d,int p);
    void show_education(void);
};
void education::set_education(string d,int p)
{
    degree=d;
    percentage=p;
}
void education::show_education(void)
{
    cout<<"Educational Qualification :-"<<endl<<"\t";
    cout<<"Degree : "<<degree<<endl<<"\t";
    cout<<"Percentage : "<<percentage<<endl;
}
class teacher:public staff,public education
{
    string subject;
    string publication;
public:
    teacher(const string &n,const string &s,const string &p):staff(n),education(),subject(s),publication(p){}
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
    t.show_name();
    t.show_code();
    t.show_education();
    t.show_subject();
    t.show_publication();
    return dout;
}
class officer:public staff,public education
{
    string grade;
public:
    officer(const string &n,const string &g):education(),staff(n),grade(g){}
    void show_grade(void);
    friend ostream& operator<<(ostream &dout,officer &o);
};
void officer::show_grade(void)
{
    cout<<"Grade : "<<grade<<endl;
}
ostream& operator<<(ostream &dout,officer &o)
{
    o.show_name();
    o.show_code();
    o.show_education();
    o.show_grade();
    return dout;
}
class typist:public staff
{
protected:
    int speed;
public:
    typist(const string &n,const int &s);
    void show_speed(void);

};
typist::typist(const string &n,const int &s):staff(n),speed(s){}
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
    s.show_name();
    s.show_code();
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
    c.show_name();
    c.show_code();
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
    teacher1.set_education("BCA",80);
    officer1.set_education("MCA",92);
    cout<<teacher1<<endl;
    cout<<officer1<<endl;
    cout<<regular1<<endl;
    cout<<casual1<<endl;
}
