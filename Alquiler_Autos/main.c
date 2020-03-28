#include <stdio.h>
#include <stdlib.h>
float calcular_costo(int kilometros);
int main()
{
    int kilometros;
    float costo;
    printf("Ingrese cantidad de kilometros: ");
    scanf ("%d",&kilometros);

    costo=calcular_costo(kilometros);

    printf ("El costo del alquiler es: %.2f",costo);
    printf ("\nEl impuesto es: %.2f\n", 19.0*costo/119.0);
    return 0;
}
float calcular_costo(int kilometros)
{
    if (kilometros<300)
    {
        return 30;
    }
    else
    {
        if (kilometros<1000)
        {
            return 60+0.15*(kilometros-300);
        }
        else
        {
            return 100+0.1*(kilometros-1000);
        }
    }
}
