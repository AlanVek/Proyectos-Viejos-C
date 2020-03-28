#include <stdio.h>
#include <stdlib.h>
#define precio 100
int calcular_docenas_obsequio (int cantidad_docenas);
float calcular_costo(int cantidad_docenas);
float calcular_descuento(int cantidad_docenas);
int main()
{
    int cantidad_docenas,docenas_obsequio;
    float descuento;
    printf ("Ingresar cantidad de docenas a comprar: ");
    scanf ("%d",&cantidad_docenas);

    docenas_obsequio=calcular_docenas_obsequio(cantidad_docenas);
    descuento=calcular_descuento(cantidad_docenas);

    printf ("\n\nMonto de la compra: %d",cantidad_docenas*precio);
    printf ("\nDescuento: %.2f",descuento);
    printf ("\nTotal a pagar: %.2f",cantidad_docenas*precio-descuento);
    printf ("\nCantidad de docenas obsequio: %d\n",docenas_obsequio);

    return 0;
}
int calcular_docenas_obsequio (int cantidad_docenas)
{
    if (cantidad_docenas>3)
    {
        return cantidad_docenas-3;
    }
    else
    {
        return 0;
    }
}

float calcular_descuento(int cantidad_docenas)
{
    if (cantidad_docenas>3)
    {
        return cantidad_docenas*precio*0.15;
    }
    else
    {
        return cantidad_docenas*precio*0.1;
    }
}
