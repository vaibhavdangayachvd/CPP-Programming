#include<iostream>
#include<cstdlib>
using namespace std;
class matrix
{
    int **mat;
    int row;
    int col;
public:
    matrix(){mat=0,row=0,col=0;};//Default Constructor
    matrix(const int r,const int c);//Constructor
    matrix(const matrix &m);//Copy Constructor
    operator=(const matrix &m);//Overloaded = Copy Constructor
    friend istream&operator>>(istream &din,matrix &m); //Overloaded >>
    friend ostream&operator<<(ostream &dout,const matrix &m);//Overloaded <<
    matrix operator+(const matrix & m2);//Overloaded +
    matrix operator-(const matrix & m2);//Overloaded -
    matrix operator/(const matrix & m2);//Overloaded /
    friend matrix operator*(const matrix &m1,const matrix &m2);//Overloaded *
    friend matrix operator*(const matrix &m1,int n);//Overloaded *
    friend matrix operator*(int n,const matrix &m1);//Overloaded *
    ~matrix(void);//Destructor
};
matrix::matrix(const int r,const int c)
{
    row=r;
    col=c;
    mat=new int*[row];
    for(int i=0;i<row;++i)
        mat[i]=new int[col];
}
matrix::matrix(const matrix &m)
{
    row=m.row,col=m.col;
    mat=new int*[row];
    for(int i=0;i<row;++i)
        mat[i]=new int[col];
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            mat[i][j]=m.mat[i][j];
}
matrix::operator=(const matrix & m)
{
    row=m.row,col=m.col;
    mat=new int*[row];
    for(int i=0;i<row;++i)
        mat[i]=new int[col];
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            mat[i][j]=m.mat[i][j];
}
istream&operator>>(istream &din,matrix &m)
{
    for(int i=0;i<m.row;++i)
        for(int j=0;j<m.col;++j)
            din>>m.mat[i][j];
    return din;
}
ostream&operator<<(ostream &dout,const matrix &m)
{
    for(int i=0;i<m.row;++i)
    {
        for(int j=0;j<m.col;++j)
            dout<<m.mat[i][j]<<" ";
        cout<<endl;
    }
    return dout;
}
matrix::~matrix(void)
{
    for(int i=0;i<row;++i)
        delete(mat[i]);
    delete(mat);
}
matrix matrix::operator/(const matrix & m2)
{
    matrix m3(m2.row,m2.col);
    for(int i=0;i<m2.col;++i)
        for(int j=0;j<m2.row;++j)
            m3.mat[i][j]=m2.mat[j][i];
    return m3;
}
matrix matrix::operator+(const matrix & m2)
{
    matrix m3(row,col);
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            m3.mat[i][j]=mat[i][j]+m2.mat[i][j];
    return m3;
}
matrix matrix::operator-(const matrix & m2)
{
    matrix m3(row,col);
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            m3.mat[i][j]=mat[i][j]-m2.mat[i][j];
    return m3;
}
matrix operator*(const matrix &m1,const matrix &m2)
{
    matrix m3;
    if(m1.col!=m2.row)
        return m3;
    m3=matrix(m1.row,m2.col);
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
    return m3;
}
matrix operator*(const matrix &m1,int n)
{
    matrix m3(m1.row,m1.col);
    for(int i=0;i<m1.row;++i)
        for(int j=0;j<m1.col;++j)
            m3.mat[i][j]=m1.mat[i][j]*n;
    return m3;
}
matrix operator*(int n,const matrix &m1)
{
    matrix m3(m1.row,m1.col);
    for(int i=0;i<m1.row;++i)
        for(int j=0;j<m1.col;++j)
            m3.mat[i][j]=m1.mat[i][j]*n;
    return m3;
}
int main()
{
    matrix m1(3,3);
    cout<<"Enter elements row wise :-\n";
    cin>>m1;
    cout<<"Entered matrix :-\n"<<m1;
    matrix m2=m1;
    cout<<"Copied matrix :-\n"<<m2;
    matrix m3=m1+m2;
    matrix m4=m1-m2;
    matrix m5=m1*m2;
    matrix m6=m1*2;
    matrix m7=m7/m1;
    cout<<"Sum matrix :-\n"<<m3;
    cout<<"Diff matrix :-\n"<<m4;
    cout<<"Prod matrix :-\n"<<m5;
    cout<<"Cnst Product matrix :-\n"<<m6;
    cout<<"Transpose matrix :-\n"<<m7;
    return 0;
}
