#include<iostream>
using namespace std;
int main()
{
    int num1,num2;
    cout<<"Enter num1 and num2 : ";
    cin>>num1>>num2;
    if(num1>num2)
        cout<<"Greater number is "<<num1;
    else if(num2>num1)
        cout<<"Greater number is "<<num2;
    else
        cout<<"Both are equal";
    return 0;
}
