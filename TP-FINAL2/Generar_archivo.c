#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maximo 99999
#define limsup 5000
void ordenar_vector (int vector[],int largo);
int i,j;
int main()
{
    srand (time(NULL));
    FILE *txt;
    txt=fopen ("numeros_a_ordenar.txt","wt+");
    int vector_numeros[maximo];
    for (i=0;i<maximo;i++)
    {
        vector_numeros[i]=rand()%(limsup+1);
    }
    ordenar_vector(vector_numeros,maximo);
    for (i=0;i<maximo;i++)
    {
        fprintf (txt,"%d\n",vector_numeros[i]);
    }

}

void ordenar_vector (int vector[],int largo)
{
    int aux;
    for (i=0;i<largo-1;i++)
    {
        for (j=i+1;j<largo;j++)
        {
            if (vector[i]>vector[j])
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
}
