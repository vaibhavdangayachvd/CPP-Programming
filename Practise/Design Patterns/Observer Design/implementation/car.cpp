#include "..\\headers\\car.h"
#include<algorithm>
void car::set_position(const int &pos)
{
    position=pos;
    notify();
}
int car::get_position(void)
{
    return position;
}
void car::attach(observer *obj)
{
    obs_list.push_back(obj);
}
void car::detach(observer *obj)
{
    obs_list.erase(std::remove(obs_list.begin(),obs_list.end(),obj),obs_list.end());
}
void car::notify(void)
{
    for(int i=0;i<obs_list.size();++i)
        obs_list[i]->update();
}
