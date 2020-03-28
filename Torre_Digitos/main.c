#include <stdio.h>
#include <stdlib.h>

void crear_torre(int filas);
int main()
{
    int filas;
    printf ("Ingrese filas: ");
    scanf ("%d",&filas);
    printf ("\n\n");
    crear_torre(filas);
    printf ("\n");
    return 0;
}
void crear_torre(int filas)
{
    int inicio=1,numero=1,i,j,espacios=(filas-1)*2+50;
    for (i=0;i<filas;i++)
    {
        for (j=0;j<espacios;j++)
        {
            printf (" ");
        }
        for (j=0;j<(2*inicio-1)/2+1;j++)
        {
            printf ("%d ",numero);
            numero+=1;
        }
        for (j=0;j<(2*inicio-1)/2;j++)
        {
            printf ("%d ",numero-2);
            numero-=1;
        }
        printf ("\n");
        inicio+=1;
        numero=inicio;
        espacios-=2;
    }
}
