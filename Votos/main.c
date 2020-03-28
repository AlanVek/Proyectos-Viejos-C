#include <stdio.h>
#include <stdlib.h>
#define participantes 3
/*3.	Se cuentan los votos obtenidos por Nory, Laura y Fany
en una elección democrática a la presidencia del club
“Las Amantes del C”. Para ganar la elección se debe obtener como mínimo
el 50% de los votos mas 1.  En caso que no haya un ganador
se repite la elección en una segunda vuelta: van a la segunda
vuelta los dos que obtengan la más alta votación o los tres en
 caso de producirse un empate doble (entre los dos con menor votación)
 o un empate triple. Determinar el resultado de la elección.*/
int cargar_votos(int lista_votos[],int largo,int ronda,int indice_perdedor);
void ordenar_vector (int lista_votos[],int largo);
void limpiar_vector(int lista_votos[],int largo);
void copiar_vector (int lista_votos[],int lista_votos_copia[],int largo);
int buscar_enlista (int lista_votos[],int n,int largo);
int i;
int main()
{
    int votos[participantes],total,votos_copia[participantes],indice_ganador;
    int votos_segunda_ronda[participantes-1],votos_segronda_copia[participantes-1],indice_perdedor;
    limpiar_vector(votos,participantes);
    total=cargar_votos(votos,participantes,1,0);
    copiar_vector(votos,votos_copia,participantes);
    ordenar_vector(votos,participantes);
    if (votos[0]>=((float)total/2+1)){
        indice_ganador=buscar_enlista(votos_copia,votos[0],participantes);
        printf ("La ganadora es: ");
            switch (indice_ganador)
            {
                case 0: printf ("Nory");
                break;
                case 1: printf ("Laura");
                break;
                case 2: printf ("Fany.");
                break;
            }
    }
    else
    {
        if (votos[1]==votos[2])
        {
            limpiar_vector(votos,participantes);
            total=cargar_votos(votos,participantes,1,0);
            copiar_vector(votos,votos_copia,participantes);
            ordenar_vector(votos,participantes);
            indice_ganador=buscar_enlista(votos_copia,votos[0],participantes);
            printf ("La ganadora es: ");
            switch (indice_ganador)
            {
                case 0: printf ("Nory");
                break;
                case 1: printf ("Laura");
                break;
                case 2: printf ("Fany.");
                break;
            }

        }
        else
        {
            indice_perdedor=buscar_enlista(votos_copia,votos[participantes],participantes);
            limpiar_vector(votos_segunda_ronda,participantes-1);
            total=cargar_votos(votos_segunda_ronda,participantes-1,2,indice_perdedor);
            copiar_vector(votos_segunda_ronda,votos_segronda_copia,participantes-1);
            ordenar_vector(votos_segunda_ronda,participantes-1);
            indice_ganador=buscar_enlista(votos_segronda_copia,votos_segunda_ronda[0],participantes-1);
            printf ("La ganadora es: ");

            if (indice_perdedor==1){
                    switch (indice_ganador)
            {
                case 0:  printf ("Laura");
                break;
                case 1: printf ("Fany.");
                break;
            }
            }
            if (indice_perdedor==2){
                    switch (indice_ganador)
            {
                case 0:  printf ("Nory");
                break;
                case 1: printf ("Fany.");
                break;
            }
            }
            if (indice_perdedor==3){
                    switch (indice_ganador)
            {
                case 0:  printf ("Nory");
                break;
                case 1: printf ("Laura.");
                break;
            }
            }
        }
    }


    return 0;
}
int cargar_votos(int lista_votos[],int largo,int ronda,int indice_perdedor)
{
    int voto=1,suma=0;
    if (ronda==1){
    while (voto!=0)
    {
       printf ("Ingrese 1 para Nory, 2 para Laura, 3 para Fany: ");
       scanf("%d",&voto);
       lista_votos[voto-1]+=1;
       suma+=1;
    }
    }
    else
    {
        if (indice_perdedor==1){
        while (voto!=0)
        {
           printf ("Ingrese 2 para Laura, 3 para Fany: ");
           scanf("%d",&voto);
           lista_votos[voto-1]+=1;
           suma+=1;
        }
        }
        if (indice_perdedor==2){
         while (voto!=0)
        {
           printf ("Ingrese 1 para Nory, 3 para Fany: ");
           scanf("%d",&voto);
           lista_votos[voto-1]+=1;
           suma+=1;
        }
        }
        if (indice_perdedor==3){
         while (voto!=0)
        {
           printf ("Ingrese 1 para Nory, 2 para Laura: ");
           scanf("%d",&voto);
           lista_votos[voto-1]+=1;
           suma+=1;
        }
        }

    }
    return suma;
}
void ordenar_vector(int n[],int largo)
{
    int aux,j;
    for (i=0;i<largo-1;i++)
    {
        for (j=i+1;j<largo;j++)
        {
            if (n[j]>n[i])
            {
                aux=n[i];
                n[i]=n[j];
                n[j]=aux;
            }
        }
    }
}
void limpiar_vector(int lista_votos[],int largo)
{
    for (i=0;i<largo;i++)
    {
        lista_votos[i]=0;
    }
}
void copiar_vector (int lista_votos[],int lista_votos_copia[],int largo)
{
    for (i=0;i<largo;i++)
    {
        lista_votos_copia[i]=lista_votos[i];
    }
}
int buscar_enlista(int lista_votos_copia[],int n,int largo)
{
    for (i=0;i<largo;i++)
    {
        if (lista_votos_copia[i]==n)
        {
            lista_votos_copia[i]=0;
            break;
        }
    }
    return i;
}
