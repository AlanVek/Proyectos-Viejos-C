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
