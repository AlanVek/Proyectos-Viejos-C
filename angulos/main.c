/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main()
{
    float a,b;
    printf ("Tiene un angulo de 90°.\n");
    a=asin(0.8)*180/3.14;
    printf ("Otro angulo es %f°:\n ",a);
    b=90-a;
    printf ("El tercero es %f°: ",b);
}
