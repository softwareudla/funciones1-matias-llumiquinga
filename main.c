#include <stdio.h>
#include <string.h>
#include "funciones.h"

//#define CANTIDAD_PRODUCTOS 10
//#define CANTIDAD_CARACTERES 22

int main (int argc, char *argv[])
{
    char nombresProductos[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES];
    float preciosProductos[CANTIDAD_PRODUCTOS];
    float precioTotal=0, min=10000, max=0, promedio=0;
    int cantidadProductos=0;


    cantidadProductos =ingresarCantidadProductos();    
    imprimirSeparadores();

    for (int i = 0; i < cantidadProductos; i++)
    {
        ingresarNombresProductos(nombresProductos,i);
    }
    
    imprimirSeparadores();

    for (int i = 0; i < cantidadProductos; i++)
    {
        ingresarPreciosProductos(preciosProductos, i, nombresProductos);
    }

    for (int i = 0; i < cantidadProductos; i++)
    {
        precioTotal= obtenerPrecioTotal(precioTotal,preciosProductos, i);
        min=obtenerPrecioMin(min, preciosProductos,i);
        max=obtenerPrecioMax(max, preciosProductos, i);
    }
    
    promedio=obtenerPromedio(precioTotal,cantidadProductos);    

    imprimirProductosPrecios(cantidadProductos, nombresProductos, preciosProductos);

    imprimirCalculos(precioTotal,min,max,promedio,cantidadProductos,nombresProductos, preciosProductos);

    buscarProducto(nombresProductos, preciosProductos, cantidadProductos);
    
    return 0;
}

