#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
inline int area(int side){return side*side;}
inline int area(int len,int bred){return len*bred;}
inline float area(float rad){return 3.14*rad*rad;}
inline void hold(void){cout<<"\n\n\tPress Enter to exit...";getch();}
int main()
{
    while(1)
    {
        system("cls");
        cout<<"Choose Option :-\n\n1 - Area of circle\n2 - Area of rectangle\n3 - Area of square\n\n\tBackspace - Exit\n";
        char option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            float rad;
            cout<<"Enter Radius : ";
            cin>>rad;
            cout<<"Area of circle is : "<<area(rad);
            hold();
            break;
        case '2':
            int len,bred;
            cout<<"Enter len,bred : ";
            cin>>len>>bred;
            cout<<"Area of rectangle is : "<<area(len,bred);
            hold();
            break;
        case '3':
            int side;
            cout<<"Enter Side : ";
            cin>>side;
            cout<<"Area of sq is : "<<area(side);
            hold();
            break;
        case 8:
            return 0;
        }
    }
}
