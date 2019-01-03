#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream fout("Paragraph.txt");
    char para[300],ch;
    int flag=0;
    cout<<"Enter Paragraph : ";
    cin.getline(para,300);
    fout<<para;
    fout.close();
    ifstream fin("Paragraph.txt");
    fout.open("Paragraph-Updated.txt");
    while(!fin.eof())
    {
        ch=fin.get();
        if(ch==' ' && flag==1)
            continue;
        else
        {
            flag=0;
            if(ch==' ')
                flag=1;
            fout.put(ch);
        }
    }
    fout.close();
    fin.close();
    fin.open("Paragraph-Updated.txt");
    while(!fin.fail())
    {
        ch=fin.get();
        cout<<ch;
    }
    if(fin.eof())
        cout<<"Ended";
    fin.close();
    return 0;
}
