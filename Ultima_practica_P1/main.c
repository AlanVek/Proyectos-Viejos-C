#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define tamanio 21
void generar_n_numeros_aleatorios(int liminf,int limsup, int vector[],int largo);
float calcular_media(int vector[],int largo);
float calcular_mediana(int vector[],int largo);
void ordenar_vector(int vector[],int largo);
float calcular_varianza(int vector[],int largo,float media);
/*opcion=1 para numeros menores que la media menos la varianza y cualquier otra para
mayores que media mas varianza*/
void numeros_masmenos_media_y_desviostd(int vector[],int largo,float media, float desvio, int opc);
int primos_en_vector(int vector[],int largo);
int numeros_raiz_exacta(int vector[],int largo);
void mostrar_vector (int vector[],int largo);
int opcion=1,i;
int vector_numeros[11];
int main()
{
    srand (time(NULL));
    int liminf,limsup;
    float media,mediana,varianza,desvio_std;
    while (opcion==1)
    {
        system("cls");
        printf ("--------------------------------------------------------------------\n");
        printf ("Ingrese limite inferior: ");
        scanf ("%d",&liminf);
        printf ("Ingrese limite superior: ");
        scanf ("%d",&limsup);
        while (!(limsup>liminf))
        {
            printf ("El limite superior debe ser mayor al inferior. Intente de nuevo: ");
            scanf ("%d",&limsup);
        }
        printf ("\n");

        generar_n_numeros_aleatorios(liminf,limsup,vector_numeros,tamanio);
        ordenar_vector(vector_numeros,tamanio);
        mostrar_vector (vector_numeros,tamanio);

        media=calcular_media(vector_numeros,tamanio);


        mediana=calcular_mediana(vector_numeros,tamanio);

        varianza=calcular_varianza(vector_numeros,tamanio,media);

        desvio_std=sqrt(varianza);

        printf ("\n\nMedia: %f",media);

        printf ("\nMediana: %f",mediana);

        printf ("\nVarianza: %f",varianza);

        printf ("\nDesvio estandar: %f",desvio_std);

        printf ("\n\nNumeros mayores que la media mas el desvio:\n");

        numeros_masmenos_media_y_desviostd(vector_numeros,tamanio,media,desvio_std,2);
        /*opcion=1 para numeros menores que la media menos la varianza y cualquier otra para
        mayores que media mas varianza*/
        printf ("\n\nNumeros menores que la media menos el desvio: \n");

        numeros_masmenos_media_y_desviostd(vector_numeros,tamanio,media,desvio_std,1);
        /*opcion=1 para numeros menores que la media menos la varianza y cualquier otra para
        mayores que media mas varianza*/
        printf ("\n\nCantidad de primos en el vector: %d",primos_en_vector(vector_numeros,tamanio));

        printf ("\n\nCantidad de numeros con raiz exacta: %d",numeros_raiz_exacta(vector_numeros,tamanio));

        printf ("\n\nSi desea continuar, presione 1. Si no, cualquier otro numero: ");

        scanf ("%d",&opcion);

        printf ("\n");
    }
    printf ("--------------------------------------------------------------------\n");

    return 0;
}

void generar_n_numeros_aleatorios(int liminf,int limsup, int vector[],int largo)
{
    int numero;
    for (i=0;i<largo;i++)
    {
        numero=rand()%(limsup+1-liminf)+liminf;
        vector[i]=numero;
    }
}
float calcular_media(int vector[],int largo)
{
    float suma=0;
    for (i=0;i<largo;i++)
    {
        suma+=vector[i];
    }
    return (float) suma/largo;
}
float calcular_mediana(int vector[],int largo)
{
    if (largo%2==1)
    {
        return vector[(largo/2)];
    }
    else
    {
        return (float) (vector[largo/2] + vector[largo/2+1])/2.0;
    }
}
void ordenar_vector(int vector[],int largo)
{
    int j,aux;
    for (i=0;i<largo-1;i++)
    {
        for (j=i+1;j<largo;j++)
        {
            if (vector[j]<vector[i])
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
}
float calcular_varianza(int vector[],int largo,float media)
{
    int var=0;
    for(i=0;i<largo;i++)
    {
        var+=((vector[i]-media)*(vector[i]-media));
    }
    return (float) var/(largo-1);
}
void numeros_masmenos_media_y_desviostd(int vector[],int largo,float media, float desvio, int opc)
{
    /*opcion=1 para numeros menores que la media menos la varianza y cualquier otra para
    mayores que media mas varianza*/
    float numero;
    if (opc==1)
    {
        numero=media-desvio;
        for (i=0;i<largo;i++)
        {
            if (vector[i]<numero)
            {
                printf ("%d/",vector[i]);
            }
        }
    }
    else
    {
        numero=media+desvio;
        for (i=0;i<largo;i++)
        {
            if (vector[i]>numero)
            {
                printf ("%d/",vector[i]);
            }
        }
    }
}

int primos_en_vector(int vector[],int largo)
{
    int j,suma=0,primo;
    for (i=0;i<largo;i++)
    {
        primo=1;
        for (j=2;j<vector[i];j++)
        {
            if (vector[i]%j==0)
            {
                primo=0;
                break;
            }

        }
        if (primo==1)
        {
            suma+=1;
        }
    }
    return suma;
}
void mostrar_vector (int vector[],int largo)
{

    printf ("/");
    for (i=0;i<largo;i++)
    {
        if (i==largo-1)
        {
            printf ("%d",vector[i]);
        }
        else
        {
            printf ("%d,",vector[i]);
        }
    }
    printf ("/");
}
int numeros_raiz_exacta(int vector[],int largo)
{
    int j,a,suma=0;
    for (i=0;i<largo;i++)
    {
        a=vector[i];
        j=1;
        while (a>0)
        {
            a=a-j;
            j+=2;
        }
        if (a==0)
        {
            suma+=1;
        }
    }
    return suma;
}
