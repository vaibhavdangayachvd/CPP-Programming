#include<iostream>
#include<string>
#include<vector>
int main()
{
    std::vector<std::string> names;
    std::string temp;
    for(int i=0;i<3;++i)
    {
        std::cin>>temp;
        names.push_back(temp);
    }
    std::cout<<names[2];
    return 0;
}
