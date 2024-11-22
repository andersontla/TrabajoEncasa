#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion, capacidadRecursos = 60, capacidadTiempo;
    int cantidades[5] = {0};
    char continuar;

    printf("---- CIBER APARATOS -----\n");
    printf ("\n\n ---- TIENES UN TOTAL DE 60 RECURSOS PARA DESAROLLAR TU PRODUCT----- \n\n" );
    printf("1. AUDIFONOS (TIENE 6 RECURSOS, 2 HORAS POR UNIDAD)\n");
    printf("2. CELULARES (OCUPAN 14 RECURSOS, 5 HORAS POR UNIDAD)\n");
    printf("3. TABLETS (OCUPAN 8 RECURSOS, 3 HORAS POR UNIDAD)\n");
    printf("4. CALCULADORAS (OCUPAN 4 RECURSOS, 1 HORA POR UNIDAD)\n");
    printf("5. CAMARAS (OCUPAN 16 RECURSOS, 6 HORAS POR UNIDAD)\n");

    printf("\nIngrese el tiempo maximo de produccion disponible (horas): ");
    scanf("%d", &capacidadTiempo);
    if (capacidadTiempo < 0) {
        printf("Valor invalido. Desea continuar? (s/n): ");
        scanf(" %c", &continuar);
        if (continuar == 'n' || continuar == 'N') return 0;
    }

    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Agregar cantidad de un producto\n");
        printf("2. Eliminar un producto\n");
        printf("3. Calcular produccion\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion < 1 || opcion > 4) {
            printf("Valor invalido. Desea continuar? (s/n): ");
            scanf(" %c", &continuar);
            if (continuar == 'n' || continuar == 'N') break;
            else;
        }

        switch (opcion) {
            case 1:
                agregarCantidad(cantidades);
                break;
            case 2:
                eliminarProducto(cantidades);
                break;
            case 3:
                calcularProduccion(cantidades, capacidadRecursos, capacidadTiempo);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}