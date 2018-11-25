#include<iostream>
using namespace std;
inline float area(float rad,float pie){return pie*rad*rad;}
inline float area(float rad){return 3.14*rad*rad;}
int main()
{
    float rad=5.0;
    cout<<area(rad,3.14)<<endl;
    cout<<area(rad);
    return 0;
}
