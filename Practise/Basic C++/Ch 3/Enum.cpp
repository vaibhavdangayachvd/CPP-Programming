#include<iostream>
using namespace std;
int main()
{
    enum {red,yellow,green};
    int light;
    cout<<"Enter current light code(0 Red,1 Yellow,2 Green) : ";
    cin>>light;
    switch(light)
    {
    case red:
        cout<<"You have to stop";
        break;
    case yellow:
        cout<<"You have to wait";
        break;
    case green:
        cout<<"You have to move";
        break;
    default:
        cout<<"Wrong Input !!";
    }
    return 0;
}
