#include <stdio.h>
#include <stdlib.h>
#define maximo 500
void cargar_vector(int lista1[],int largo);
void cargar_posiciones(int lista5[],int lista2[],int listan[],int largo);
void copiar_vector (int lista3[],int lista4[],int largo);
void ordenar_vector (int n[],int largo);
void mostrar_vector(int veca[],int largo);
int i,j;
int main()
{
    int vector[maximo],posiciones[maximo],vector2[maximo],n;

    printf ("Ingrese cantidad: ");
    scanf ("%d",&n);
    printf ("\n");

    cargar_vector(vector,n);

    printf ("\nVector ingresado: ");
    mostrar_vector(vector,n);

    copiar_vector(vector,vector2,n);
    ordenar_vector(vector2,n);
    cargar_posiciones(vector2,vector,posiciones,n);

    printf ("\nPosiciones: ");
    mostrar_vector(posiciones,n);

    printf ("\n");

    return 0;
}
void cargar_vector(int lista1[],int largo)
{
    for (i=0;i<largo;i++)
    {
        printf ("Ingrese posicion %d: ",i+1);
        scanf ("%d",&lista1[i]);
        printf ("\n");
    }
}
void ordenar_vector (int n[],int largo)
{
    int t,aux;
    for (t=0;t<largo-1;t++)
    {
        for (j=t+1;j<largo;j++)
        {
            if (n[j]<n[t])
            {
                aux=n[t];
                n[t]=n[j];
                n[j]=aux;
            }
        }
    }
}
void cargar_posiciones(int lista5[],int lista2[],int listan[],int largo)
{
    int orden=1,esta;
    for (i=0;i<largo;i++)
    {
        esta=0;
        for (j=0;j<largo;j++)
        {
            if (lista5[i]==lista2[j])
            {
                lista2[j]=0;
                listan[j]=orden;
                esta=1;
            }
        }
        if (esta==1)
            orden+=1;
    }
}
void copiar_vector (int lista3[],int lista4[],int largo)
{
    for (i=0;i<largo;i++)
    {
        lista4[i]=lista3[i];
    }
}

void mostrar_vector(int veca[],int largo)
{
    for (i=0;i<largo;i++)
    {
        printf ("%d/",veca[i]);
    }
}
