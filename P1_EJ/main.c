#include <stdio.h>
#include <stdlib.h>
#define max_elem 1000
void cargar_vector(int v[],int n);
int productoria (int v[],int n);
void limpiar_vector(int v[],int n);
int ingresar_cantidad(void);
int main()
{
    int vector[max_elem],producto,suma=0;
    int n=ingresar_cantidad();
    while (n!=0)
    {
        limpiar_vector(vector,n);

        cargar_vector(vector,n);

        producto=productoria(vector,n);

        suma+=1;

        printf ("\nLa productoria es: %d\n",producto);
        n=ingresar_cantidad();
    }
    printf ("\n\n//El programa fue usado %d vez o veces//.\n\n",suma);
    return 0;
}
void cargar_vector(int v[],int n)
{
    int i;
    printf ("\n");
    for (i=0;i<n;i++)
    {
        printf ("Ingrese dato numero %d: ",i+1);
        scanf ("%d",&v[i]);
    }
}
int productoria (int v[],int n)
{
    int i, producto=1;
    for (i=0;i<n;i++)
    {
        producto=producto*v[i];
    }
    return producto;
}
void limpiar_vector(int v[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        v[i]=0;
    }
}
int ingresar_cantidad(void)
{
    int n;
    printf ("\nIngrese cantidad de datos: ");
    scanf ("%d",&n);
    while (!(n>=0 && n<=max_elem))
    {
        printf ("La cantidad debe estar entre 1 y %d. Intente de nuevo: ",max_elem);
        scanf ("%d",&n);
    }
    return n;
}


