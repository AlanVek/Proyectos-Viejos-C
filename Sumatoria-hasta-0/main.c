#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,suma;
    printf ("Ingrese uno a sumar. Se termina cuando ingresa 0: ");
    scanf ("%f",&a);
    suma=a;
    while (a!=0)
    {
        printf ("\nIngrese uno a sumar. Se termina cuando ingresa 0: ");
        scanf ("%f",&a);
        suma+=a;
    }
    printf ("\nLa suma es %.2f\n",suma);
    return 0;
}
