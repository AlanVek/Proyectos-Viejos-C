#include <stdio.h>
#include "Empleados.h"

void Ordenar_Por_Sueldo (Empleado vectorr[],int cantidad)
{
    int i,j;
    Empleado aux;
    for (i=0;i<cantidad-1;i++)
    {
        for (j=i+1;j<cantidad;j++)
        {
            if (vectorr[j].sueldo<vectorr[i].sueldo)
            {
                aux=vectorr[j];
                vectorr[j]=vectorr[i];
                vectorr[i]=aux;
            }
        }
    }
}
void Cargar_Datos (FILE *txt,Empleado vector[],int *cantidad)
{
    (*cantidad)=0;
    fscanf (txt,"%d",&vector[0].legajo);
    fgetc(txt);
    fgets (vector[0].nombre,50,txt);
    fscanf (txt," %c %f",&vector[0].categoria,&vector[0].sueldo);
    while (!(feof(txt)))
    {
        *cantidad=*cantidad+1;
        fscanf (txt,"%d",&vector[*cantidad].legajo);
        fgetc(txt);
        fgets (vector[*cantidad].nombre,50,txt);
        fscanf (txt," %c %f",&vector[*cantidad].categoria,&vector[*cantidad].sueldo);
    }
}
void Cambiar_Sueldos (FILE*txt, Empleado vector[],int cantidad)
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        if (vector[i].categoria=='A'||vector[i].categoria=='B')
            vector[i].sueldo*=1.05;
        if (vector[i].categoria=='C')
            vector[i].sueldo*=1.1;
        if (vector[i].categoria=='D')
            vector[i].sueldo*=1.2;
    }
}
void Actualizar_Archivo (FILE*txt,Empleado vector[],int cantidad)
{
    int i;
    for (i=0;i<cantidad;i++)
        fprintf (txt,"%05d  %s %c %f\n",vector[i].legajo,vector[i].nombre,vector[i].categoria,vector[i].sueldo);
}
void Cargar_Binarios (FILE *tec, FILE *admin, Empleado vector[], int cantidad)
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        if (vector[i].categoria=='A'|| vector[i].categoria=='C')
        {
           fwrite(&vector[i],1,sizeof(Empleado),admin);
        }
        else
        {
            fwrite(&vector[i],1,sizeof(Empleado),tec);
        }
    }
}
void Mostrar_Categoria_X (Empleado vector_ordenado[], char cat, int cantidad)
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        if (vector_ordenado[i].categoria==cat)
            printf ("%05d  %s %c %f\n",vector_ordenado[i].legajo,vector_ordenado[i].nombre,vector_ordenado[i].categoria,vector_ordenado[i].sueldo);
    }
}
float Promedio (Empleado vector_ordenado[],int cantidad)
{
    int i;
    float promedio=0;
    for (i=0;i<cantidad;i++)
        promedio+=vector_ordenado[i].sueldo;
    promedio/=cantidad;
    return (promedio);
}
void Mayores_A_Promedio (Empleado vector_ordenado[], float promedio, int cantidad)
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        if (vector_ordenado[i].sueldo>promedio)
            printf ("%05d  %s %c %f\n",vector_ordenado[i].legajo,vector_ordenado[i].nombre,vector_ordenado[i].categoria,vector_ordenado[i].sueldo);
    }
}
