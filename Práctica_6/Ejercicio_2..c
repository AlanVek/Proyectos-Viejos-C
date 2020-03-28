#include <stdio.h>
#include <stdlib.h>
int i;
float maximo(float lista[]);
int main()
{
    float t,n[10];
    for (i=0;i<10;i++)
    {
        printf ("Ingrese dato: ");
        scanf ("%f",&n[i]);
    }
    t=maximo(n);
    printf ("El maximo es: %.2f",t);
    return 0;
}
float maximo(float lista[])
{
    float max;
    max=lista[0];
    for (i=1;i<10;i++)
    {
        if (lista[i]>max)
        {
            max=lista[i];
        }
    }
    return max;
}

