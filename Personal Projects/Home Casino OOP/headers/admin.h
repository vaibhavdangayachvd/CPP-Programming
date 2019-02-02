#ifndef ADMIN_H
#define ADMIN_H
class admin:public person
{
protected:
    char username[30];
    char password[30];
public:
    admin();
    void change_password(void);
    void show_admin_menu(void);
	void give_coins(void);
    void update_basic_details(void);
	void create_new_admin(void)const;
	void show_all_admins(void)const;
    void show_credentials(void)const;
    static void commit_to_adminfile(const admin &a);
    static admin get_admin_by_username(const char *);
    static admin login(void);
};
#endif