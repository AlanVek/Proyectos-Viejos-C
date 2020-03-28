/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int i,j,h,t,aux,l,tam;
    printf ("Ingrese cantidad de datos: ");
    scanf ("%d",&j);
    int n[j];
    for (i=0;i<j;i++)
    {
        printf ("Ingrese dato: ");
        scanf ("%d",&n[i]);
    }

    for (h=0;h<j-1;h++)
    {
        for (t=h+1;t<j;t++)
        {
            if (n[h]<n[t])
            {
                aux=n[h];
                n[h]=n[t];
                n[t]=aux;
            }
        }
    }

    printf ("De mayor a menor: \n");
    for (l=0;l<j;l++)
    {
        printf ("/ %d /",n[l]);
    }
    printf ("/.\n");

    tam= sizeof(n)/sizeof(n[0]);
    printf ("El largo es %d.",tam);
    return 0;
}

