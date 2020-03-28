#include <stdio.h>
#include "Cadenas.h"

void Dar_Vuelta_Palabra (char Palabra[])
{
    int i=0,j;
	while (Palabra[i]!=0)
		i++;

	for (j=i-1;j>-1;j--)
        printf ("%c",Palabra[j]);
}
int Son_Anagramas (char Palabra1[],char Palabra2[])
{
    int largo1=0,largo2=0;
    int i,j;
    char Copia_Palabra1[1000],Copia_Palabra2[1000];

	while (Palabra1[largo1]!=0)
		largo1++;
    while (Palabra2[largo2]!=0)
		largo2++;

    if (largo1!=largo2)
        return 0;

    for (i=0;i<largo1;i++)
        Copia_Palabra1[i]=Palabra1[i];
    for (i=0;i<largo2;i++)
        Copia_Palabra2[i]=Palabra2[i];

    for (i=0;i<largo1;i++)
    {
        for (j=0;j<largo2;j++)
        {
            if (Copia_Palabra2[j]==Copia_Palabra1[i])
            {
                Copia_Palabra2[j]=0;
                break;
            }
        }
        if (Copia_Palabra2[j]!=0)
            return 0;
    }
    return 1;
}
int Una_Incluye_A_Otra (char Palabra1[],char Palabra2[])
{
    int largo1=0,largo2=0;
    int Incluye;
    int i,j,t;
    char Copia_Palabra1[1000],Copia_Palabra2[1000];

	while (Palabra1[largo1]!=0)
		largo1++;
    while (Palabra2[largo2]!=0)
		largo2++;
    for (i=0;i<largo1;i++)
        Copia_Palabra1[i]=Palabra1[i];
    for (i=0;i<largo2;i++)
        Copia_Palabra2[i]=Palabra2[i];

    if (largo1<largo2)
        return 0;

    for (i=0;i<largo1-largo2;i++)
    {
        Incluye=1;
        t=i+1;
        for (j=0;j<largo2;j++)
        {
            if (Copia_Palabra2[j]!=Copia_Palabra1[t])
            {
                Incluye=0;
                break;
            }
            t++;
        }
        if (Incluye==1)
            return 1;
    }
    return 0;
}
int Es_Palindromo (char Palabra[])
{
    int largo=0;
    int i;
	while (Palabra[largo]!=0)
		largo++;
    for (i=0;i<largo/2;i++)
    {
        if (Palabra[i]!=Palabra[largo-i-1])
            return 0;
    }
    return 1;
}
