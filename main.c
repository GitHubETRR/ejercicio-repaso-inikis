#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define OPCION_INGRESAR 1
#define OPCION_MOSTRAR 2
#define OPCION_SALIR 3
#define CHAR_MAX_NOMBRE 83

typedef struct empleado{
    char nombre[CHAR_MAX_NOMBRE];
    int edad;
    int salario;
}empleado;

void ingresarDatos(empleado empleados[],int cantEmpleados);
void procesarDatos(empleado empleados[]);
void mostrarDatos(empleado empleados[],int cantEmpleados);
void buscarSalarioAlto(empleado empleados[],int cantEmpleados);

int main(void){
    empleado empleados[5];
    int cantEmpleados = 0;
    int opcionIngresada;

    printf("BASE DE DATOS DE EMPLEADOS\n--------------------------");
    

    do{    
        printf("\n1. Ingresar datos de un empleado.\n2. Procesar y mostrar informacion relevante.\n3. Salir.\n");
        
        printf("\nIngrese su opcion: ");
        scanf("%d", &opcionIngresada);

        if (opcionIngresada==OPCION_INGRESAR){
            if (cantEmpleados>=5){
                printf("\nLimite de empleados (5) alcanzado.\n");
            }else{
                ingresarDatos(empleados,cantEmpleados);
                cantEmpleados++;
            }
        }else if (opcionIngresada==OPCION_MOSTRAR){
            procesarDatos(empleados);
            mostrarDatos(empleados,cantEmpleados);
            buscarSalarioAlto(empleados,cantEmpleados);
        }else if(opcionIngresada!=OPCION_SALIR){
            printf("\nIngrese una opcion correcta.\n");
        }
    }while(opcionIngresada!=OPCION_SALIR);
    
    printf("\nHasta luego.");

    return 0;
}

void ingresarDatos(empleado empleados[],int cantEmpleados){
    int edadIngresada = 0;
    int salarioIngresado = 0;
    char nombreIngresado;

    printf("\nIngrese el nombre del empleado numero %d: ",cantEmpleados+1);
    scanf("%s", empleados[cantEmpleados].nombre);

    printf("Ingrese la edad del empleado numero %d: ",cantEmpleados+1);
    scanf("%d", &empleados[cantEmpleados].edad);

    printf("Ingrese el salario del empleado %d: ",cantEmpleados+1);
    scanf("%d", &empleados[cantEmpleados].salario);
    
    printf("\nDatos ingresados\n");
}

void buscarSalarioAlto(empleado empleados[],int cantEmpleados){
    int numEmpleadoSalarioAlto = 0;
    for (int i = 0; i < cantEmpleados; i++){
        if (empleados[i].salario>empleados[numEmpleadoSalarioAlto].salario){
            numEmpleadoSalarioAlto=i;
        }
    }

    printf("\nSalario max: %s, %d\n", empleados[numEmpleadoSalarioAlto].nombre, empleados[numEmpleadoSalarioAlto].salario);
}

void procesarDatos(empleado empleados[]){
    float promedio = 0;
    float sumaSalarios = 0;

    for (int i = 0; i < 5; i++){
        sumaSalarios += empleados[i].salario;
    }

    promedio = sumaSalarios/5;
}

void mostrarDatos(empleado empleados[],int cantEmpleados){
    for (int i = 0; i < cantEmpleados; i++){
        printf("\nEmpleado %d", i+1);
        printf("\n - Nombre: %s",empleados[i].nombre);
        printf("\n - Edad: %d",empleados[i].edad);
        printf("\n - Salario: %d\n",empleados[i].salario);
    }
}
