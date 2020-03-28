#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>
#include <string.h>
#include <allegro/draw.h>
#define ancho 600
#define alto 500

void juego (BITMAP *buffer,char palabra[]);
int crearnumaleat(int mem[],int posicion);
int main()
{
    int i,m,a=1,tecla,posicion=0,mem[36],menpos,largo;
    allegro_init();
    srand (time(NULL));
    set_color_depth(32);
    install_keyboard();
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, ancho, alto, 0, 0);
    BITMAP *buffer=create_bitmap(ancho,alto);
    char asc,letra,palabrita[500];


    while (!key[KEY_ESC])
    {
        while (a==1)
        {
            clear_to_color(buffer, makecol(0,0,0));

            textout_centre_ex(buffer,font,"AHORCADO",ancho/2,90,0xFFFFFF, 0xDF1680);
            textout_centre_ex(buffer, font, "1.- UN/A JUGADOR/A.", ancho/2, 160, 0xFFFFFF, makecol(0,0,0));
            textout_centre_ex(buffer, font, "2.- DOS JUGADORES/AS.", ancho/2, 370, 0xFFFFFF, makecol(0,0,0));

            blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
            if (keypressed)
                break;
        }
        clear_to_color (buffer,makecol(0,0,0));
        if (key[KEY_1])
        {
            m=crearnumaleat(mem,posicion);
            char n[500];
            if (posicion>0)
            {
                for (i=0;i<strlen(n);i++)
                {
                    n[i]=00;
                }
            }
            switch (m)
            {
                case 0:
                    {
                        char n[]={"P.A.C.H.A.M.A.M.A"};
                        juego(buffer,n);
                        break;
                    }
                case 1:
                    {
                        char n[]={"A.B.A.R.R.O.T.A.D.O"};
                        juego(buffer,n);
                        break;
                    }
                case 2:
                    {
                        char n[]={"L.I.N.F.O.C.I.T.O"};
                        juego(buffer,n);
                        break;
                    }
                case 3:
                    {
                        char n[]={"C.A.R.A.M.B.O.L.A.S"};
                        juego(buffer,n);
                        break;
                    }
                case 4:
                    {
                        char n[]={"C.O.R.R.E.T.E.A.N.D.O"};
                        juego(buffer,n);
                        break;
                    }
                case 5:
                    {
                        char n[]={"S.E.R.E.N.D.I.P.I.A"};
                        juego(buffer,n);
                        break;
                    }
                case 6:
                    {
                        char n[]={"W.H.I.S.K.Y"};
                        juego(buffer,n);
                        break;
                    }
                case 7:
                    {
                        char n[]={"C.A.Z.A.D.O.R.A"};
                        juego(buffer,n);
                        break;
                    }
                case 8:
                    {
                        char n[]={"M.A.R.Q.U.E.S.A"};
                        juego(buffer,n);
                        break;
                    }
                case 9:
                    {
                        char n[]={"P.E.R.O.X.I.D.O.S"};
                        juego(buffer,n);
                        break;
                    }
                case 10:
                    {
                        char n[]={"H.A.M.A.C.A"};
                        juego(buffer,n);
                        break;
                    }
                case 11:
                    {
                        char n[]={"C.A.L.A.B.A.Z.A"};
                        juego(buffer,n);
                        break;
                    }
                case 12:
                    {
                        char n[]={"R.I.Q.U.I.S.I.M.O"};
                        juego(buffer,n);
                        break;
                    }
                case 13:
                    {
                        char n[]={"C.A.R.T.I.L.A.G.I.N.O.S.O"};
                        juego(buffer,n);
                        break;
                    }
                case 14:
                    {
                        char n[]={"E.N.T.R.E.T.E.N.I.D.O"};
                        juego(buffer,n);
                        break;
                    }
                case 15:
                    {
                        char n[]={"C.O.N.S.E.N.T.I.M.I.E.N.T.O"};
                        juego(buffer,n);
                        break;
                    }
                case 16:
                    {
                        char n[]={"A.M.E.T.R.A.L.L.A.D.O.R.A"};
                        juego(buffer,n);
                        break;
                    }
                case 17:
                    {
                        char n[]={"K.I.T.A.S.A.T.O"};
                        juego(buffer,n);
                        break;
                    }
                case 18:
                    {
                        char n[]={"M.A.Q.U.I.A.V.E.L.I.C.O"};
                        juego(buffer,n);
                        break;
                    }
                case 19:
                    {
                        char n[]={"O.C.C.I.P.I.T.A.L"};
                        juego(buffer,n);
                        break;
                    }
                case 20:
                    {
                        char n[]={"M.E.S.O.P.O.T.A.M.I.C.O"};
                        juego(buffer,n);
                        break;
                    }
                case 21:
                    {
                        char n[]={"E.N.R.A.R.E.C.I.D.O"};
                        juego(buffer,n);
                        break;
                    }
                case 22:
                    {
                        char n[]={"D.E.S.P.O.J.A.D.O"};
                        juego(buffer,n);
                        break;
                    }
                case 23:
                    {
                        char n[]={"C.A.M.A.R.A"};
                        juego(buffer,n);
                        break;
                    }
                case 24:
                    {
                        char n[]={"A.L.A.B.A.N.Z.A"};
                        juego(buffer,n);
                        break;
                    }
                case 25:
                    {
                        char n[]={"I.N.T.E.R.I.O.R.I.Z.A.D.O"};
                        juego(buffer,n);
                        break;
                    }
                case 26:
                    {
                        char n[]={"Q.U.I.T.I.N.A"};
                        juego(buffer,n);
                        break;
                    }
                case 27:
                    {
                        char n[]={"M.E.Q.U.E.T.R.E.F.E"};
                        juego(buffer,n);
                        break;
                    }
                case 28:
                    {
                        char n[]={"A.G.A.S.A.J.A.D.A"};
                        juego(buffer,n);
                        break;
                    }
                case 29:
                    {
                        char n[]={"Z.A.F.I.R.O"};
                        juego(buffer,n);
                        break;
                    }
                case 30:
                    {
                        char n[]={"H.A.L.A.J.A.S"};
                        juego(buffer,n);
                        break;
                    }
                case 31:
                    {
                        char n[]={"M.A.Z.O.R.C.A"};
                        juego(buffer,n);
                        break;
                    }
                case 32:
                    {
                        char n[]={"P.A.K.I.S.T.A.N.I"};
                        juego(buffer,n);
                        break;
                    }
                case 33:
                    {
                        char n[]={"E.S.Q.U.I.Z.O.F.R.E.N.I.C.O"};
                        juego(buffer,n);
                        break;
                    }
                case 34:
                    {
                        char n[]={"D.E.S.I.N.H.I.B.I.D.A"};
                        juego(buffer,n);
                        break;
                    }
                case 35:
                    {
                        char n[]={"A.V.A.L.A.N.C.H.A"};
                        juego(buffer,n);
                        break;
                    }
                case 36:
                    {
                        char n[]={"C.A.P.O.E.I.R.A"};
                        juego(buffer,n);
                        break;
                    }
                case 37:
                    {
                        char n[]={"A.C.A.U.D.A.L.A.D.A"};
                        juego(buffer,n);
                        break;
                    }
                case 38:
                    {
                        char n[]={"O.Y.E.N.T.E"};
                        juego(buffer,n);
                        break;
                    }
                case 39:
                    {
                        char n[]={"M.A.C.H.A.C.A.D.A"};
                        juego(buffer,n);
                        break;
                    }
            }

            mem[posicion]=m;
            posicion+=1;

            if (posicion==40)
            {
                textout_centre_ex(buffer, font,"JUEGO TERMINADO.",ancho/2,100,0xffffff,makecol(0,0,0));
                blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
                rest (2200);
                break;
            }

            a=1;
        }
        if (key[KEY_2])
        {
            for (i=1;i<499;i++)
                palabrita[i]=0;

            clear_to_color(buffer,makecol(0,0,0));
            for (i=-2;i<499;i+=2)
            {
                textout_centre_ex(buffer,font,"JUGADOR 1",ancho/2,100,0xffffff,makecol(0,0,0));
                textout_centre_ex(buffer,font,"INGRESE PALABRA Y PRESIONE ENTER: ",ancho/2-135,400,0xffffff,makecol(0,0,0));
                blit(buffer,screen,0,0,0,0,ancho,alto);
                if (key[KEY_ENTER])
                {
                    largo=i;
                    break;
                }
                else
                {
                    tecla=readkey();
                    if (!key[KEY_2] && !key[KEY_ENTER])
                    {
                        tecla=tecla-32;
                        letra=tecla;
                        palabrita[i]=letra;
                    }
                }
                if (palabrita[i]>=65 && palabrita[i]<=90)
                {
                    textprintf_ex(buffer,font,7*i+ancho/2+5,400,0xffffff,makecol(0,0,0),"%c",palabrita[i]);
                    blit(buffer,screen,0,0,0,0,ancho,alto);
                }
            }
            rest (800.0);
            clear_to_color(buffer,makecol(0,0,0));
            blit(buffer,screen,0,0,0,0,ancho,alto);
            juego (buffer,palabrita);
        }
        a=1;

    }
    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}
