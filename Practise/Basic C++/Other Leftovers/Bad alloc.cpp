#include<iostream>
using namespace std;
int main()
{
    int *a;
    if((a=new int[100000000000])==0)
        cout<<"Hi";
    return 0;
}
