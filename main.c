/*Una tienda desea implementar un programa en C que permita gestionar su inventario de productos. 
El programa debe recibir los nombres de los productos y sus precios, para luego realizar varias operaciones, tales como:

Calcular el precio total del inventario.
Encontrar el producto más caro y el más barato.
Calcular el precio promedio de todos los productos.
Buscar un producto por su nombre y mostrar su precio.
El número máximo de productos que el sistema debe manejar es 10.*/

#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define CANTIDAD_PRODUCTOS 10
#define CANTIDAD_CARACTERES 22

int ingresarCantidadProductos();
void ingresarNombresProductos(char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], int cantidadProductos);

int main (int argc, char *argv[])
{
    char nombresProductos[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES];
    float preciosProductos[CANTIDAD_PRODUCTOS];
    float precioTotal=0, min=0, max=0, promedio=0;

    int cantidadProductos=0;




    inicializarPreciosProductos(preciosProductos);

    cantidadProductos =ingresarCantidadProductos();    

    ingresarNombresProductos(nombresProductos, cantidadProductos);
    
    ingresarPreciosProductos(preciosProductos, cantidadProductos, nombresProductos);

    precioTotal= obtenerPrecioTotal(preciosProductos, cantidadProductos);
    min=obtenerPrecioMin(preciosProductos,cantidadProductos);
    max=obtenerPrecioMax(preciosProductos, cantidadProductos);
    promedio=obtenerPromedio(preciosProductos,cantidadProductos);


    

    imprimirProductosPrecios(cantidadProductos, nombresProductos, preciosProductos);

    imprimirCalculos(precioTotal,min,max,promedio,cantidadProductos,nombresProductos, preciosProductos);

    buscarProducto(nombresProductos, preciosProductos, cantidadProductos);
    


    return 0;
}

