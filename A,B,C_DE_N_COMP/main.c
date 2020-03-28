#include <stdio.h>
#include <stdlib.h>
#define maximo 20
#define liminf 0
#define limsup 20
void cargar_vector (int vector[]);
void primero_y_ultimo_C (int vector1[],int vector2[],int vector3[]);
void mostrar_vector (int vector[]);
void pares_e_impares_C(int vector1[],int vector2[],int vector3[]);
int i;
int main()
{
    int A[maximo],B[maximo],C[maximo];
    cargar_vector (A);
    cargar_vector (B);
    printf ("Primer vector:\n\n");
    mostrar_vector (A);
    printf ("\n\nSegundo vector:\n\n");
    mostrar_vector (B);
    primero_y_ultimo_C (A,B,C);
    printf ("\n\n\nC[1]=A[1]+B[n]... :\n\n");
    mostrar_vector (C);
    pares_e_impares_C(A,B,C);
    printf ("\n\nC[i]=A[i] si i impar o C[i]=B[i] si i par:\n\n");
    mostrar_vector (C);
    printf("\n");

    return 0;
}
void cargar_vector (int vector[])
{
    for (i=0;i<maximo;i++)
    {
        vector[i]=rand()%(limsup-liminf+1);
    }
}
void primero_y_ultimo_C (int vector1[],int vector2[],int vector3[])
{
    for (i=0;i<maximo;i++)
    {
        vector3[i]=vector1[i]+vector2[maximo-i-1];
    }
}
void mostrar_vector (int vector[])
{
    for (i=0;i<maximo;i++)
    {
        printf ("%d/",vector[i]);
    }
}
void pares_e_impares_C(int vector1[],int vector2[],int vector3[])
{
    for (i=0;i<maximo;i++)
    {
        if (i%2==1)
        {
            vector3[i]=vector1[i];
        }
        else
        {
            vector3[i]=vector2[i];
        }
    }
}