END_OF_MAIN();

void juego (BITMAP *buffer,char palabra[])
{
    int esta2,l=0,i,esta,valor=7,total=0,tecla,largo,tipo=2;
    for (i=0;i<498;i++)
    {
        if ((palabra[i]==' ' && palabra[i+1]==' ')||(palabra[i]==0 && palabra[i+1]==0))
        {
            largo=i;
            break;
        }
    }
    if (key[KEY_1])
    {
        tipo=1;
        valor=8;
        for (i=0;i<499;i++)
        {
            if (palabra[i]==0)
            {
                largo=i;
                break;
            }
        }
    }

    char pal[largo], usadas[valor],asc;

    for (i=0;i<7;i++)
        usadas[i]=0;
    for (i=0;i<largo;i+=2)
    {
        pal[i]=95;
        if (i!=largo-1)
            pal[i+1]=00;
    }

    while (valor>0 && total<((largo+1)/2))
    {
        line(buffer,ancho/2-20,300,ancho/2+20,300,0xffffff);
        line(buffer,ancho/2,300,ancho/2,180,0xffffff);
        line(buffer,ancho/2,180,ancho/2+50,180,0xffffff);
        line(buffer,ancho/2+50,180,ancho/2+50,200,0xffffff);

        if (valor<=6)
            circle(buffer,ancho/2+50,210,10,0xffffff);
        if (valor<=5)
            line (buffer,ancho/2+50,220,ancho/2+50,250,0xffffff);
        if (valor<=4)
            line (buffer, ancho/2+50,250,ancho/2+35,275,0xffffff);
        if (valor<=3)
            line (buffer, ancho/2+50,250,ancho/2+65,275,0xffffff);
        if (valor<=2)
            line (buffer, ancho/2+50,230,ancho/2+40,245,0xffffff);
        if (valor<=1)
            line (buffer,ancho/2+50,230,ancho/2+60,245,0xffffff);

        textprintf_ex(buffer, font, ancho-100,50, 0xffffff,makecol(0,0,0), "Vidas: %d", valor);
        for (i=0;i<largo;i+=2)
             textprintf_ex(buffer, font, 10*i+ancho/2-85,400, 0xffffff,makecol(0,0,0), "%c", pal[i]);

        for (i=0;i<7;i++)
        {
            if (usadas[i]==0)
                break;
            if (usadas[i]>=65 && usadas[i]<=90)
                textprintf_ex(buffer, font, 9*i+ancho/2-85,220, 0xffffff,makecol(0,0,0), "%c", usadas[i]);
        }
        if (tipo==2)
        {
            textout_centre_ex(buffer,font, "JUGADOR 2: ",ancho/2,70,0xffffff, makecol(0,0,0));
        }
        textout_centre_ex(buffer,font, "ADIVINE LA PALABRA",ancho/2,100,0xffffff, makecol(0,0,0));
        blit (buffer,screen,0,0,0,0,ancho,alto);
        tecla=readkey();
        asc=tecla-32;
        esta=0;
        for (i=0;i<largo;i+=2)
        {
            if (palabra[i]==asc)
            {
                if (pal[i]!=asc)
                {
                    pal[i]=asc;
                    pal[i+1]=0;
                    total+=1;
                }
                esta=1;
            }
        }
        esta2=0;
        if (esta!=1)
        {
            valor=valor-1;
            for (i=0;i<largo;i++)
            {
                if (usadas[i]==asc)
                {
                    esta2=1;
                    break;
                }
            }
            if (esta2==0)
            {
                usadas[l]=asc;
                l+=1;
            }
        }

    }

    if (valor==0)
    {
        line(buffer,ancho/2-20,300,ancho/2+20,300,0xffffff);
        line(buffer,ancho/2,300,ancho/2,180,0xffffff);
        line(buffer,ancho/2,180,ancho/2+50,180,0xffffff);
        line(buffer,ancho/2+50,180,ancho/2+50,200,0xffffff);
        circle(buffer,ancho/2+50,210,10,0xffffff);
        line (buffer,ancho/2+50,220,ancho/2+50,250,0xffffff);
        line (buffer, ancho/2+50,250,ancho/2+35,275,0xffffff);
        line (buffer, ancho/2+50,250,ancho/2+65,275,0xffffff);
        line (buffer, ancho/2+50,230,ancho/2+40,245,0xffffff);
        line (buffer,ancho/2+50,230,ancho/2+60,245,0xffffff);
        textprintf_ex(buffer,font,ancho/2+44,204,0xffffff,makecol(0,0,0),"x");
        textprintf_ex(buffer,font,ancho/2+52,204,0xffffff,makecol(0,0,0),"x");
        textprintf_ex(buffer,font,ancho/2+46,210,0xffffff,makecol(0,0,0),"_");
        textprintf_ex(buffer, font, ancho-100,50, 0xffffff,makecol(0,0,0), "Vidas: %d", valor);
        textprintf_ex(buffer, font, ancho-140,70, 0xffffff,makecol(0,0,0), "JUEGO TERMINADO");
        blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
        rest(1300);
        clear_to_color(buffer,makecol(255,0,0));
        textout_centre_ex(buffer, font,"PERDISTE",ancho/2,100,makecol(0,0,0),0xedf3f3);
        textout_centre_ex(buffer, font,"LA PALABRA ERA: ",ancho/2,150,makecol(0,0,0),0xedf3f3);

        for (i=0;i<largo;i+=2)
             textprintf_ex(buffer, font, 10*i+ancho/2-110,300, makecol(0,0,0),makecol(255,0,0), "%c", palabra[i]);

        blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
        rest (1800);
    }
    if (total==(largo+1)/2)
    {
        clear_to_color(buffer,makecol(30,220,20));
        for (i=0;i<largo;i+=2)
             textprintf_ex(buffer, font, 10*i+ancho/2-110,300, makecol(0,0,0),makecol(30,220,20), "%c", pal[i]);

        textout_centre_ex(buffer, font,"GANASTE",ancho/2,100,makecol(0,0,0),0xedf3f3);
        blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
        rest (1800);
    }
}

int crearnumaleat(int mem[],int posicion)
{
    int menpos=0,s,i;
    while (menpos==0)
    {
        s=rand()%40;
        for (i=0;i<posicion;i++)
        {
            if (mem[i]==s)
                menpos=1;
        }
        menpos=1-menpos;
    }
    return s;
}
