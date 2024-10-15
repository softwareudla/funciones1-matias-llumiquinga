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
    int cantidadProductos=0;


    cantidadProductos =ingresarCantidadProductos();    

    ingresarNombresProductos(nombresProductos, cantidadProductos);
    



    for (int i = 0; i < cantidadProductos; i++)
    {
        printf("%s\n", nombresProductos[i]);
    }
    
    
    


    return 0;
}

