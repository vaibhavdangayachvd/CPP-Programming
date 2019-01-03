#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class student
{
    int roll;
    string name;
public:
    void display(void);
    void getdata(void);
};
void student::getdata(void)
{
    cout<<"Enter Name : ";
    cin>>name;
    cout<<"Enter Roll Number : ";
    cin>>roll;
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
    student item[3];
    student temp;
    int num;
    fstream fp;
    fp.open("Student.txt",fstream::out);
    fp.close();
    fp.open("Student.txt",ios::ate|ios::binary|ios::out|ios::in);
    //Read Data
    fp.seekp(0);
    for(int i=0;i<3;++i)
    {
        item[i].getdata();
        char ch;
        cin.get(ch);
        fp.write((char*)&item[i],sizeof(item[i]));
    }
    //Display current Data
    fp.seekg(0);
    while(fp.read((char*)&temp,sizeof(temp)))
        temp.display();
    fp.clear();
    //Add New Item to end
    cout<<"Add To New Item :-\n";
    temp.getdata();
    char ch;
    cin.get(ch);
    fp.write((char*)&temp,sizeof(temp))<<flush;
    //Display Current Position of file
    fp.seekg(0);
    while(fp.read((char*)&temp,sizeof(temp)))
        temp.display();
    //Append new item
    cout<<"Enter Object Number to update : ";
    cin>>num;
    cin.get(ch);
    num=(num-1)*sizeof(temp);
    if(fp.eof())
        fp.clear();
    fp.seekp(num);
    temp.getdata();
    cin.get(ch);
    fp.write((char*)&temp,sizeof(temp))<<flush;
    //Updated File
    fp.seekg(0);
    while(fp.read((char*)&temp,sizeof(temp)))
        temp.display();
    //Close File
    fp.close();
    return 0;
}
