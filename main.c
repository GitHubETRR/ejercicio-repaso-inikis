#include <stdio.h>
#include "banco_lib.h"

#define TRUE 1
#define FALSE 0
#define OPCION_INGRESAR 1
#define OPCION_MOSTRAR 2
#define OPCION_SALIR 3

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
