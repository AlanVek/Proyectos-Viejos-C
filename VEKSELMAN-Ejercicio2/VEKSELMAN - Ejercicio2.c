#include <stdio.h>
#include <stdlib.h>
#define maximo 1000
void fibonacci (int numero,int vector[],int *cuantos);
void mostrar_vector (int vector[],int largo);
void limpiar_vector (int vector[],int largo);
int main()
{
    int numero,*cuantos=0,numeros_fibonacci[maximo];
    printf ("Ingrese cantidad: ");
    scanf ("%d",&numero);
    while (numero!=0)
    {
        while (numero<0)
        {
            printf ("\nEl numero debe ser mayor a 0 o igual a 0 para salir: ");
            scanf ("%d",&numero);
        }
        if (numero==0)
        {
            break;
        }
        fibonacci (numero,numeros_fibonacci,&cuantos);
        printf ("\n");
        mostrar_vector (numeros_fibonacci,numero);
        limpiar_vector(numeros_fibonacci,numero);
        printf ("\n\nIngrese nueva cantidad: ");
        scanf ("%d",&numero);
    }
    printf ("\n");
    printf ("Cantidad de veces calculado: %d\n",cuantos);


    return 0;
}
void fibonacci (int numero,int vector[],int *cuantos)
{
    int a=2,b=1,c=0,d,indice=2;
    vector[0]=0;
    vector[1]=1;

    while (a<numero)
    {
        d=b+c;
        vector[indice]=d;
        indice+=1;
        if (b>c)
        {
            c=d;
        }
        else
        {
            b=d;
        }
        a++;
    }
    *cuantos+=1;
}
void mostrar_vector (int vector[],int largo)
{
    int i;
    for (i=0;i<largo;i++)
    {
        printf ("%d/",vector[i]);
    }
}
void limpiar_vector (int vector[],int largo)
{
    int i;
    for (i=0;i<largo;i++)
    {
        vector[i]=0;
    }
}

