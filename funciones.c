#include <stdio.h>
#include "funciones.h"

void agregarCantidad(int cantidades[]) {
    int indice, cantidad;
    char continuar;

    printf("Seleccione el producto a agregar cantidad:\n");
    printf("1. AUDIFONOS\n2. CELULARES\n3. TABLETS\n4. CALCULADORAS\n5. CAMARAS\n");
    printf("Ingrese el numero del producto: ");
    scanf("%d", &indice);

    if (indice < 1 || indice > 5) {
        printf("Valor invalido. Desea continuar? (s/n): ");
        scanf(" %c", &continuar);
        if (continuar == 'n' || continuar == 'N') return;
        else agregarCantidad(cantidades);
        return;
    }

    printf("Ingrese la cantidad deseada: ");
    scanf("%d", &cantidad);
    if (cantidad < 0) {
        printf("Valor invalido. Desea continuar? (s/n): ");
        scanf(" %c", &continuar);
        if (continuar == 'n' || continuar == 'N') return;
        else agregarCantidad(cantidades);
        return;
    }

    cantidades[indice - 1] += cantidad;
    printf("Se agregaron %d unidades al producto seleccionado.\n", cantidad);
}

void eliminarProducto(int cantidades[]) {
    int indice;
    char continuar;

    printf("Seleccione el producto a eliminar:\n");
    printf("1. AUDIFONOS\n2. CELULARES\n3. TABLETS\n4. CALCULADORAS\n5. CAMARAS\n");
    printf("Ingrese el numero del producto: ");
    scanf("%d", &indice);

    if (indice < 1 || indice > 5) {
        printf("Valor invalido. Desea continuar? (s/n): ");
        scanf(" %c", &continuar);
        if (continuar == 'n' || continuar == 'N') return;
        else eliminarProducto(cantidades);
        return;
    }

    cantidades[indice - 1] = 0;
    printf("Se eliminaron todas las unidades del producto seleccionado.\n");
}

void calcularProduccion(int cantidades[], int capacidadRecursos, int capacidadTiempo) {
    int recursos[5] = {6, 14, 8, 4, 16};
    int tiempos[5] = {2, 5, 3, 1, 6};
    int totalRecursos = 0, totalTiempo = 0;

    for (int i = 0; i < 5; i++) {
        totalRecursos += cantidades[i] * recursos[i];
        totalTiempo += cantidades[i] * tiempos[i];
    }

    printf("\n--- RESULTADOS DE PRODUCCION ---\n");
    printf("Recursos necesarios totales: %d (Maximo: %d)\n", totalRecursos, capacidadRecursos);
    printf("Tiempo total de produccion: %d horas (Maximo: %d horas)\n", totalTiempo, capacidadTiempo);

    if (totalRecursos <= capacidadRecursos && totalTiempo <= capacidadTiempo) {
        printf("La produccion es viable.\n");
    } else {
        printf("La produccion NO es viable debido a restricciones de recursos o tiempo.\n");
    }
}
