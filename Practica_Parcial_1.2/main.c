#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define largo 10
void cargar_consumo(int autox[]);
int mayor_consumo (int autox[]);
int consumo_total(int autox[]);
void mostrar_consumos (int autox[]);
int comparar (int autox1[],int autox2[]);
int i;
int main()
{
    int auto1[largo],auto2[largo], max_total=0,menor_consumo_total=0,ganador;
    srand(time(NULL));

    cargar_consumo (auto1);
    cargar_consumo (auto2);

    if (mayor_consumo(auto1)>mayor_consumo(auto2))
        max_total=1;
    if (mayor_consumo(auto1)<mayor_consumo(auto2))
        max_total=2;

    if (consumo_total(auto1)<consumo_total(auto2))
        menor_consumo_total=1;
    if (consumo_total(auto1)>consumo_total(auto2))
        menor_consumo_total=2;

    ganador=comparar(auto1,auto2);

    printf ("------------------------------------------------------\n\n");
    printf ("AUTO 1:\n");
    mostrar_consumos(auto1);
    printf ("\n\nAUTO 2:\n");
    mostrar_consumos(auto2);
    if (menor_consumo_total!=0)
        printf ("\n\nEl que tuvo menor promedio: Auto %d ",menor_consumo_total);
    else
        printf ("\n\nAmbos tuvieron el mismo promedio.");

    if (max_total!=0)
        printf ("\nEl auto con mayor consumo en un tramo de 250km. fue: Auto %d",max_total);
    else
        printf ("\nAmbos maximos fueron iguales.");

    if (ganador!=0)
        printf ("\nEl que tuvo mayor cantidad de menor consumo: Auto %d\n",ganador);
    else
        printf ("\nAmbos tuvieron la misma cantidad de menor consumo.\n");

    printf ("\n------------------------------------------------------\n");

    return 0;
}
void cargar_consumo(int autox[] )
{
    for (i=0;i<largo;i++)
    {
        autox[i]=rand()%11+12;
    }
}
int mayor_consumo(int autox[])
{
    int max=autox[0];
    for (i=1;i<largo;i++)
    {
        if (autox[i]>max)
        {
            max=autox[i];
        }
    }
    return max;
}
int consumo_total(int autox[])
{
    int total=0;
    for (i=0;i<largo;i++)
    {
        total+=autox[i];
    }
    return total;
}
void mostrar_consumos (int autox[])
{
    for (i=0;i<largo;i++)
    {
        printf ("%d/",autox[i]);
    }
}
int comparar (int autox1[], int autox2[])
{
    int suma1=0,suma2=0,ganador=0;
    for (i=0;i<largo;i++)
    {
        if (autox1[i]<autox2[i])
            suma1+=1;
        if (autox1[i]>autox2[i])
            suma2+=1;
    }
    if (suma1>suma2)
        ganador=1;
    if (suma1<suma2)
        ganador=2;
    return ganador;
}
