#include <stdio.h>
#include <stdlib.h>
#define largototal 5
int armstrong (int numero, int vector[]);
void generar_numeros(int numero, int vector[]);
void limpiar_vector(int vector[]);
void armstrong_en_rango(int rango);
int main()
{
    int rango;
    printf ("Ingrese rango: ");
    scanf ("%d",&rango);

    armstrong_en_rango(rango);

    return 0;
}
int armstrong (int numero,int vector[])
{
    int suma=0;
    int h;
    for (h=0;h<largototal;h++)
    {
        suma+=vector[h]*vector[h]*vector[h];
    }
    if (suma==numero)
        return 1;
    else
        return 0;

}
void generar_numeros(int numero, int vector[])
{
    int j=0;
    int i;
    int largo_corrida=numero*10;
    i=10;
    while (i<largo_corrida)
    {
        if (numero==0)
            break;
        else{
            vector[j]=(numero%i)/(i/10);
            numero=numero-numero%i;
            j+=1;
        }
        i=i*10;
    }
}
void limpiar_vector(int vector[])
{
    int m;
    for (m=0;m<largototal;m++)
    {
        vector[m]=0;
    }
}
void armstrong_en_rango(int rango)
{
    int t;
    int vector_armstrong[largototal];
    limpiar_vector(vector_armstrong);
    for (t=0;t<rango;t++)
    {
        generar_numeros(t,vector_armstrong);
        if (armstrong(t,vector_armstrong)==1)
            printf ("%d/",t);
        limpiar_vector(vector_armstrong);
    }
}
