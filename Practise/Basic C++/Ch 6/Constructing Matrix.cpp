#include<iostream>
using namespace std;
class matrix
{
    int **mat;
    int row,col;
public:
    matrix(int i,int j);
    void set_element(int i,int j,int value)
    {
        mat[i][j]=value;
    }
    int &get_element(int i,int j)
    {
        return mat[i][j];
    }
};
matrix::matrix(int i,int j)
{
    row=i,col=j;
    mat=new int*[row];
    for(int k=0;k<row;++k)
        mat[k]=new int[col];
}
int main()
{
    int row,col,value;
    cout<<"Enter order of matrix : ";
    cin>>row>>col;
    matrix m1(row,col);
    cout<<"Enter values row wise : "<<endl;
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
        {
            cin>>value;
            m1.set_element(i,j,value);
        }
    cout<<"Entered Matrix :-\n";
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
            cout<<m1.get_element(i,j)<<" ";
        cout<<endl;
    }
    return 0;
}
