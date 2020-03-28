#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define cantidad 15
#define limite_sup 5
#define limite_inf 0
void cargar_vector (int vector[],int largo);
void ordenar_vector(int n[],int largo);
void cuanto_se_repite(int vector[],int repeticiones[],int largo);
void mostrar_vector (int vector[],int largo);
void imprimir_repeticiones (int vector[],int posiciones[],int posiciones_copia[],int largo);
void copiar_vector (int vector[],int vector_copia[],int largo);
int buscar_en_vector(int n,int vector_copia[],int cant);
int i;
int main()
{
    int numeros[cantidad],posic[cantidad],posic_copia[cantidad];
    srand(time(NULL));

    cargar_vector(numeros,cantidad);
    ordenar_vector(numeros,cantidad);

    printf ("Vector: ");
    mostrar_vector(numeros,cantidad);
    printf ("\n");

    cuanto_se_repite(numeros,posic,cantidad);
    copiar_vector(posic,posic_copia,cantidad);
    ordenar_vector(posic_copia,cantidad);

    printf ("\n");
    imprimir_repeticiones(numeros,posic,posic_copia,cantidad);

    printf ("\n");

    return 0;
}
void cargar_vector (int vector[],int largo)
{
    for (i=0;i<largo;i++)
    {
        vector[i]=limite_inf + rand()%(limite_sup-limite_inf+1);
    }
}
void ordenar_vector(int n[],int largo)
{
    int j,aux;
    for (i=0;i<largo-1;i++)
    {
        for (j=i+1;j<largo;j++)
        {
            if (n[j]>n[i])
            {
                aux=n[i];
                n[i]=n[j];
                n[j]=aux;
            }
        }
    }
}
void cuanto_se_repite(int vector[],int repeticiones[],int largo)
{
    int suma=1;
    for (i=1;i<largo;i++)
    {
        if (vector[i]!=vector[i-1])
        {
            repeticiones[i-1]=suma;
            suma=1;
        }
        else
        {
            suma+=1;
            repeticiones[i-1]=0;
        }
        if (i==largo-1)
        {
            repeticiones[i]=suma;
        }
    }
}
void mostrar_vector (int vector[],int largo)
{
    for (i=0;i<largo;i++)
    {
        printf ("%d/",vector[i]);
    }
}
void imprimir_repeticiones (int vector[],int posiciones[],int posiciones_copia[],int largo)
{
    int indice=0;
    for (i=0;i<largo;i++)
    {
        if (posiciones_copia[i]!=0)
        {
            indice=buscar_en_vector(posiciones_copia[i],posiciones,largo);
            printf ("%d se repite: %d veces.\n",vector[indice],posiciones_copia[i]);
        }
    }
}
void copiar_vector (int vector[],int vector_copia[],int largo)
{
    for (i=0;i<largo;i++)
    {
        vector_copia[i]=vector[i];
    }
}
int buscar_en_vector(int n,int vector_copia[],int cant)
{
    int h;
    for (h=0;h<cant;h++)
    {
        if (vector_copia[h]==n)
        {
            vector_copia[h]=0;
            break;
        }
    }
    return h;
}
