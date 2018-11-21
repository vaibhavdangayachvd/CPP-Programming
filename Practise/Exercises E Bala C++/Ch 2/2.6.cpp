#include<iostream>
using namespace std;
class temp
{
private:
    int sel;
    int fer;
public:
    void convert(void);
};
void temp::convert(void)
{
    cout<<"Enter temp in fer : ";
    cin>>fer;
    sel=(fer-32)*5/9;
    cout<<"Temp in sel : "<<sel;
}
int main()
{
    temp mon;
    cout<<mon.fer;
    mon.convert();
    return 0;
}
