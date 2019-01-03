#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char me[40];
    ofstream fout("myFile.txt");
    fout<<"My Name is Vaibhav";
    fout.close();
    ifstream fin("myFile.txt");
    while(fin)
    {
        fin.getline(me,80);
        cout<<me;
    }
    fin.close();
    return 0;
}
