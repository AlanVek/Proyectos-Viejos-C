#include <stdio.h>
#include <stdlib.h>
#define maximo 500
#define cant_notas 5
typedef struct
{
    char nombre[50];
    float notas[maximo];
    int cantidad;
} Alumno;

float calcular_promedio (float vector[],int largo);
void cargar_notas (Alumno vector[], int i);
int j;
int main()
{
    Alumno vector_alumnos[maximo];
    int i, total_alumnos=0;
    int opcion=1;
    float prom;
    while (opcion!=0)
    {
        printf ("Ingrese nombre: ");
        fflush(stdin);
        gets (vector_alumnos[total_alumnos].nombre);

        cargar_notas (vector_alumnos,total_alumnos);
        total_alumnos+=1;

        printf ("\nSi desea terminar, presione 0. Si no, cualquier otro numero: ");
        scanf ("%d",&opcion);

        printf ("\n");
    }

    for (i=0;i<total_alumnos;i++)
    {
        prom=calcular_promedio (vector_alumnos[i].notas,vector_alumnos[i].cantidad);
        if (prom!=-1)
            printf ("\n\nEl promedio de %s es %.2f\n",vector_alumnos[i].nombre,prom);
        else
            printf ("\nNo se ingresaron datos de %s.\n",vector_alumnos[i].nombre);
    }

    return 0;
}
float calcular_promedio (float vector[],int largo)
{
    int suma=0;
    if (largo==0)
        return -1;

    for (j=0;j<largo;j++)
    {
        suma+=vector[j];
    }
    return (float)suma/j;
}
void cargar_notas (Alumno vector_alumnos[],int i)
{
    j=0;
    printf ("\nIngrese notas");
    while (1!=0)
    {
        printf ("\n\nIngrese: ");
        scanf ("%f",&vector_alumnos[i].notas[j]);
        while (vector_alumnos[i].notas[j]>10 || (vector_alumnos[i].notas[j]!=-1 && vector_alumnos[i].notas[j]<0))
        {
            printf ("\nLa nota ingresada no es correcta. Intente de nuevo: ");
            scanf ("%f",&vector_alumnos[i].notas[j]);
        }
        if (vector_alumnos[i].notas[j]==-1)
        {
            vector_alumnos[i].cantidad=j;
            break;
        }
        else
            j+=1;
    }
}
