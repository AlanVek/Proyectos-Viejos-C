#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>
#include <string.h>
#include <allegro/draw.h>
#include <allegro/midi.h>
#define ancho 600
#define alto 500
void pantalla (BITMAP *buffer);
void circulitos(BITMAP *buffer,int posic_x[],int posic_y[]);
void comercirculitos(BITMAP *buffer,int posic_x[],int posic_y[],int a,int b);
void pacman (BITMAP *buffer, int a, int b);
void fantasmita (BITMAP *buffer,int a, int b);
int ver_si_gane(int posic_x[],int posic_y[]);
int movim (int a, int b);

int main()
{
    MIDI *muerte=load_wav("pacman_death.wav"),*inicio=load_wav("pacman_beginning.wav");
    int i,j, a,b,cont,s,pausa=0,m,pasos=0;
    allegro_init();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
    srand (time(NULL));
    set_color_depth(32);
    int install_timer();
    install_keyboard();
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, ancho, alto, 0, 0);
    BITMAP *buffer=create_bitmap(ancho,alto);
    time_t tiempo;

    while (!key[KEY_ESC])
    {
        clear_to_color(buffer, makecol(0,0,0));

        textout_centre_ex(buffer,font,"PACMAN",ancho/2,90,0xFFFFFF, 0xDF1680);
        textout_centre_ex(buffer, font, "1.- INICIAR", ancho/2, 160, 0xFFFFFF, makecol(0,0,0));
        textout_centre_ex(buffer, font, "2.- SALIR", ancho/2, 370, 0xFFFFFF, makecol(0,0,0));

        blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
        if (key[KEY_1])
        {
           int posic_x[148]={20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,580,580,580,580,580,580,580,580,580,580,580,580,580,580,580,580,580,580,580,580,300,300,300,300,300,300,300,300,300,300,300,300,20,48,76,104,132,160,188,216,244,272,300,328,356,384,412,440,468,496,524,552,580,20,48,76,104,132,160,188,216,244,272,300,328,356,384,412,440,468,496,524,552,580,20,48,76,104,132,160,188,216,244,272,300,328,356,384,412,440,468,496,524,552,580,20,48,76,104,132,160,188,216,244,272,300,328,356,384,412,440,468,496,524,552,580,216,216,216,216,216,216,412,412,412,412,412,412};
           int posic_y[148]={20,43,66,89,112,135,158,181,204,227,250,273,296,319,342,365,388,411,434,457,20,43,66,89,112,135,158,181,204,227,250,273,296,319,342,365,388,411,434,457,20,43,66,89,112,135,342,365,388,411,434,457,480,480,480,480,480,480,480,480,480,480,480,480,480,480,480,480,480,480,480,480,480,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,158,158,158,158,158,158,158,158,158,158,158,158,158,158,158,158,158,158,158,158,158,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,181,204,227,250,273,296,181,204,227,250,273,296};
            a=15;
            b=15;
            i=ancho-10;
            j=alto-10;
            cont=1;
            while (cont=1)
            {
                clear_to_color(buffer,makecol(0,0,0));
                pantalla(buffer);
                pacman (buffer,a,b);
                circulitos(buffer,posic_x,posic_y);
                rest(1000);
                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                play_sample(inicio,255,0,1000,2);
                if (!key[KEY_1])
                {
                    cont=2;
                    break;
                }
            }
            while (cont==2)
            {
                if (pausa==0)
                {

                    tiempo=clock();
                    clear_to_color(buffer,makecol(0,0,0));
                    pantalla(buffer);
                    fantasmita (buffer,i,j);
                    circulitos(buffer,posic_x,posic_y);
                    pacman (buffer,a,b);
                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                    if (key[KEY_RIGHT])
                    {
                        clear_to_color(buffer,makecol(0,0,0));
                        pantalla(buffer);
                        circulitos(buffer,posic_x,posic_y);
                        if (a>=ancho)
                            a=0;
                        s=movim (a+30,b);
                        if (s==1)
                            a+=15;
                        pacman (buffer,a,b);
                        fantasmita (buffer,i,j);
                        blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                        rest (100);

                    }
                    if (key[KEY_ESC])
                        break;
                    if (key[KEY_DOWN])
                    {
                        clear_to_color(buffer,makecol(0,0,0));
                        pantalla(buffer);
                        circulitos(buffer,posic_x,posic_y);
                        if (b>=alto)
                            b=0;
                        s=movim (a,b+30);
                        if (s==1)
                            b+=15;
                        pacman (buffer,a,b);
                        fantasmita (buffer,i,j);
                        blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                        rest (100);

                    }
                    if (key[KEY_LEFT])
                    {
                        clear_to_color(buffer,makecol(0,0,0));
                        pantalla(buffer);
                        circulitos(buffer,posic_x,posic_y);
                        if (a<=0)
                            a=ancho;
                        s=movim (a-30,b);
                        if (s==1)
                            a-=15;
                        pacman(buffer,a,b);
                        fantasmita (buffer,i,j);
                        blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                        rest (100);
                    }
                    if (key[KEY_UP])
                    {
                        clear_to_color(buffer,makecol(0,0,0));
                        pantalla(buffer);
                        circulitos(buffer,posic_x,posic_y);
                        if (b<=0)
                            b=alto;
                        s=movim (a,b-30);
                        if (s==1)
                            b-=15;
                        pacman (buffer,a,b);
                        fantasmita (buffer,i,j);
                        blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                        rest (100);
                    }
                    if (clock()-tiempo>80)
                    {
                        int k=32;
                        tiempo=clock();
                        if (pasos==0)
                        {
                            if (i>25)
                            {
                                i=i-k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j>15)
                                {
                                    j=j-k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                {
                                    pasos=1;
                                }
                            }
                        }
                        if (pasos==1)
                        {
                            if (i<580)
                            {
                                i=i+k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j<300)
                                {
                                    j=j+k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                {
                                    pasos=2;
                                }
                            }
                        }
                        if (pasos==2)
                        {
                            if (i>226)
                            {
                                i=i-k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j>158)
                                {
                                    j-=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=3;
                            }
                        }
                        if (pasos==3)
                        {
                            if (i<300)
                            {
                                i+=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j>20)
                                {
                                    j=j-k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=4;
                            }
                        }
                        if (pasos==4)
                        {
                            if (i<580)
                            {
                                i+=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j<165)
                                {
                                    j+=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=5;
                            }
                        }
                        if (pasos==5)
                        {
                            if (i>20)
                            {
                                i-=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j<315)
                                {
                                    j+=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=6;
                            }
                        }
                        if (pasos==6)
                        {
                            if (i<580)
                            {
                                i+=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j<480)
                                {
                                    j+=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=7;
                            }
                        }
                        if (pasos==7)
                        {
                            if (i>20)
                            {
                                i-=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j>315)
                                {
                                    j-=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=8;
                            }
                        }
                        if (pasos==8)
                        {
                            if (i<395)
                            {
                                i+=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j>165)
                                {
                                    j-=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=9;
                            }
                        }
                        if (pasos==9)
                        {
                            if (i>220)
                            {
                                i-=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j<315)
                                {
                                    j+=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=10;
                            }
                        }
                        if (pasos==10)
                        {
                            if (i<580)
                            {
                                i+=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j<480)
                                {
                                    j+=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=11;
                            }
                        }
                        if (pasos==11)
                        {
                            if (i>310)
                            {
                                i-=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j>315)
                                {
                                    j-=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=12;
                            }
                        }
                        if (pasos==12)
                        {
                            if (i<395)
                            {
                                i+=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j>158)
                                {
                                    j-=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=13;
                            }
                        }
                        if (pasos==13)
                        {
                            if (i>216)
                            {
                                i-=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j<315)
                                {
                                    j+=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=14;
                            }
                        }
                        if (pasos==14)
                        {
                            if (i>20)
                            {
                                i-=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j>20)
                                {
                                    j-=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=15;
                            }
                        }
                        if (pasos==15)
                        {
                            if (i<295)
                            {
                                i+=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j<158)
                                {
                                    j+=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=16;
                            }
                        }
                        if (pasos==16)
                        {
                            if (i<580)
                            {
                                i+=k;
                                clear_to_color(buffer,makecol(0,0,0));
                                pantalla(buffer);
                                circulitos(buffer,posic_x,posic_y);
                                pacman (buffer,a,b);
                                fantasmita (buffer,i,j);
                                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                            }
                            else
                            {
                                if (j<480)
                                {
                                    j+=k;
                                    clear_to_color(buffer,makecol(0,0,0));
                                    pantalla(buffer);
                                    circulitos(buffer,posic_x,posic_y);
                                    pacman (buffer,a,b);
                                    fantasmita (buffer,i,j);
                                    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                                }
                                else
                                    pasos=0;
                            }
                        }

                    }

                    if (abs(i-a)<=25 && abs(b-j)<=25)
                    {
                        clear_to_color(buffer,makecol(240,20,30));
                        textout_centre_ex(buffer,font,"PERDISTE",ancho/2,alto/2,makecol(0,0,0),makecol(240,20,30));
                        stop_sample(inicio);
                        play_sample(muerte,255,0,2000,0);
                        blit (buffer, screen,0,0,0,0,ancho,alto);
                        pasos=0;
                        rest(1800);
                        break;
                    }
                    if (key[KEY_SPACE])
                    {
                        pausa=1-pausa;
                    }

                    comercirculitos(buffer,posic_x,posic_y,a,b);
                    m=ver_si_gane(posic_x,posic_y);
                    if (m==1)
                    {
                        clear_to_color(buffer,makecol(30,240,20));
                        textout_centre_ex(buffer,font,"GANASTE",ancho/2,alto/2,makecol(0,0,0),makecol(30,240,20));
                        stop_sample(inicio);
                        blit(buffer,screen,0,0,0,0,ancho,alto);
                        pasos=0;
                        rest (1500);
                        break;
                    }

                }
                if (pausa==1)
                {
                    rectfill(buffer,ancho/2-80,alto/2-50,ancho/2+80,alto/2+50,0x333333);
                    textout_centre_ex(buffer,font,"JUEGO EN PAUSA",ancho/2,alto/2,0xffffff,0x333333);
                    blit(buffer,screen,0,0,0,0,ancho,alto);
                    if (key[KEY_SPACE])
                        pausa=1-pausa;
                }

            }
        }
        if (key[KEY_2])
            break;


    }
    destroy_bitmap(buffer);
    destroy_sample(inicio);
    destroy_sample(muerte);
    allegro_exit();
    return 0;
}
END_OF_MAIN();
void pantalla (BITMAP *buffer)
{
    rect(buffer,50,50,275,100,makecol(0,0,255));
    rect(buffer,47,47,278,103,makecol(0,0,255));
    rect(buffer,235,180,380,280,makecol(0,0,255));
    rect(buffer,232,177,383,283,makecol(0,0,255));
    rect(buffer,328,50,550,100,makecol(0,0,255));
    rect(buffer,325,47,553,103,makecol(0,0,255));
    rect(buffer,50,180,180,280,makecol(0,0,255));
    rect(buffer,47,177,183,283,makecol(0,0,255));
    rect(buffer,430,180,550,280,makecol(0,0,255));
    rect(buffer,427,177,553,283,makecol(0,0,255));
    rect(buffer,328,350,550,450,makecol(0,0,255));
    rect(buffer,325,347,553,453,makecol(0,0,255));
    rect(buffer,50,350,275,450,makecol(0,0,255));
    rect(buffer,47,347,278,453,makecol(0,0,255));
}
void pacman (BITMAP *buffer, int a, int b)
{
    circlefill(buffer,a,b,15,makecol(255,255,0));
    circlefill(buffer,a+7,b-2,2,makecol(0,0,0));
    line (buffer,a+7,b+5,a+15,b+5,makecol(0,0,0));
}
void circulitos(BITMAP *buffer,int posic_x[],int posic_y[])
{
    int i;
    for (i=0;i<148;i++)
    {
        circlefill(buffer,posic_x[i],posic_y[i],1,0xffffff);
    }
}
int movim (int a, int b)
{
    if (!((a>=47 && a<=278)&&(b>=47 && b<=103)||(a>=232 && a<=383)&&(b>=177 && b<=283)||(a>=325 && a<=553)&&(b>=47 && b<=103)||(a>=47 && a<=183)&&(b>=177 && b<=283)||(a>=427 && a<=553)&&(b>=177 && b<=283)||(a>=325 && a<=553)&&(b>=347 && b<=453)||(a>=47 && a<=278)&&(b>=347 && b<=453)))
        return 1;
    else
        return 0;
}
void comercirculitos(BITMAP *buffer,int posic_x[],int posic_y[],int a,int b)
{
    int i;
    for (i=0;i<148;i++)
    {
        if (posic_x[i]<=a+15 && posic_x[i]>=a-15 && posic_y[i]<=b+15 && posic_y[i]>=b-15)
        {
            posic_x[i]=0;
            posic_y[i]=0;
        }
    }
}
int ver_si_gane(int posic_x[],int posic_y[])
{
    int i,gane=1;
    for (i=0;i<148;i++)
    {
        if (posic_x[i]!=0 && posic_y[i]!=0)
            gane=0;
    }
    return gane;
}
void fantasmita (BITMAP *buffer,int a, int b)
{
    circlefill(buffer,a,b,10,0xf419d5);
    circlefill(buffer,a+4,b-1,2,makecol(0,0,0));
    circlefill(buffer,a-4,b-1,2,makecol(0,0,0));
    line (buffer,a-3,b+5,a+3,b+5,makecol(0,0,0));
}





