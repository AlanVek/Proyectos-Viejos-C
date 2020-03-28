#include <stdio.h>
#include <stdlib.h>
#include "Empleados.h"

int main()
{
    FILE *txt,*admin,*tec;
    Empleado vector[1000],vector_ordenado[1000],a;
    int cantidad,i;
    float promedio=0;
    char cat;

    txt=fopen ("nomina.txt","rt");
    if (txt==NULL)
    {
        printf ("No se puede abrir el archivo.\n");
        exit(9);
    }

    Cargar_Datos(txt,vector,&cantidad);

    Cambiar_Sueldos(txt,vector,cantidad);
    fclose(txt);

    txt=fopen("nomina.txt","wt");

    Actualizar_Archivo(txt,vector,cantidad);
    fclose(txt);

    admin=fopen("Administrativos.bin","wb");
    tec=fopen ("Tecnicos.bin","wb");

    Cargar_Binarios(tec,admin,vector,cantidad);

    for (i=0;i<cantidad;i++)
        vector_ordenado[i]=vector[i];

    Ordenar_Por_Sueldo(vector_ordenado,cantidad);

    printf ("Ingrese categoria a mostrar: ");
    scanf ("%c",&cat);

    while (cat!='A' && cat!='B' && cat!='C' && cat!='D')
    {
        printf ("Categoria incorrecta. Intente de nuevo: ");
        scanf ("%c",&cat);
    }

    printf ("\nEmpleados de categoria %c:\n",cat);

    Mostrar_Categoria_X(vector_ordenado,cat,cantidad);

    promedio = Promedio (vector_ordenado,cantidad);

    printf ("\nPromedio de sueldos: %f\n\n",promedio);
    printf ("Empleados que cobran mas que el promedio:\n");

    Mayores_A_Promedio(vector_ordenado, promedio, cantidad);

    fclose (admin);
    fclose (tec);
    return 0;
}
