#include<iostream>
#include<iomanip>
std::ostream &space(std::ostream &dout)
{
    dout<<"  ";
    return dout;
}
class pascle
{
    int arr[20][20];
    int size;
public:
    void set(int sz);
    void display(void);
};
void pascle::set(int sz)
{
    size=sz;
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<=i;++j)
        {
            if(j==0 || j==i)
                arr[i][j]=1;
            else
                arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
    }
}
void pascle::display(void)
{
    for(int i=0;i<size;++i)
    {
        for(int k=0;k<size-1-i;++k)
            std::cout<<space;
        for(int j=0;j<=i;++j)
            std::cout<<std::setw(2)<<arr[i][j]<<space;
        std::cout<<std::endl;
    }
}
int main()
{
    pascle p1;
    std::cout<<"Enter size : ";
    int size;
    std::cin>>size;
    p1.set(size);
    p1.display();
    return 0;
}
