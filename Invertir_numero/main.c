#include <stdio.h>
#include <stdlib.h>
void invertir_numero(int numero);
int main()
{
    int numero;
    printf("Ingrese numero: ");
    scanf ("%d",&numero);
    invertir_numero(numero);

    return 0;
}
void invertir_numero(int numero)
{
    printf ("%d",numero%10);
    numero=numero-numero%10;
    if (numero>0){
    printf ("%d",(numero%100)/10);
    numero=numero-numero%100;
    }
    if (numero>0){
    printf ("%d",(numero%1000)/100);
    numero=numero-numero%1000;}
}
