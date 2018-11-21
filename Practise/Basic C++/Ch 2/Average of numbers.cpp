#include<iostream>
using namespace std;
int main()
{
    float num1,num2,average,sum;
    /*
    cout<<"Enter number 1 : ";
    cin>>num1;
    cout<<"Enter number 2 : ";
    cin>>num2;
    */
    cout<<"Enter number1 and number 2 : ";
    cin>>num1>>num2;
    average=(num1+num2)/2;
    sum=num1+num2;
    cout<<"\nAverage is "<<average<<"\n"
    <<"Sum is "<<sum<<"\n";
    return 0;
}
