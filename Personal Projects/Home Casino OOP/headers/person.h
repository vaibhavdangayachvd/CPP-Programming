#ifndef PERSON_H
#define PERSON_H
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
#endif