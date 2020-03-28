#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maximo 100
#define liminf 0
#define limsup 10
void cargar_matriz_manual (int vector[maximo][maximo],int fil, int col);
void cargar_matriz_automatico (int vector[maximo][maximo],int fil, int col);
void matriz_a_archivo (int vector[maximo][maximo],int fil, int col,FILE *archivo);
float promedio_total (int vector[maximo][maximo],int fil, int col);
void mostrar_matriz(int vector[maximo][maximo],int fil, int col);
int i,j;
int main()
{
    int cant_al, cant_mat,opcion;
    int matriz[maximo][maximo];
    FILE *archivo;
    srand (time(NULL));
    archivo=fopen ("alumnos-y-notas.txt","wt+");
    if (archivo==NULL)
    {
        printf ("Error abriendo el archivo.");
        exit (9);
    }
    printf ("Ingrese cantidad de alumnos: ");
    scanf ("%d",&cant_al);
    printf ("\nIngrese cantidad de materias: ");
    scanf ("%d",&cant_mat);
    printf ("\nIngrese 1 para cargar matriz manualmente o 2 para hacerlo automaticamente: ");
    scanf ("%d",&opcion);
    if (opcion==1)
        cargar_matriz_manual (matriz,cant_al,cant_mat);
    else
        cargar_matriz_automatico (matriz,cant_al,cant_mat);
    printf ("\n");
    mostrar_matriz(matriz,cant_al,cant_mat);
    printf ("\n");
    matriz_a_archivo (matriz,cant_al,cant_mat,archivo);
    printf ("\nPromedio total: %.2f",promedio_total(matriz,cant_al,cant_mat));
    fclose (archivo);
    return 0;
}
void cargar_matriz_manual (int vector[maximo][maximo],int fil, int col)
{
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            printf ("Ingrese posicion [%d,%d]: ",i+1,j+1);
            scanf ("%d",&vector[i][j]);
            while (vector[i][j]<0 || vector[i][j]>10)
            {
                printf ("\nNota incorrecta. Intente de nuevo: ");
                scanf ("%d",&vector[i][j]);
            }
        }
    }
}
void matriz_a_archivo (int vector[maximo][maximo],int fil, int col,FILE *archivo)
{
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            fprintf (archivo,"%d   ",vector[i][j]);
        }
        fprintf (archivo,"\n");
    }
}
float promedio_total (int vector[maximo][maximo],int fil, int col)
{
    int suma=0;
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            suma+=vector[i][j];
        }
    }
    return (float) suma/(fil*col);
}
void cargar_matriz_automatico (int vector[maximo][maximo],int fil, int col)
{
    int a;

    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            a=liminf+(rand()%(limsup-liminf+1));
            vector[i][j]=a;
        }
    }
}
void mostrar_matriz(int vector[maximo][maximo],int fil, int col)
{
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            printf ("%d   ",vector[i][j]);
        }
        printf ("\n");
    }
}
