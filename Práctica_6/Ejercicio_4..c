#include <stdio.h>
int longitud(char n[]);
void imprimir_reves(char n[],int longitud);
void que_comparten(char cad1[],char cad2[],int i, int t);
int main()

{
    char cad1[100],cad2[100];
    int longit1,longit2;
    printf ("Ingrese la primera cadena: ");
    gets(cad1);
    printf ("\nIngrese la segunda cadena: ");
    gets(cad2);
    printf ("\n");

    printf ("%s\n",cad1);
    longit1=longitud(cad1);
    imprimir_reves(cad1,longit1);
    printf ("\nSu longitud es %d\n\n",longit1);
    longit2=longitud(cad2);


    printf ("%s\n",cad2);
    imprimir_reves(cad2,longit2);
    printf ("\nSu longitud es %d\n\n",longit2);

    que_comparten(cad1,cad2,longit1,longit2);


}
int longitud(char n[])
{
    int i=0,longit=0;
    while (n[i]!=0)
    {
        longit+=1;
        i+=1;
    }
    return longit;
}
void imprimir_reves(char n[],int longitud)
{
    int i;
    for (i=longitud-1;i>-1;i--)
    {
        printf ("%c",n[i]);
    }
}
void que_comparten(char cad1[],char cad2[],int i, int t)
{
    int m,s,k,l,h,g,f,q,x=0;
    for (m=0;m<t;m++)
    {
        for (h=0;h<i;h++)
        {
            if (cad1[h]==cad2[m])
            {
                x=1;
                s=m;
                g=m;
                for (l=h;l<i;l++)
                {
                    if (cad1[l]!=cad2[g] || (g==t))
                    {
                        k=g;
                        break;
                    }
                    else
                    {
                        if (l==i-1)
                            k=g+1;
                        else
                            g++;
                    }
                }
                if ((k-s)>=3)
                {
                    printf ("Son iguales desde la posicion %d de la segunda cadena hasta la posicion %d.\n",s,k-1);
                    printf ("La coincidencia es: ");
                    for (f=s;f<k;f++)
                    {
                        printf ("%c",cad2[f]);
                    }
                    printf ("\n");
                    q=1;
                    break;
                }
                else
                {
                    printf ("\nLo que comparten tiene menos de tres caracteres.\n");
                    q=1;
                    break;
                }


            }
             if (q==1)
                break;
        }
        if (q==1)
            break;

    }
    if(x==0)
        printf ("No comparten nada.\n");


}



