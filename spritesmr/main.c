#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

#define SCREEN_W 640
#define SCREEN_H 480
#define SPRITE_W 16
#define SPRITE_H 16

int main(){
    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,SCREEN_W,SCREEN_H,0,0);
    set_palette(desktop_palette);

    BITMAP* bas = load_bitmap("pokemon.bmp", NULL);
    BITMAP* haut = load_bitmap("pokemon_haut.bmp", NULL);
    BITMAP* gauche = load_bitmap("pokemon_gauche.bmp", NULL);
    BITMAP* droite = load_bitmap("pokemon_droite.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);

    int recur = 0;
    int pause = 100; // delay between frames in game loops
    int sprite_x = (SCREEN_W - SPRITE_W)/ 2; // starting position of sprite
    int sprite_y = (SCREEN_H - SPRITE_H)/ 2;

    while (!key[KEY_ESC]){
        clear_bitmap(buffer);

        int x= (recur%4)*SPRITE_W;
        int y= (recur/4)*SPRITE_H;

        if (key[KEY_LEFT]){
            sprite_x -= 7;
            masked_blit(gauche,buffer,x,y,sprite_x,sprite_y,SPRITE_W,SPRITE_H);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
        if (key[KEY_RIGHT]){
            sprite_x += 7;
            masked_blit(droite,buffer,x,y,sprite_x,sprite_y,SPRITE_W,SPRITE_H);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
        if (key[KEY_UP]){
            sprite_y -= 7;
            masked_blit(haut,buffer,x,y,sprite_x,sprite_y,SPRITE_W,SPRITE_H);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
        if (key[KEY_DOWN]){
            sprite_y += 7;
            masked_blit(bas,buffer,x,y,sprite_x,sprite_y,SPRITE_W,SPRITE_H);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }

        rest(pause);
        recur=(recur + 1) % 4;
    }

    destroy_bitmap(bas);
    destroy_bitmap(haut);
    destroy_bitmap(gauche);
    destroy_bitmap(droite);
    destroy_bitmap(buffer);
    return 0;
}
END_OF_MAIN()
