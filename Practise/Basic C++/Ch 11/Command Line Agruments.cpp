#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char *argv[])
{
    ofstream fout("Students.txt");
    for(int i=1;i<argc;++i)
        fout<<argv[i]<<endl;
    fout.close();
    return 0;
}
