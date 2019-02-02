#include "..\\headers\\extras.h"
//Hold Screen Message
void hold(void)
{
    cout<<"\n\n\tPress Enter to continue...";
    getch();
}
//Securely read password in an array
void get_password(char *ch)
{
    char c;
    int i=0;
    //Read character and if backspace reduce counter
    while((c=getch())!=13)//Enter
    {
        if(c==8)//Backspace
        {
            if(i!=0)//While index not equal to 0
            {
                if(i>1)//Do until single character is left
                    cout<<"\b\b"<<ch[i-2]<<" \b";
                else//Prevent from accessing past 0 i.e when single char is left
                    cout<<"\b \b";
                --i;
            }
            continue;
        }
        else
        {
            if(i!=0)
                cout<<"\b*";//After first character go back and convert into *
            ch[i]=c;
            cout<<ch[i++];//Display current character and increment i
        }
    }
    cout<<"\b*";//After enter is pressed remove last read character
    ch[i]='\0';//Make it String
    cout<<endl;
}
