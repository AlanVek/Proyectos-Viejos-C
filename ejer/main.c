#include <stdio.h>
#include <stdlib.h>
void print_fecha (int fecha,int *anio,int *mes,int *dia);
int main()
{
    int fecha,anio,mes,dia;
    printf ("Ingrese fecha: ");
    scanf ("%d",&fecha);
    print_fecha (fecha,&anio,&mes,&dia);

    printf ("Año: %d\nMes:%d\nDia:%d",anio,mes,dia);
    return 0;
}

void

 print_fecha (int fecha,int *anio,int *mes,int *dia)
{
    *dia=fecha%100;
    *mes=(fecha%10000)/100;
    *anio=fecha/10000;

}
