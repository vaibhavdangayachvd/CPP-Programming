#include<iostream>
#include<map>
#include<string>
#include<cctype>
using namespace std;
enum token_value
{
    NAME,NUMBER,END,
    PLUS='+',MINUS='-',MUL='*',DIV='/',
    PRINT=';',ASSIGN='=',LP='(',RP=')'
};
token_value curr_tok = PRINT;
token_value get_token(void);
double expr(bool get);
double term(bool get);
double error(const string &s);
double prim(bool get);
double expr(bool get)
{
    double left=term(get);
    for(;;)
    {
        switch(curr_tok)
        {
        case PLUS:
            left+=term(true);
            break;
        case MINUS:
            left-=term(true);
            break;
        default:
            return left;
        }
    }
}
double term(bool get)
{
    double left=prim(get);
    for(;;)
    {
        switch(curr_tok)
        {
        case MUL:
            left*=prim(true);
            break;
        case DIV:
            if(double d=prim(true))
            {
                left/=d;
                break;
            }
            return error("Divide by ZERO");
        default:
            return left;
        }
    }
}
map<string,double> table;
double number_value;
string string_value;
double prim(bool get)
{
    if(get)
        get_token();
    double v;
    switch(curr_tok)
    {
    case NUMBER:
        v=number_value;
        get_token();
        return v;
    case NAME:
    {
        double &v=table[string_value];
        if(get_token()==ASSIGN)
            v=expr(true);
        return v;
    }
    case MINUS:
        return -prim(true);
    case LP:
    {
        double e=expr(true);
        if(curr_tok!=RP)
            error("')' expected");
        get_token();
        return e;
    }
    default:
        error("Primary Expected");
    }
}
token_value get_token(void)
{
    char ch=0;
    do
        cin.get(ch);
    while(ch!='\n'&& isspace(ch));
    switch(ch)
    {
    case ';':
    case '\n':
        return curr_tok=END;
    case MUL:
    case DIV:
    case PLUS:
    case MINUS:
    case LP:
    case RP:
    case ASSIGN:
        return curr_tok=token_value(ch);
    case '0':case '1':case '2':case '3':case '4':
    case '5':case '6':case '7':case '8':case '9':
    case '.':
        cin.putback(ch);
        cin>>number_value;
        return curr_tok=NUMBER;
    default:
        if(isalpha(ch))
        {
            cin.putback(ch);
            cin>>string_value;
            return curr_tok=NAME;
        }
        error("bad token");
        return curr_tok=PRINT;
    }
}
int no_of_errors;
double error(const string &s)
{
    no_of_errors++;
    cerr<<"error:"<<s<<'\n';
    return 1;
}
int main()
{
    table["pi"]=3.14;
    table["e"]=2.71;
    get_token();
    if(curr_tok!=END)
        cout<<expr(false)<<'\n';
    return no_of_errors;
}
