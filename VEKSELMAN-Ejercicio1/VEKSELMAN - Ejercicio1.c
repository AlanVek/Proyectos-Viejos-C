#include <stdio.h>
#include <stdlib.h>
int dividir (int numerador, int denominador,int *resto);
int main()
{
    int n1,n2,*resto;
    printf ("Ingrese primer numero: ");
    scanf ("%d",&n1);
    printf ("\nIngrese segundo numero: ");
    scanf ("%d",&n2);
    while (!(n1==0 && n2==0))
    {
        while (n2==0)
        {
            printf ("\nNo se puede dividir por 0. Ingrese otro: ");
            scanf ("%d",&n2);
        }
        printf ("El resultado es: %d",dividir (n1,n2,&resto));
        printf ("\nEl resto es: %d\n",resto);

        printf ("\nIngrese primer numero: ");
        scanf ("%d",&n1);
        printf ("\nIngrese segundo numero: ");
        scanf ("%d",&n2);

        printf ("\n");
    }
    printf ("Hasta luego.\n");
    return 0;
}
int dividir (int n1, int n2,int *resto)
{

    *resto=abs(n1);
    int cociente=0;
    while (*resto>=abs(n2))
    {
        cociente+=1;
        *resto-=abs(n2);
    }

    if (!((n1>0 && n2>0)||(n1<0 && n2<0)))
    {
        if (n2>0)
        {
            *resto=*resto*(-1);
        }
        cociente*=(-1);
    }
    return cociente;
}
