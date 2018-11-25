#include<iostream>
using namespace std;
void area(int radius,float pie=3.14);
int main()
{
    int rad=5;
    area(rad);
    return 0;
}
void area(int r,float pie)
{
    cout<<pie*r*r;
}
