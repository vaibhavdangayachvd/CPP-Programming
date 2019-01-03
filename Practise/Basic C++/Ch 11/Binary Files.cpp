#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int height[10]={1,2,3,4,5,6,7,8,9,10};
    int haha[133];
    fstream fp;
    fp.open("Binary.txt",fstream::out);
    fp.close();
    fp.open("Binary.txt",ios::out|ios::in);
    fp.write((char*)&height,sizeof(height));
    fp.seekg(0);
    for(int i=0;i<10;++i)
        height[i]=0;
    fp.read((char*)&haha,sizeof(haha));
    for(int i=0;i<10;++i)
        cout<<haha[i]<<endl;
    return 0;
}
