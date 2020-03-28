/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int tipotriang(float a, float b, float c);
int main()
{
    float lado1,lado2,lado3;
    int a;
    printf ("Ingresar lado: ");
    scanf ("%f",&lado1);
    printf ("Ingresar lado: ");
    scanf ("%f",&lado2);
    printf ("Ingresar lado: ");
    scanf ("%f",&lado3);

    a= tipotriang (lado1,lado2,lado3);
    switch (a)
    {
        case 1:printf ("Es equilatero.");
            break;
        case 2: printf ("Es isosceles. ");
            break;
        case 3: printf ("Es escaleno. ");
            break;
    }

    return 0;
}

int tipotriang (float a, float b, float c)
{
    if ((a==b) && (b==c))
    {
        return 1;
    }
    else
    {
        if ((a==b && b!=c)|| (b==c && a!=c ) ||(a==c && a!=b))
        {
            return 2;
        }
        else
        {
            return 3;
        }

    }


}


