#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define n 100
#define ntotal 1000
#define p 0.3
void Limpiar_Vector (int Vector[],int largo);
float Varianza (int Vector[],int largo,float Promedio);
float Promedio (int Vector[],int largo);
int main()
{
    int i,j,Suma[ntotal];
    float Var,Prom,a;
    srand(time(NULL));
    Limpiar_Vector(Suma,ntotal);
    for (i=0;i<ntotal;i++)
    {
        for (j=0;j<n;j++)
        {
            a = rand()/(float) RAND_MAX;
          //  printf ("%f\n",a);
            if (a<=p)
                Suma[i]--;
            else
                if (a>=2*p)
                    Suma[i]++;
        }
    }
    Prom = Promedio(Suma,ntotal);
    Var = Varianza(Suma,ntotal,Prom);

    printf ("Promedio = %f.\nVarianza = %f",Prom,Var);
    return 0;

}
void Limpiar_Vector (int Vector[],int largo)
{
    int i;
    for (i=0;i<largo;i++)
        Vector[i] = 0;
}

float Varianza (int Vector[],int largo,float Promedio)
{
    int i;
    float suma=0;
    for (i=0;i<largo;i++)
    {
        suma += (Vector[i]-Promedio)*(Vector[i]-Promedio);
    }
    suma = suma/(largo-1);
    return sqrt(suma);
}
float Promedio (int Vector[],int largo)
{
    int i;
    float suma=0;
    for (i=0;i<largo;i++)
    {
        suma += Vector[i];
    }
    return (float)(suma/largo);
}
