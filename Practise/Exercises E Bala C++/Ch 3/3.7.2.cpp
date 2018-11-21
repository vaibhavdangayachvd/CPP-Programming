#include<iostream>
#include<cmath>
#define ACCURACY 0.0001
using namespace std;
int main()
{
    float sum=0,term=1;
    int i=2;
    do
    {
        sum+=term;
        term=1/pow(i,i);
        i++;
    }
    while(term>ACCURACY);
    cout<<"Sum = "<<sum;
    return 0;
}
