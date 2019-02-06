#ifndef USER_H
#define USER_H
#include "person.h"
class user:public person
{
    int coin_balance;
    char username[30];
    char password[30];
public:
    user();
    void create_new_user(void);
	void show_user_menu(void);
    void add_coins(int coins);
    void take_coins(int coins);
    void change_password(void);
    void update_basic_details();
    int set_bet(void)const;//
    void show_credentials(void)const;
    void show_coin_balance(void)const;
    int get_coin_balance(void)const;
    static void show_all_users(void);
	static user get_user_by_username(const char *);
    static user login(void);
    static void show_user_by_name(void);
    static void commit_to_userfile(const user &a);
};
#endif
