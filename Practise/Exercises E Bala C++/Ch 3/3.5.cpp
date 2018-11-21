#include<iostream>
#include<cstdlib>
using namespace std;
int winner(int cand[],int _size);
int main()
{
    int _size;
    cout<<"Enter Number of Candidates : ";
    cin>>_size;
    int cand[_size+1];
    for(int i=0;i<=_size;++i)
        cand[i]=0;
    while(1)
    {
        cout<<"Enter you vote(-999 to end) : ";
        int vote;
        cin>>vote;
        switch(vote)
        {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        cand[vote]++;
        break;
    case -999:
        cout<<endl<<"Total Votes :-"<<endl<<endl;
        break;
    default:
        cout<<"Invalid Vote !!"<<endl;
        ++cand[0];
        }
        if(vote==-999)
            break;
    }
    for(int i=1;i<=_size;++i)
        cout<<"Candidate "<<i<<" votes : "<<cand[i]<<endl;
    cout<<"Invalid votes : "<<cand[0]<<endl<<endl;
    cout<<"Winner is candidate : "<<winner(cand,_size);
    return 0;
}
int winner(int cand[],int _size)
{
    int _max=0,k=0;
    for(int i=1;i<=_size;++i)
    {
        if(cand[i]>_max)
        {
            _max=cand[i];
            k=i;
        }
    }
    if(!k)
    {
        cout<<"No Winner !!";
        exit(0);
    }
    return k;
}
