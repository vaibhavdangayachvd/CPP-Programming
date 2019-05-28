#include<iostream>
#include<fstream>
#include<iomanip>
int main()
{
    const float rate=1.25;
    double amount=113000;
    int step=6800;
    std::ofstream outf("Output3");
    int count=0;
    double tot=0;
    while(amount>0)
    {
        outf<<std::setw(2)<<++count<<" "<<std::setw(10)<<amount<<" ";
        double interest=(rate/100)*amount;
        tot+=interest;
        if(amount-(step-interest)<0)
        {
            outf<<std::setw(10)<<interest<<" "<<std::setw(10)<<amount+interest<<std::endl;
            outf<<tot;
            break;
        }
        amount-=(step-interest);
        outf<<std::setw(10)<<interest<<" "<<std::setw(10)<<step-interest<<std::endl;
    }
    outf.close();
    return 0;
}
