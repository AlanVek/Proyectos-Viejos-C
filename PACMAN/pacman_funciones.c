
#include "pacman_funciones.h"


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




