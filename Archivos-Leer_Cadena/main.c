#include <stdio.h>
#include <stdlib.h>
#define maximo 100000
int cantidad_palabras (char vector[]);
int buscar_cad_en_otra (char vector_busqueda[],char vector[],int largo);
int longitud_cadena (char vector[]);
int main()
{
    FILE *txt;
    int cant_veces,cant_palabras,largo;
    char cadena[maximo],cad_buscar[maximo];
    printf ("Ingrese cadena: ");
    fgets (cadena,maximo,stdin);
    printf ("\nCadena leida:\n%s",cadena);
    txt=fopen ("archivo-texto.txt","wt");

    fprintf (txt,"%s",cadena);

    cant_palabras=cantidad_palabras (cadena);

    printf ("\nLa cadena tiene %d palabras.\n",cant_palabras);

    printf ("\nIngrese cadena a buscar: ");
    fgets (cad_buscar,maximo,stdin);

    largo=longitud_cadena(cadena);

    cant_veces= buscar_cad_en_otra (cad_buscar,cadena,largo);

    printf ("\nLa cadena ingresada aparece %d veces en la inicial.\n",cant_veces);

    return 0;
}
int cantidad_palabras (char vector[])
{
    int i=0,cant_pal=0;
    while (vector[i]!=0)
    {
        if (vector[i]==' ')
        {
            cant_pal+=1;
        }
        i+=1;
    }
    if (i!=0)
        return cant_pal+1;
    else
        return cant_pal;
}
int buscar_cad_en_otra (char vector_busqueda[],char vector[],int largo)
{
    int i=0,suma=0,j,t;
    for (i=0;i<largo;i++)
    {
        j=0;
        t=i;
        while (vector[t]==vector_busqueda[j] && t<largo && vector_busqueda[j]!=0)
        {
            j+=1;
            t+=1;
        }
        if (j==longitud_cadena(vector_busqueda))
        {
            suma+=1;
            i=t;
        }
    }
    return suma;
}
int longitud_cadena (char vector[])
{
    int h=0;
    while (vector[h]!=0)
    {
        h+=1;
    }
    return h-1;
}
