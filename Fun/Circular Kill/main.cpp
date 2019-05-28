#include<iostream>
int main()
{
    const int tot=9;
    int skip=2;
    int current=1;
    int init=1;
    while(current+skip<=tot)
    {
        while(current<=tot)
        {
            if(current+skip>tot)
            {
                if(skip-(tot-current)>init)
                    init+=skip;
                current=init;
                skip*=2;
                break;
            }
            current+=skip;
        }
    }
    std::cout<<"Answer is : "<<current;
    return 0;
}
