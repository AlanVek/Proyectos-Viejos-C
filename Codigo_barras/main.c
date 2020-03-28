#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define digitos 13
void cargar_codigo(int codigo[],int largo);
void mostrar_codigo(int codigo[],int largo);
void ingresar_codigo(int codigo[],int largo);
int ver_si_ultimo_digito_es_valido(int codigo[],int largo);
int i;
int main()
{
   int codigo[digitos],opcion;
   srand(time(NULL));
   printf ("Ingrese 1 para cargar codigo manualmente o 0 para cargarlo automaticamente: ");
   scanf ("%d",&opcion);
   if (opcion==0){
        cargar_codigo(codigo,digitos);}
   else
        ingresar_codigo(codigo,digitos);

   printf ("Codigo de barras: ");
   mostrar_codigo(codigo,digitos);
   printf ("\n\n");
   if (ver_si_ultimo_digito_es_valido(codigo,digitos)==1)
   {
       printf ("||Es valido||");
   }
   else
   {
       printf ("||No es valido||");
   }
   printf ("\n");
   return 0;
}
void cargar_codigo(int codigo[],int largo)
{
    for (i=0;i<largo;i++)
    {
        codigo[i]=rand()%10;
    }
}

void mostrar_codigo(int codigo[],int largo)
{
    for (i=0;i<largo;i++)
    {
        printf ("%d/",codigo[i]);
    }
}
int ver_si_ultimo_digito_es_valido(int codigo[],int largo)
{
    int suma=0;
    for (i=0;i<largo-1;i++)
    {
        if (i%2==0)
        {
            suma+=3*codigo[i];
        }
        else
            suma+=codigo[i];
    }
    if ((10-suma%10)==codigo[largo-1])
        return 1;
    else
        return 0;
}
void ingresar_codigo(int codigo[],int largo)
{
    for (i=0;i<largo;i++)
    {
        printf ("Ingrese nro. %d: ",i+1);
        scanf("%d",&codigo[i]);
        printf ("\n");
    }
}


