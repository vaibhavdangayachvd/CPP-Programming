#include<iostream>
using namespace std;
template<class t>
class matrix;
template<class t>
istream&operator>>(istream &din,matrix<t>&m);
template<class t>
ostream&operator<<(ostream &dout,const matrix<t>&m);
template<class t>
class matrix
{
    t **mat;
    int row;
    int col;
public:
    matrix();//Default constructor
    matrix(int r,int c);//const with row n col
    matrix(const t m);//Type Conversion
    matrix(const matrix<t> &m);//Copy Constructor
    ~matrix();//Destructor
    void operator=(const matrix<t> &m);//Overloading = copy
    void operator=(const t &m);//Overloading = assign integer
    matrix<t> operator*(const matrix<t> &m2);
    matrix<t> operator+(const matrix<t> &m2);
    matrix<t> operator-(const matrix<t> &m2);
    matrix<t> operator*(const t &n);
    friend matrix<t> operator*(const t &n,const matrix<t> &m2)
    {
        matrix<t> temp(m2.row,m2.col);
        for(int i=0;i<m2.row;++i)
            for(int j=0;j<m2.col;++j)
                temp.mat[i][j]=m2.mat[i][j]*n;
        return temp;
    }
    friend istream&operator>><>(istream &din,matrix<t> &m);
    friend ostream&operator<<<>(ostream &dout,const matrix<t> &m);
    void test(void);
};
template<class t>
matrix<t>::matrix()
{
    row=0,col=0,mat=0;
}
template<class t>
matrix<t>::matrix(int r,int c)
{
    row=r,col=c;
    mat=new t*[row];
    for(int i=0;i<row;++i)
        mat[i]=new t[col];
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            mat[i][j]=0;
}
template<class t>
matrix<t>::matrix(const t m)
{
    cout<<"Enter Order of matrix(row col) : ";
    cin>>row>>col;
    mat=new t*[row];
    for(int i=0;i<row;++i)
        mat[i]=new t[col];
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            mat[i][j]=m;
}
template<class t>
matrix<t>::matrix(const matrix<t> &m)
{
    row=m.row;
    col=m.col;
    mat=new t*[row];
    for(int i=0;i<row;++i)
        mat[i]=new t[col];
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            mat[i][j]=m.mat[i][j];
}
template<class t>
matrix<t>::~matrix()
{
    for(int i=0;i<row;++i)
        delete mat[i];
    delete mat;
}
template<class t>
void matrix<t>::operator=(const matrix<t> &m)
{
    matrix<t>::~matrix();
    row=m.row;
    col=m.col;
    mat=new t*[row];
    for(int i=0;i<row;++i)
        mat[i]=new t[col];
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            mat[i][j]=m.mat[i][j];
}
template<class t>
void matrix<t>::operator=(const t &m)
{
    if(row==0 && col==0)
    {
        cout<<"Enter Order of matrix(row col) : ";
        cin>>row>>col;
        mat=new t*[row];
        for(int i=0;i<row;++i)
            mat[i]=new t[col];
    }
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            mat[i][j]=m;
}
template<class t>
matrix<t> matrix<t>::operator*(const matrix<t> &m2)
{
    matrix<t> m3(row,m2.col);
    if(col!=m2.row)
    {
        cout<<"Multiplication not possible !!"<<endl;
        return m3;
    }
    for(int i=0;i<m3.row;++i)
    {
        for(int j=0;j<m3.col;++j)
        {
            int sum=0;
            for(int k=0;k<col;++k)
                sum+=mat[i][k]*m2.mat[k][j];
            m3.mat[i][j]=sum;
        }
    }
    return m3;
}
template<class t>
matrix<t> matrix<t>::operator*(const t &n)
{
    matrix<t> temp(row,col);
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            temp.mat[i][j]=mat[i][j]*n;
    return temp;
}
template<class t>
matrix<t> matrix<t>::operator+(const matrix<t> &m2)
{
    matrix<t>m3;
    if(row!=m2.row || col!=m2.col)
    {
        cout<<"Addition not possible !!"<<endl;
        return m3;
    }
    m3=matrix<t>(row,col);
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            m3.mat[i][j]=mat[i][j]+m2.mat[i][j];
    return m3;
}
template<class t>
matrix<t> matrix<t>::operator-(const matrix<t> &m2)
{
    matrix<t>m3;
    if(row!=m2.row || col!=m2.col)
    {
        cout<<"Addition not possible !!"<<endl;
        return m3;
    }
    m3=matrix<t>(row,col);
    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            m3.mat[i][j]=mat[i][j]-m2.mat[i][j];
    return m3;
}
template<class t>
istream&operator>>(istream &din,matrix<t>&m)
{
    if(m.row==0 && m.col==0)
    {
        cout<<"Enter Order of matrix(row col) : ";
        din>>m.row>>m.col;
        m.mat=new t*[m.row];
        for(int i=0;i<m.row;++i)
            m.mat[i]=new t[m.col];
    }
    cout<<"Enter elements of matrix("<<m.row<<","<<m.col<<") (row wise) :-"<<endl;
    for(int i=0;i<m.row;++i)
        for(int j=0;j<m.col;++j)
            din>>m.mat[i][j];
    return din;
}
template<class t>
ostream&operator<<(ostream &dout,const matrix<t>&m)
{
    for(int i=0;i<m.row;++i)
    {
        for(int j=0;j<m.col;++j)
            dout<<m.mat[i][j]<<" ";
        dout<<endl;
    }
    return dout;
}
int main()
{
    //Use Matrix Here
}
