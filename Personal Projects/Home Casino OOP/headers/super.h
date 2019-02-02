#ifndef SUPER_H
#define SUPER_h
class super:public admin
{
public:
    super();
    void show_super_menu(void);
    void reset_casino(void);
    static super login(void);
    static super get_super_by_username(const char *);
    static void commit_to_superfile(const super &s);

};
#endif