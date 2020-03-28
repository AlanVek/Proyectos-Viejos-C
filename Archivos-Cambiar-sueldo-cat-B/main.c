#include <stdio.h>
#include <stdlib.h>
#define categ_a_cambiar 'B'
typedef struct
{
    int codigo;
    char nombre[50];
    char categoria;
    float sueldo;
} empleado;
int main()
{
    FILE *catA;
    int i,tam,cant_reg;
    empleado UnEmpleado;

    catA=fopen ("nomina.bin","r+b");
    if (catA==NULL)
    {
        printf ("El archivo no se puede abrir.");
        exit(9);
    }
    fseek(catA,0,SEEK_END);
    tam=ftell(catA);
    cant_reg=tam/sizeof(empleado);
    printf ("Cantidad de empleados totales: %d\n\n",cant_reg);
    printf ("Sueldos iniciales:\n");
    fseek(catA,0,SEEK_SET);
    fread(&UnEmpleado,sizeof(empleado),1,catA);
    while (!(feof(catA)))
    {
        if (UnEmpleado.categoria==categ_a_cambiar)
            printf ("%04d %s %c %.2f\n", UnEmpleado.codigo, UnEmpleado.nombre, UnEmpleado.categoria,UnEmpleado.sueldo);
        fread(&UnEmpleado,sizeof(empleado),1,catA);
    }
    fseek(catA,0,SEEK_SET);

    printf ("\nSueldos modificados:\n\n");
    fread(&UnEmpleado,sizeof(empleado),1,catA);
    while (!(feof(catA)))
    {
        if (UnEmpleado.categoria==categ_a_cambiar)
        {
            fseek(catA,sizeof(empleado)*-1,SEEK_CUR);
            UnEmpleado.sueldo*=1.1;
            fwrite (&UnEmpleado,sizeof(empleado),1,catA);
            printf ("%04d %s %c %.2f\n", UnEmpleado.codigo, UnEmpleado.nombre, UnEmpleado.categoria,UnEmpleado.sueldo);
            fflush(catA);
        }
        fread(&UnEmpleado,sizeof(empleado),1,catA);
    }
    fclose (catA);
    return 0;
}
