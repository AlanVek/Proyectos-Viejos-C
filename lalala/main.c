#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void sumar_vectores(int vector_1[],int vector_2[],int masmas[],int n);
void mostrar_vector(int vector[],int n);
void cargar_vector (int vector[],int largo);
void limpiar_vector (int vector[],int largo);
int i;
int main()
{
    int n;
    printf ("Ingrese cantidad digitos: ");
    scanf ("%d",&n);
    printf ("\n");

    int vector1[n],vector2[n],vector_suma[n+1];

    limpiar_vector (vector_suma,n+1);

    printf ("Primer numero:\n");
    cargar_vector(vector1,n);
    printf ("Segundo numero:\n");
    cargar_vector(vector2,n);

    sumar_vectores(vector1,vector2,vector_suma,n);
    printf ("\n");

    printf ("Suma: ");
    mostrar_vector(vector_suma,n+1);

    printf ("\n");

    return 0;
}
void sumar_vectores(int vector_1[],int vector_2[],int masmas[],int n)
{
    int sumas;
    for (i=n-1;i>=0;i--)
    {
        sumas=vector_1[i]+vector_2[i];
        if (sumas>=10)
        {
            masmas[i+1]+=(sumas%10);
            masmas[i]+=1;
        }
        else
            masmas[i+1]+=sumas;
    }
}
void mostrar_vector(int vector[],int largo)
{
    for (i=0;i<largo;i++)
    {
        if (!(i==0 && vector[i]==0))
            printf ("%d",vector[i]);
    }
}
void cargar_vector (int vector[],int largo)
{
    for (i=0;i<largo;i++)
    {
        printf ("Ingrese posicion %d: ",i+1);
        scanf ("%d",&vector[i]);
        printf ("\n");
    }
}
void limpiar_vector (int vector[],int largo)
{
    for (i=0;i<largo;i++)
    {
        vector[i]=0;
    }
}
