
#include<allegro.h>

int main()
{
    allegro_init();
    set_color_depth(16);
    install_keyboard();
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);

    BITMAP *Simple = load_bitmap("Casa del puente MDP.bmp", NULL);
    blit(Simple,screen,0,0,100,0,SCREEN_W,SCREEN_H);
    destroy_bitmap(Simple);
    while (!keypressed());
    allegro_exit();
    return 0;
}

END_OF_MAIN()
