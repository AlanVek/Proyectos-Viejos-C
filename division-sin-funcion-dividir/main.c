/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int entero1,entero2,i,opcion,a;
    printf ("Ingrese un entero: ");
    scanf ("%d",&entero1);
    printf ("Ingrese otro entero: ");
    scanf ("%d",&entero2);
    while ((entero2==0) && (entero1!=0))
    {
        printf ("El divisor debe ser distinto de 0. Intente de nuevo: ");
        scanf ("%d",&entero2);
    }
   
    while ((entero1!=0)||(entero2!=0))
    {
        i=0;
        a=entero1;
    
        while (a>=entero2)
        {
            a=a-entero2;
            i+=1;
        }
        printf ("El resultado del cociente es %d y el resto es %d.\n",i,a);
        
        printf ("Ingrese un entero: ");
        scanf ("%d",&entero1);
        printf ("Ingrese otro entero: ");
        scanf ("%d",&entero2);
        while ((entero2==0) && (entero1!=0))
        {
            printf ("El divisor debe ser distinto de 0. Intente de nuevo: ");
            scanf ("%d",&entero2);
        }
    
        
    }
    printf ("Gracias por usar el programa. Vuelva pronto.");
    return 0;
}
