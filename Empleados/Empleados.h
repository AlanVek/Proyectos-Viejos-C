typedef struct
{
    int legajo;
    char nombre [50];
    char categoria;
    float sueldo;
} Empleado;
void Ordenar_Por_Sueldo (Empleado vectorr[],int cantidad);
void Cargar_Datos (FILE *txt,Empleado vector[],int *cantidad);
void Cambiar_Sueldos (FILE*txt, Empleado vector[],int cantidad);
void Actualizar_Archivo (FILE*txt,Empleado vector[],int cantidad);
void Cargar_Binarios (FILE *tec, FILE *admin, Empleado vector[], int cantidad);
void Mostrar_Categoria_X (Empleado vector_ordenado[], char categoria, int cantidad);
float Promedio (Empleado vector_ordenado[],int cantidad);
void Mayores_A_Promedio (Empleado vector_ordenado[], float promedio, int cantidad);
