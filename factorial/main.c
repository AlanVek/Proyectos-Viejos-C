/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int factorial (int n);
int main()
{
    int a,b;
    
    printf ("Ingrese un entero: ");
    scanf ("%d",&a);
    b=factorial (a);
    printf ("El factorial de %d es %d",a,b);
    return 0;
}

int factorial (int a)
{
    int i,f;
    
    if ((a==0) || (a==1))
    {
        return 1;
    }
    else
    {
        i=1;
        f=1;
        while (i<a+1)
        {
            f=f*i;
            i=i+1;
        }
        return f;
    }
}

