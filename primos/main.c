#include <stdio.h>
int es_primo (int a);
int main()
{
    int a,b;
    printf ("Ingrese entero: ");
    scanf("%d",&a);
    b= es_primo(a);
    if (b==0)
    {
        printf ("No es primo.");
    }
    else
    {
        printf ("Es primo.");
    }
}

int es_primo(int a)
{
    int primo,y;
    if ((a==1)||(a==0))
    {
        return 0;
    }
    else
    {
        primo=1;
        for (y=2;y<a;y++)
        {
            if (a%y==0)
            {
                primo=0;
                break;
            }
        }
        return primo;

    }
}



