#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin;
    ofstream fout;
    char line[80];
    fout.open("Items.txt");
    fout<<"My name is Vaibhav"<<endl<<"I am awesome";
    fout.close();
    fin.open("Items.txt");
    while(1)
    {
        if(fin.eof())
            break;
        fin.getline(line,80);
        cout<<line<<endl;
    }
    fin.close();
    return 0;
}
