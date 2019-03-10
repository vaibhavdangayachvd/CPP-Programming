#ifndef CAR_H
#define CAR_H
#include<vector>
class car;
#include "..\\abstract\\observer.h"
class car
{
    std::vector<observer *> obs_list;
    int position;
public:
    void set_position(const int &pos);
    int get_position(void);
    void attach(observer *obj);
    void detach(observer *obj);
    void notify(void);
};
#endif // CAR_H
