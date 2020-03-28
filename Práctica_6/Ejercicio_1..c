#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n[10],suma,a;
    int i;
    for (i=0;i<10;i++)
    {
        printf ("Ingrese dato: ");
        scanf ("%f",&n[i]);
    }
    for (i=0;i<10;i++)
    {
        suma+=n[i];
    }
    a=(float) suma/10;
    printf ("El promedio es %.2f",a);
}
