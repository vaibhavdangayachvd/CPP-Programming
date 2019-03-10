#ifndef GAME_SETTINGS
#define GAME_SETTINGS
class game_settings
{
    static game_settings *instance;
    int width;
    int height;
    int brightness;
    game_settings();
public:
    static game_settings* get_instance();
    static game_settings* reset_settings();
    void set_width(int w);
    void set_height(int h);
    void set_brightness(int b);
    int get_width();
    int get_height();
    int get_brightness();
    void display_settings();
};
#endif // GAME_SETTINGS
