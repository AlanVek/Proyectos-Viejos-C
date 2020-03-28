#include <stdio.h>

int main()

{
    char cad1[100],cad2[100];
    int j,i,t,m,l,h,iguales,g;
    printf ("Ingrese la primera cadena: ");
    scanf ("%s",cad1);
    printf ("\nIngrese la segunda cadena: ");
    scanf ("%s",cad2);
    printf ("\n");
    i=0;
    while (i<100)
    {
        if (cad1[i]==0)
        {
            break;
        }
        i++;
    }

    for (j=i-1;j>=0;j--)
    {
        printf ("%c",cad1[j]);
    }
    printf ("\nSu longitud es %d\n\n",i);

    t=0;
    while (t<100)
    {
        if (cad2[t]==0)
        {
            break;
        }
        t++;
    }

    for (j=t-1;j>=0;j--)
    {
        printf ("%c",cad2[j]);
    }
    printf ("\nSu longitud es %d\n\n",t);

    for (m=0;m<t;m++)
    {
        if (cad2[m]==cad1[0])
        {
            iguales=1;
            g=0;
            h=m;
            for (l=m;l<i+m;l++)
            {
                if (cad2[l]!=cad1[g])
                    iguales=0;
                g++;
            }
            if (iguales==1)
            {
                printf ("La cadena 1 esta dentro de la segunda desde la posición %d hasta la posición %d",h,i+m-1);
            }
        }
    }
}








