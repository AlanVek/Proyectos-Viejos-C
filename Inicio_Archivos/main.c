#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    char nombre[100];
    printf ("Ingrese numero: ");
    scanf ("%d",&a);
    printf ("\nIngrese nombre: ");
    fgets (nombre,1000,stdin);

    printf ("%s",nombre);

    return 0;
}
