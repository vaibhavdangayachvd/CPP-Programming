#include "..\\headers\\game_settings.h"
#include<iostream>
game_settings* game_settings::instance;
game_settings::game_settings()
{
    width=100;
    height=100;
    brightness=50;
}
game_settings* game_settings::get_instance()
{
    if(instance==NULL)
        instance=new game_settings;
    return instance;
}
void game_settings::set_width(int w)
{
    width=w;
}
void game_settings::set_height(int h)
{
    height=h;
}
void game_settings::set_brightness(int b)
{
    brightness=b;
}
int game_settings::get_width()
{
    return width;
}
int game_settings::get_height()
{
    return height;
}
int game_settings::get_brightness()
{
    return brightness;
}
void game_settings::display_settings()
{
    std::cout<<"Width : "<<get_width()<<std::endl<<"Height : "<<get_height()<<std::endl<<"Brightness : "<<get_brightness()<<std::endl;
}
game_settings* game_settings::reset_settings()
{
    delete instance;
    instance=NULL;
    return get_instance();
}
