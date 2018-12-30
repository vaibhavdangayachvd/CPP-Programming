#include<iostream>
using namespace std;
class medical_record
{
protected:
    int policy_num;
    int limit;
public:
    void set_medical_record(const int &n,const int &l);
    void show_medical_record(void) const;
};
void medical_record::set_medical_record(const int &n,const int &l)
{
    policy_num=n;
    limit=l;
}
void medical_record::show_medical_record(void) const
{
    cout<<"Policy Number : "<<policy_num<<endl;
    cout<<"Claim Limit : "<<limit<<endl;
}
class person
{
protected:
    string name;
    int age;
public:
    void show_details(void) const;
    void set_details(const string &n,const int &a);
};
void person::show_details(void) const
{
    cout<<"Name : "<<name<<endl;
    cout<<"Age : "<<age<<endl;
}
void person::set_details(const string &n,const int &a)
{
    name=n;
    age=a;
}
class patient:public person,public medical_record
{
protected:
    int id;
public:
    void show_patient_details(void) const;
    void add_patient(const string &n,const int &a,const int &i);
};
void patient::show_patient_details(void) const
{
    cout<<"Patient Name : "<<name<<endl;
    cout<<"Patient Age : "<<age<<endl;
    cout<<"Patient ID : "<<id<<endl;
}
void patient::add_patient(const string &n,const int &a,const int &i)
{
    set_details(n,a);
    id=i;
}
class hospital:public patient
{
    string name;
public:
    hospital(const string &n){name=n;}
    void show_name(void)const{cout<<"Hospital Name : "<<name<<endl;}
};
int main()
{
    hospital h1("Maladevi");
    h1.add_patient("Vaibhav",19,1);
    h1.set_medical_record(101,10000);
    h1.show_patient_details();
    return 0;
}
