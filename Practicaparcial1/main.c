#include <stdio.h>
#include <stdlib.h>
int largocadena(char a[]);
int espalindromo(char a[],int largo);
int carencad(char a[],char b,int largo);
int main()
{
    char cad1[100],cad2[100],a;
    int largo1,largo2,pali1,pali2,car1,car2;
    printf ("Ingrese la primera cadena: ");
    gets(cad1);
    printf ("\nIngrese la segunda cadena: ");
    gets (cad2);
    largo1= largocadena(cad1);
    largo2=largocadena(cad2);

    pali1=espalindromo(cad1,largo1);
    pali2=espalindromo(cad2,largo2);

    printf ("\nIngrese caracter a buscar en cadenas: ");
    scanf ("%c",&a);

    car1=carencad(cad1,a,largo1);
    car2=carencad(cad2,a,largo2);

    if (largo1>largo2)
        printf ("\nLa cadena 2 es mas larga que la cadena 1.\n");
    else
    {
        if (largo2>largo1)
            printf ("\nLa cadena 1 es mas larga que la cadena 2.\n");
        else
            printf ("\nAmbas cadenas tienen el mismo largo.\n");
    }

    if (pali1)
        printf ("\n\n%s es palindromo\n",cad1);
    if (pali2)
        printf ("\n%s es palindromo\n",cad2);
    if (!pali1 && !pali2)
        printf ("\nNinguna es palindromo.\n");

    printf ("\nEl caracter %c aparece en la primera cadena %d vez o veces y en la segunda cadena, %d vez o veces.\n\n",a,car1,car2);
    return 0;
}
int largocadena(char a[])
{
    int i,largo;
    for (i=0;i<100;i++)
    {
        if (a[i]==0)
        {
            largo=i;
            break;
        }
    }
    return largo;
}
int espalindromo (char a[],int largo)
{
    int i,pal=1;
    for (i=largo-1;i>-1;i--)
    {
        if (a[i]!=a[largo-i-1])
        {
            pal=0;
            break;
        }
    }
    return pal;
}
int carencad(char a[],char b,int largo)
{
    int i,cant=0;
    for (i=0;i<largo;i++)
    {
        if (a[i]==b)
            cant++;
    }
    return cant;
}
