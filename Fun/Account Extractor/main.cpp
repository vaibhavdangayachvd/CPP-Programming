#include<iostream>
#include<fstream>
#include<string>
#include<list>
class account
{
    std::string email;
    std::string plan;
    std::string country;
    std::string owner;
    std::string config;
public:
    //Setters
    void set_email(std::string x){email=x;}
    void set_plan(std::string x){plan=x;}
    void set_country(std::string x){country=x;}
    void set_owner(std::string x){owner=x;}
    void set_config(std::string x){config=x;}
    //Getters
    std::string get_email(){return email;}
    std::string get_plan(){return plan;}
    std::string get_country(){return country;}
    std::string get_owner(){return owner;}
    std::string get_config(){return config;}
};
void display(std::list<account> acc)
{
    std::ofstream outf("Output.txt");
    std::list<account>::iterator p;
    for(p=acc.begin();p!=acc.end();++p)
    {
        if(p->get_country()!="Country: IN")
            continue;
        //std::cout<<p->get_email()<<std::endl<<p->get_country()<<std::endl<<std::endl;
        outf<<p->get_email()<<std::endl<<p->get_country()<<std::endl<<std::endl;
    }
    std::cout<<"Script Run Successful !!";
    outf.close();
}
int main()
{
    std::ifstream fin("accounts.txt");
    std::list<account> accounts;
    account bucket;
    while(fin)
    {
        char temp[200];
        fin.getline(temp,200);
        fin.getline(temp,200);
        bucket.set_email(temp);
        fin.getline(temp,200);
        bucket.set_plan(temp);
        fin.getline(temp,200);
        bucket.set_country(temp);
        fin.getline(temp,200);
        bucket.set_owner(temp);
        fin.getline(temp,200);
        bucket.set_config(temp);
        accounts.push_back(bucket);
    }
    fin.close();
    display(accounts);
    return 0;
}
