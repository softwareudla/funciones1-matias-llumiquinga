#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    char nombreProductos[10][50];
    float precioProductos[10];
    int opc=1;
    int cont=0;
    do
    {
        cont+=MenuInicial(nombreProductos,precioProductos,cont);
        printf("Desea seleccionar otra opcion:\n1.Si\n2.No\n>>");
        scanf("%d",&opc);
    } while (opc==1);
    

    //leerProducto(nombreProductos,precioProductos,1,0);

    //imprimirProducto(nombreProductos,precioProductos,1,0);

    //char nombreABuscar[50]="Arroz";

    //buscarProductoXNombre(nombreProductos,precioProductos,nombreABuscar);




    return 0;
}