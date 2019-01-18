using namespace std;
class person
{
protected:
    char fname[30];
    char lname[30];
    int age;
    char gender;
public:
    void read_basic_details(void);
    void show_basic_details(void)const;
};
void person::read_basic_details(void)
{
    cout<<"Enter First Name : ";
    cin>>fname;
    cout<<"Enter Last Name : ";
    cin>>lname;
    do
    {
        cin.clear();//Clear cin flags
        cin.sync();//Remove newline char
        cout<<"Enter Age : ";
        cin>>age;
    }while(cin.fail());
    do
    {
        cout<<"Choose Gender:-\nM : Male\nF : Female\nO : Others\n->";
        cin>>gender;
        if(gender!='m' && gender!='f' && gender!='o')//Only accept 3 char values(m,o,f)
            cout<<"Wrong Choice !! Try again !!\n";
    }while(gender!='m' && gender!='f' && gender!='o');
}
void person::show_basic_details(void)const
{
    cout<<"Name : "<<fname<<" "<<lname<<endl;
    cout<<"Gender : ";
    switch(gender)
    {
    case 'm':
        cout<<"Male"<<endl;
        break;
    case 'f':
        cout<<"Female"<<endl;
        break;
    case 'o':
        cout<<"Others"<<endl;
        break;
    }
    cout<<"Age : "<<age<<endl;
}