#include <stdio.h>
#include <stdlib.h>
int longitud(char n[]);
int main()
{
    char cad1[500],cad2[500];
    int longit1,longit2,suma,i,j;
    printf ("Ingrese primera cadena: ");
    gets(cad1);
    printf ("\nIngrese segunda cadena: ");
    gets (cad2);


    longit1=longitud(cad1);
    longit2=longitud(cad2);

    suma=0;

    for (i=0;i<longit1;i++)
    {
        for (j=0;j<longit2;j++)
        {
            if (cad1[i]==cad2[j])
            {
                cad2[j]=0;
                suma+=1;
                break;
            }
        }
    }

    if (suma==longit1)
        printf ("\nSon anagramas.\n");

    else
        printf ("\nNo son anagramas.\n");


    return 0;
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
