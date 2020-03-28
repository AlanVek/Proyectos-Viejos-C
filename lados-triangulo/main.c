/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int es_triang(float a, float b, float c);
int main()
{
    float lado1,lado2,lado3;
    printf ("Ingresar lado: ");
    scanf ("%f",&lado1);
    printf ("Ingresar lado: ");
    scanf ("%f",&lado2);
    printf ("Ingresar lado: ");
    scanf ("%f",&lado3);
    
    if (es_triang(lado1,lado2,lado3)==0)
    {
        printf ("No es triC!ngulo. ");
    }
    else
    {
        printf ("Es triC!ngulo.");
    }
    
    return 0;
    
}

int es_triang(float a, float b, float c)
    {
        if ((a+b)>c && (a+c)>b && (b+c)>a)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }



