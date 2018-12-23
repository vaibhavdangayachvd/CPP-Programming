#include<iostream>
using namespace std;
class matrix
{
private:
    int mat[30][30];
    int row,col;
public:
    void create(void);
    void display(void);
    friend matrix mul(matrix m1,matrix m2);
};
void matrix::create(void)
{
    cout<<"Enter order of matrix : ";
    cin>>row>>col;
    cout<<"Enter element row wise :-\n";
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            cin>>mat[i][j];
    cout<<"Matrix Created !!\n";
}
void matrix::display(void)
{
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}
matrix mul(matrix m1,matrix m2)
{
    matrix m3;
    if(m1.col!=m2.row)
    {
        cout<<"Cant Multiply These Matrix !!\n";
        return m3;
    }
    m3.row=m1.row;
    m3.col=m2.col;
    for(int i=0;i<m1.row;++i)
    {
        for(int j=0;j<m2.col;++j)
        {
            int sum=0;
            for(int k=0;k<m1.col;++k)
                sum+=m1.mat[i][k]*m2.mat[k][j];
            m3.mat[i][j]=sum;
        }
    }
}
int main()
{
    matrix m1,m2,m3;
    m1.create();
    m2.create();
    m3=mul(m1,m2);
    m3.display();
    return 0;
}
