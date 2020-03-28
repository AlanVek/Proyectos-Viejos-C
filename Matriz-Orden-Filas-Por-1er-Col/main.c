#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define maximo 100
#define liminf 0
#define limsup 9
void mostrar_matriz(float vector[maximo][maximo],int fil, int col);
void cargar_matriz(float vector[maximo][maximo],int fil, int col);
void ordenar_filas (float vector[maximo][maximo],int filas, int columnas);
void ordenar_si_iguales(float vector[maximo][maximo],int filas, int columnas);
void cambiar_filas(float vector[maximo][maximo],int fila1, int fila2, int colum);
int i,j;
int main()
{
    int filas,columnas;
    float matriz[maximo][maximo];
    srand(time(NULL));

    printf ("Ingresar filas: ");
    scanf ("%d",&filas);

    printf ("\nIngresar columnas: ");
    scanf ("%d",&columnas);

    cargar_matriz(matriz,filas,columnas);

    printf ("\n\nMatriz generada:\n");
    mostrar_matriz(matriz,filas,columnas);

    ordenar_filas(matriz,filas,columnas);

    ordenar_si_iguales(matriz,filas,columnas);

    printf ("\n\nMatriz con filas de menor a mayor:\n");

    mostrar_matriz(matriz,filas,columnas);

    return 0;
}
void cargar_matriz(float vector[maximo][maximo],int fil, int col)
{
    float a;
    int b;
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            a=liminf+rand()%(limsup-liminf+1);
            b=rand()%2;
            if (a!=0)
                a*=pow(-1,b);
            vector[i][j]=a;
        }
    }
}
void mostrar_matriz(float vector[maximo][maximo],int fil, int col)
{
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            printf ("%.2f   ",vector[i][j]);
        }
        printf ("\n");
    }
}

void ordenar_filas (float vector[maximo][maximo],int filas, int columnas)
{
    int m,s;
    for (m=0;m<filas-1;m++)
    {
        for (s=m+1;s<filas;s++)
        {
            if (vector[m][0]>vector[s][0])
            {
                cambiar_filas(vector,m,s,columnas);
            }
        }
    }
}
void ordenar_si_iguales (float vector[maximo][maximo],int filas, int columnas)
{
    int t;
    for (i=0;i<filas-1;i++)
    {
        for (j=i+1;j<filas;j++)
        {
            t=0;
            while ((vector[i][t]==vector[j][t]) && t<columnas)
            {
                t++;
            }
            if (t<columnas && vector[i][t]>vector[j][t])
            {
                cambiar_filas(vector,i,j,columnas);
            }
        }
    }
}

void cambiar_filas(float vector[maximo][maximo],int fila1, int fila2, int colum)
{
    int f;
    float vector_aux[maximo];
    for (f=0;f<colum;f++)
    {
        vector_aux[f]=vector[fila1][f];
    }
    for (f=0;f<colum;f++)
    {
        vector[fila1][f]=vector[fila2][f];
    }
    for (f=0;f<colum;f++)
    {
        vector[fila2][f]=vector_aux[f];
    }

}
