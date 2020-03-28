/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
float menu (float n1, float n2, int a);
int main()
{
    float n1,n2,d;
    int a;
    printf("Ingrese primero: ");
    scanf ("%f",&n1);
    printf ("Ingrese segundo: ");
    scanf ("%f",&n2);
    printf ("Ingrese 1= Sumar, 2= Restar, 3= Multiplicar y 4= Dividir: ");
    scanf ("%d",&a);
    if ((n2==0) && (a==4))
    {
        printf ("Error. No se puede dividir por 0.");
    }
    else
    {
        d= menu(n1,n2,a);
        printf ("Resultado: %.2f",d);
    }
   
    return 0;
}

float menu (float n1, float n2, int a)
{
    float b;
    
    if (a==1)
    {
        b=(float) n1+n2;
    }
    else if (a==2)
    {
        b=(float) n1-n2;
    }
    else if (a==3)
    {
        b= (float) n1*n2;
    }
    else if (a==4)
    {
        b=n1/n2;
    }
    
    return b;
}  

