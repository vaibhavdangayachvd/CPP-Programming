#include<iostream>
#include<conio.h>
#define ACCURACY 0.00001
using namespace std;
int main()
{
    float x;
    cout<<"Enter Value of X : ";
    cin>>x;
    float term=x,sum=0;
    int i=2;
    do
    {
        sum+=term;
        term*= -(x*x)/(i*(i+1));
        i+=2;
    }
    while(unsigned(term)>ACCURACY);
    cout<<"Sum = "<<sum;
    return 0;
}
