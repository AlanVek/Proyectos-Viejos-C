#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int legajo;
    char nombre[50];
    float cuota;
} Alumno;
int main()
{
    Alumno a1;
    printf ("Legajo: ");
    scanf ("%d",&a1.legajo);
    printf ("\nNombre: ");
    scanf ("%s",&a1.nombre);
    printf ("\nCuota: ");
    scanf ("%f",&a1.cuota);
    printf ("Legajo: %d, Nombre: %s, Cuota: %.2f",a1.legajo,a1.nombre,a1.cuota);
    return 0;
}
