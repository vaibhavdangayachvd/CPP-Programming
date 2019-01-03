#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
    char str[80];
    int lines=0,ch=0,words=0;
    char c;
    ofstream fout("Paragraph.txt");
    cout<<"Enter paragraph(~)to end  :- "<<endl<<"Line(1)->";
    while((c=cin.get())!='~')
    {
        if(c==' ')
            words++;
        else if(c=='\n')
        {
            ++lines;
            cout<<"Line("<<lines+1<<")->";
        }
        else if(c!='~')
            ++ch;
        fout<<c;
    }
    fout.close();
    if(ch)
       ++words,++lines;
    cout<<endl<<setiosflags(ios::left);
    cout<<setw(10)<<"Lines";
    cout<<setw(6)<<":";
    cout<<resetiosflags(ios::left);
    cout<<setw(4)<<lines<<endl;
    cout<<setiosflags(ios::left);
    cout<<setw(10)<<"Words";
    cout<<setw(6)<<":";
    cout<<resetiosflags(ios::left);
    cout<<setw(4)<<words<<endl;
    cout<<setiosflags(ios::left);
    cout<<setw(10)<<"Ch";
    cout<<setw(6)<<":";
    cout<<resetiosflags(ios::left);
    cout<<setw(4)<<ch<<endl;
    return 0;
}
