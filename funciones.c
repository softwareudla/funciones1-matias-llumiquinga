#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define CANTIDAD_PRODUCTOS 10
#define CANTIDAD_CARACTERES 22

void inicializarPreciosProductos(float preciosProductos[CANTIDAD_PRODUCTOS])
{
    for (int i = 0; i < CANTIDAD_PRODUCTOS; i++)
    {
        preciosProductos[i]=0;
    }
}


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
    int c, longitudCadena=0;
    while ((c = getchar()) != '\n' && c != EOF);

    for (int i = 0; i < cantidadProductos; i++)
    {
        fflush(stdin);
        printf("Ingrese el nombre del producto %d:   ", i+1);
        fflush(stdin);
        fgets(nombreProducto[i], CANTIDAD_CARACTERES, stdin);

        longitudCadena= strlen(nombreProducto[i]);
        if (nombreProducto[i][longitudCadena-1] == '\n')
        {
            nombreProducto[i][longitudCadena-1] = '\0';
        }

    }
}

void ingresarPreciosProductos(  float preciosProductos[CANTIDAD_PRODUCTOS], int cantidadProductos, 
                                char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES])
{
    for (int i = 0; i < cantidadProductos; i++)
    {
        printf("Ingrese el precio del producto %d (%s) (precio>0 y precio<=10000):   ", i+1, nombreProducto);
        scanf("%f", &preciosProductos[i]);

        if (preciosProductos[i]<=0 || preciosProductos[i]>10000)
        {
            printf("Valor ingresado fuera de rango\n");
            i--;
        }
    }
}



float obtenerPrecioTotal(float preciosProductos[CANTIDAD_PRODUCTOS], int cantidadProductos)
{
    float precioTotal=0;

    for (int i = 0; i < cantidadProductos; i++)
    {
        precioTotal=precioTotal + preciosProductos[i];
    }
    return precioTotal;
}

float obtenerPrecioMin(float preciosProductos[CANTIDAD_PRODUCTOS], int cantidadProductos)
{
    float minimo=10000;

    for (int i = 0; i < cantidadProductos; i++)
    {
        if (preciosProductos[i]<minimo)
        {
            minimo=preciosProductos[i];
        }
    }

    return minimo;
}

float obtenerPrecioMax(float preciosProductos[CANTIDAD_PRODUCTOS], int cantidadProductos)
{
    float maximo=0;

    for (int i = 0; i < cantidadProductos; i++)
    {
        if (preciosProductos[i]>maximo)
        {
            maximo=preciosProductos[i];
        }
    }

    return maximo;
}

float obtenerPromedio(float preciosProductos[CANTIDAD_PRODUCTOS], int cantidadProductos)
{
    float promedio = obtenerPrecioTotal(preciosProductos, cantidadProductos);
    promedio= promedio/cantidadProductos;
    return promedio;

}