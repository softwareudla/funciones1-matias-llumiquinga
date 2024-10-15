#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define CANTIDAD_PRODUCTOS 10
#define CANTIDAD_CARACTERES 22

int ingresarCantidadProductos()
{
    int cantidadProductos=0;
    do
    {
        printf("Ingrese la cantidad de productos a registrar (1-10):\n");
        scanf("%d", &cantidadProductos);

        if (cantidadProductos<=0 || cantidadProductos>10)
        {
            printf("Valor ingresado fuera de rango\n");
        }
        
    } while (cantidadProductos<=0 || cantidadProductos>10);

    return cantidadProductos;
}


void ingresarNombresProductos(char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], int cantidadProductos)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    for (int i = 0; i < cantidadProductos; i++)
    {
        fflush(stdin);
        printf("Ingrese el nombre del producto %d:   ", i+1);
        fflush(stdin);
        fgets(nombreProducto[i], CANTIDAD_CARACTERES, stdin);
        nombreProducto[i][strcspn(nombreProducto, "\n")] = '\0';
    }
     
}