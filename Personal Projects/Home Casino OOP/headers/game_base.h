#ifndef GAME_BASE_H
#define GAME_BASE_H
class game_base
{
public:
    virtual bool play(void)=0;
    virtual void show_rules(void)=0;
};
#endif // GAME_H
