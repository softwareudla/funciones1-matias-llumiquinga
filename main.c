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

        if (continuar==1 && cantidadProductos<10)
        {
            cantidadProductos++;
        }
        else if (continuar==1 && cantidadProductos>=10)
        {
            cantidadProductos=10;
        }

    } while (continuar!=5);
    
    return 0;
}

