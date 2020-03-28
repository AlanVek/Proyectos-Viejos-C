#include <stdio.h>
#include <stdlib.h>
#define liminf 0
#define limsup 10
#define maximo 100
#include <math.h>
#include <time.h>
void trasponer_matriz(float vector[maximo][maximo],float vector_copia[maximo][maximo],int dim);
void cargar_matriz(float vector[maximo][maximo],int dim);
float determinante (float vector[maximo][maximo],int dim);
void matriz_adjun(float vector[maximo][maximo],float vector_adj[maximo][maximo],int dim);
void mostrar_matriz(float vector[maximo][maximo],int dim);

int i,j;
int main()
{
    int n;
    float matriz[maximo][maximo],matriz_adjunta[maximo][maximo],det;
    float matriz_inversa[maximo][maximo];
    srand (time(NULL));

    printf ("Ingrese dimension: ");
    scanf ("%d",&n);

    while (n!=2 && n!=3)
    {
        printf ("\nSolo puede ser 2 o 3. Intente de nuevo: ");
        scanf ("%d",&n);
    }

    printf ("\n");

    cargar_matriz(matriz,n);
    printf ("Matriz generada:\n\n");
    mostrar_matriz(matriz,n);

    if (determinante(matriz,n)==0)
    {
        printf ("\n\nLa matriz no es inversible.\n");
        exit(9);
    }

    matriz_adjun(matriz,matriz_adjunta,n);

    trasponer_matriz(matriz_adjunta,matriz_inversa,n);

    det=determinante(matriz,n);

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            matriz_inversa[i][j]= (float) matriz_inversa[i][j]/det;
        }
    }

    printf ("\n");

    printf ("Matriz inversa:\n\n");
    mostrar_matriz(matriz_inversa,n);
    printf ("\n");

    return 0;
}
void trasponer_matriz(float vector[maximo][maximo],float vector_copia[maximo][maximo],int dim)
{
    for (i=0;i<dim;i++)
    {
        for (j=0;j<dim;j++)
        {
            vector_copia[j][i]= vector[i][j];
        }
    }
}
void cargar_matriz(float vector[maximo][maximo],int dim)
{
    float a;
    int b;
    for (i=0;i<dim;i++)
    {
        for (j=0;j<dim;j++)
        {
            a=liminf+(rand()%(10*(limsup-liminf+1)))*0.1;
            b=rand()%2;
            a*=pow(-1,b);
            vector[i][j]=a;
        }
    }
}
float determinante (float vector[maximo][maximo],int dim)
{
    if (dim==2)
    {
        return vector[0][0]*vector[1][1]-vector[0][1]*vector[1][0];
    }
    if (dim==3)
    {
        return vector[0][0]*(vector[1][1]*vector[2][2]-vector[1][2]*vector[2][1])-vector[0][1]*(vector[1][0]*vector[2][2]-vector[1][2]*vector[2][0]) + vector[0][2]*(vector[1][0]*vector[2][1]-vector[1][1]*vector[2][0]);
    }
}
void matriz_adjun(float vector[maximo][maximo],float vector_adj[maximo][maximo],int dim)
{
    if (dim==2)
    {
        vector_adj[0][1]=(-1)*vector[1][0];
        vector_adj[1][0]=(-1)*vector[0][1];
        vector_adj[0][0]=vector[1][1];
        vector_adj[1][1]=vector[0][0];
    }
    if (dim==3)
    {
        vector_adj[0][0]= vector[1][1]*vector[2][2]-vector[1][2]*vector[2][1];
        vector_adj[0][1]=(-1)*(vector[1][0]*vector[2][2]-vector[1][2]*vector[2][0]);
        vector_adj[0][2]=vector[1][0]*vector[2][1]-vector[1][1]*vector[2][0];
        vector_adj[1][0]=(-1)*(vector[0][1]*vector[2][2]-vector[0][2]*vector[2][1]);
        vector_adj[1][1]=vector[0][0]*vector[2][2]-vector[0][2]*vector[2][0];
        vector_adj[1][2]=(-1)*(vector[0][0]*vector[2][1]-vector[0][1]*vector[2][0]);
        vector_adj[2][0]=vector[0][1]*vector[1][2]-vector[0][2]*vector[1][1];
        vector_adj[2][1]=(-1)*(vector[0][0]*vector[1][2]-vector[0][2]*vector[1][0]);
        vector_adj[2][2]=vector[0][0]*vector[1][1]-vector[0][1]*vector[1][0];
    }
}
void mostrar_matriz(float vector[maximo][maximo],int dim)
{
    for (i=0;i<dim;i++)
    {
        for (j=0;j<dim;j++)
        {
            printf (" %.3f   ",vector[i][j]);
        }
        printf ("\n");
    }
}

