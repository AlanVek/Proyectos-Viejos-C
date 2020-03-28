#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial (int n);
float funcion (float numero,int *terminos);
int main()
{
    float x;
    int *terminos;
    printf("Ingrese numero: ");
    scanf ("%f",&x);
    printf ("\nResultado: %f",funcion(x,&terminos));
    printf ("\nCantidad de terminos: %d",terminos);
    return 0;
}
int factorial (int n)
{
    int fact,j;

    if ((n==0) || (n==1))
    {
        return 1;
    }
    else
    {
        for (j=1;j<n+1;j++)
        {
            fact*=j;
        }
        return fact;
    }
}
float funcion (float numero,int *terminos)
{
    float resultado=1.0;
    int i=1;
    *terminos=1;
    while (resultado>pow(10,-6))
    {
        resultado+=(pow(-1,i)*(numero/factorial(i)));
        *terminos+=1;
        i+=1;
    }
    return resultado;
}

