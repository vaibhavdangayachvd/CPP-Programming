#include<iostream>
#define MAX 50
using namespace std;
void read(int arr[][MAX]=NULL,int m=0,int n=0);
void write(int arr[][MAX]=NULL,int m=0,int n=0);
int main()
{
    int arr[MAX][MAX];
    cout<<"Enter order of matrix : ";
    int m,n;
    cin>>m>>n;
    cout<<"Enter array elements(row wise)\n";
    read(arr,m,n);
    cout<<"Matrix :-\n";
    write(arr,m,n);
    return 0;
}
void read(int arr[][MAX],int m,int n)
{
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            cin>>arr[i][j];
}
void write(int arr[][MAX],int m,int n)
{
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
