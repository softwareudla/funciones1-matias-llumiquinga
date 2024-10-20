#include <stdio.h>
#include <string.h>
#include "funciones.h"

//#define CANTIDAD_PRODUCTOS 10
//#define CANTIDAD_CARACTERES 22

int main (int argc, char *argv[])
{
    char nombresProductos[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES];
    float preciosProductos[CANTIDAD_PRODUCTOS];
    int cantidadProductos=0, continuar=0;


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

    do
    {
        continuar=menuFinal(nombresProductos,preciosProductos,cantidadProductos);
    } while (continuar!=4);
    
    
    
    return 0;
}

