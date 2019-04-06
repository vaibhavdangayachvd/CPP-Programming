#ifndef BULLET_H
#define BULLET_H
#include<memory>
class bullet
{
    int direction;
    int speed;
    int weight;
public:
    bullet(int s,int w);
    void fire(int d);
    virtual std::unique_ptr<bullet> clone(void)=0;
};
#endif // BULLET_H
