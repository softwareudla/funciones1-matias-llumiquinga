#include <stdio.h>
#include "funciones.h"
#include <string.h>

void leerProducto(char nombres[10][50], float precios[10], int num, int i){
    fflush(stdin);
    printf("Ingrese el nombre del producto %d: ",num);
    scanf("%s",&nombres[i]);
    printf("Ingrese el precio del producto %d: ",num);
    scanf("%f",&precios[i]);
}

void imprimirProducto(char nombres[10][50], float precios[10], int num, int i){
    //printf("#\t\tNombre\t\tPrecio\n");
    printf("%d\t\t%s\t\t%.2f\n",num,nombres[i],precios[i]);
}

void buscarProductoXNombre(char nombres[10][50], float precios[10], char nombreBuscar[50]){
    int encontrado=0;
    for (int i = 0; i < 10; i++)
    {
        if(strcmp(nombres[i],nombreBuscar)==0){
            int num=i+1;
            printf("#\t\tNombre\t\tPrecio\n");
            imprimirProducto(nombres,precios,num,i);
            encontrado=1;
        }
    }
    if(encontrado==0){
        printf("No existe el producto\n");
    }
    

}


int MenuInicial(char nombres[10][50], float precios[10],int i){
    int opc=0;
    int add=0;
    printf("Seleccione una opcion:\n");
    printf("1.Ingresar Producto\n2.Buscar Producto\n3.Imprimir Productos\n>>");
    scanf("%d",&opc);
    int num=i+1;
    char nombreBuscar[50];
    switch (opc)
    {
    case 1:
        leerProducto(nombres,precios,num,i);
        add=1;
        break;
    case 2:
        printf("Ingrese el nombre del producto que desea buscar: ");
        scanf("%s",&nombreBuscar);
        buscarProductoXNombre(nombres,precios,nombreBuscar);
        break;
    case 3:
        printf("#\t\tNombre\t\tPrecio\n");
        for (int j = 0; j < i; j++)
        {
            int num2=j+1;
            imprimirProducto(nombres,precios,num2,j);
        }
         
    default:
        break;
    }
    return add;
}