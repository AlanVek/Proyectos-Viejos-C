#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n[10],suma,promedio;
    int i;
    suma=0;
    for (i=0;i<10;i++)
    {
        printf ("Ingrese nota: ");
        scanf ("%f",&n[i]);
        suma+=n[i];
    }
    promedio=(float) suma/10;
    printf ("\nEl promedio es: %.2f",promedio);
    printf ("\nLas notas mayores al promedio son:\n");
    for (i=0;i<10;i++)
    {
        if (n[i]>promedio)
            printf ("%.2f\n",n[i]);
    }
}
