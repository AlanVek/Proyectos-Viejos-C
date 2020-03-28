#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define largo 7
void cargar_produccion(int maquina[] );
int prod_menor_1000 (int maquina[]);
int prod_semanal(int maquina[]);
void mostrar_produccion (int maquina[]);
int i;
int main()
{
    int maquina1[largo],maquina2[largo], menos_1000_maq1, menos_1000_maq2,semanal_1,semanal_2;
    srand(time(NULL));

    cargar_produccion (maquina1);
    cargar_produccion (maquina2);

    menos_1000_maq1=prod_menor_1000(maquina1);
    menos_1000_maq2=prod_menor_1000(maquina2);

    semanal_1=prod_semanal(maquina1);
    semanal_2=prod_semanal(maquina2);

    printf ("-------------------------------------\n");
    printf ("MAQUINA 1:\n\n");
    mostrar_produccion(maquina1);
    printf ("\n\nDias con produccion menor a 1000: %d.",menos_1000_maq1);
    printf ("\nProduccion semanal total: %d.",semanal_1);
    printf ("\nProduccion promedio:%d.",semanal_1/largo);
    printf ("\n\nMAQUINA 2:\n\n");
    mostrar_produccion(maquina2);
    printf ("\n\nDias con produccion menor a 1000: %d.",menos_1000_maq2);
    printf ("\nProduccion semanal total: %d.",semanal_2);
    printf ("\nProduccion promedio:%d.\n",semanal_2/largo);
    printf ("-------------------------------------\n");

    return 0;
}
void cargar_produccion(int maquina[] )
{
    for (i=0;i<largo;i++)
    {
        maquina[i]=rand()%8000;
    }
}
int prod_menor_1000 (int maquina[])
{
    int suma=0;
    for (i=0;i<largo;i++)
    {
        if (maquina[i]<1000)
        {
            suma+=1;
        }
    }
    return suma;
}
int prod_semanal(int maquina[])
{
    int total=0;
    for (i=0;i<largo;i++)
    {
        total+=maquina[i];
    }
    return total;
}
void mostrar_produccion (int maquina[])
{
    for (i=0;i<largo;i++)
    {
        printf ("%d/",maquina[i]);
    }
}
