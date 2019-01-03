#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class student
{
    int roll;
    string name;
public:
    student(void);
    void display(void);
};
student::student(void)
{
    cout<<"Enter Roll Number : ";
    cin>>roll;
    cout<<"Enter Name : ";
    cin>>name;
}
void student::display(void)
{
    cout<<setiosflags(ios::left);
    cout<<setw(8)<<"Name";
    cout<<setw(2)<<":";
    cout<<setw(10)<<name<<endl;
    cout<<setw(8)<<"Roll No";
    cout<<setw(2)<<":";
    cout<<setw(10)<<roll<<endl;
    cout<<resetiosflags(ios::left);
}
int main()
{
    student st[4];
    int last;
    fstream fp;
    fp.open("Student.dll",fstream::out);
    for(int i=0;i<4;++i)
        fp.write((char*)&st[i],sizeof(st));
    fp.seekp(0,ios::end);
    last=fp.tellp();
    fp.close();
    cout<<"Number of Objects Stored : "<<last/sizeof(st);
    return 0;
}
