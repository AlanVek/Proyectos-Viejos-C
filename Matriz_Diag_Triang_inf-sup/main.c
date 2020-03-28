#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define liminf 0
#define limsup 1
#define maximo 100
void cargar_matriz(int vector[maximo][maximo],int fil, int col);
void mostrar_matriz(int vector[maximo][maximo],int fil, int col);
int es_diagonal (int vector[maximo][maximo],int fil, int col);
int es_triangular_superior (int vector[maximo][maximo],int fil, int col);
int es_triangular_inferior (int vector[maximo][maximo],int fil, int col);
int i,j;
int main()
{
    int n;
    int matriz[maximo][maximo];
    srand(time(NULL));
    printf ("Ingrese cantidad de filas y columnas de matriz cuadrada: ");
    scanf ("%d",&n);

    cargar_matriz(matriz,n,n);
    printf ("\nMatriz generada:\n");
    mostrar_matriz(matriz,n,n);

    if (es_diagonal(matriz,n,n)==1)
        printf ("\nLa matriz es diagonal.\n");
    else
    {
        if (es_triangular_inferior(matriz,n,n)==1)
            printf ("\nLa matriz es triangular inferior.\n");
        else
        {
            if (es_triangular_superior(matriz,n,n)==1)
                printf ("\nLa matriz es triangular superior.\n");
            else
                printf ("\nLa matriz no es diagonal ni triangular superior ni triangular inferior.\n");
        }
    }


    return 0;
}
void cargar_matriz(int vector[maximo][maximo],int fil, int col)
{
    int a;
    int b;
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            a=liminf+(rand()%(limsup-liminf+1));
            b=rand()%2;
            a*=pow(-1,b);
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
int es_diagonal (int vector[maximo][maximo],int fil, int col)
{
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            if (i!=j && vector[i][j]!=0)
                return 0;
        }
    }
    return 1;
}
int es_triangular_inferior (int vector[maximo][maximo],int fil, int col)
{
    for (i=0;i<fil;i++)
    {
        for (j=i+1;j<col;j++)
        {
            if (vector[i][j]!=0)
                return 0;
        }
    }
    return 1;
}
int es_triangular_superior (int vector[maximo][maximo],int fil, int col)
{
    for (i=0;i<fil;i++)
    {
        for (j=0;j<i;j++)
        {
            if (vector[i][j]!=0)
                return 0;
        }
    }
    return 1;

}
