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
        printf("Ingrese el nombre del producto %d:\t", i+1);
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
        printf("Ingrese el precio del producto %d (%s) (precio>0 y precio<=10000):\t", i+1, nombreProducto[i]);
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

void buscarProducto(char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], 
                    float preciosProductos[CANTIDAD_PRODUCTOS], 
                    int cantidadProductos)
{
    char productoBuscado[CANTIDAD_CARACTERES];
    int encontrado, continuar = 0;

    printf("BUSQUEDA DE PRODUCTOS\n");

    do
    {
        imprimirSeparadores();
        encontrado = 0;

        printf("Ingrese el nombre del producto a buscar:   ");
        scanf("%s", &productoBuscado);

        for (int i = 0; i < cantidadProductos; i++)
        {
            if (strcmp(nombreProducto[i], productoBuscado) == 0) //strcmp compara 2 cadenas y devulve 0 si son iguales
            {
                printf("El precio del producto %d (%s) es:\t%.2f\n", i + 1, nombreProducto[i], preciosProductos[i]);
                encontrado = 1;
            }
        }
        if (encontrado == 0)
        {
            printf("No se encontro el producto buscado\n");
        }

        printf("Presione 0 para buscar otro producto y cualquier numero entero para terminar:\t");
        scanf("%f", &continuar);

    } while (continuar == 0);
}


void imprimirProductosPrecios(  int cantidadProductos, char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], 
                                float preciosProductos[CANTIDAD_PRODUCTOS])
{
    printf("\n");
    imprimirSeparadores();

    printf("PRODUCTOS\n");
    
    imprimirSeparadores();
    
    for (int i = 0; i < cantidadProductos; i++)
    {
        printf("%d.\t%-22s$%-22.2f\n", i+1, nombreProducto[i], preciosProductos[i]);
    }

    imprimirSeparadores();
}

void imprimirCalculos(  float precioTotal, float min, float max, float promedio,
                        int cantidadProductos, 
                        char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], 
                        float preciosProductos[CANTIDAD_PRODUCTOS])
{

    char nombresProductosBaratos[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES];
    int acumBaratos=0;
    char nombresProductosCaros[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES];
    int acumCaros=0;

    printf("CALCULOS\n");
    
    imprimirSeparadores();

    printf("%-3s%-22s%-3s%-22s%-3s%-22s%-3s%-22s\n", "|", "Total:","|", "Precio P. Mas Barato:", "|", "Precio P. Mas Caro:", "|", "Promedio:");

    printf("%-4s%-21.2f%-4s%-21.2f%-4s%-21.2f%-4s%-21.2f\n","|  $", precioTotal, "|  $", min, "|  $", max, "|  $", promedio);

    

    for (int i = 0; i < cantidadProductos; i++)
    {
        if (preciosProductos[i]==min)
        {
            strcpy(nombresProductosBaratos[acumBaratos], nombreProducto[i]);
            acumBaratos++;
        }
        if (preciosProductos[i]==max)
        {
            strcpy(nombresProductosCaros[acumCaros], nombreProducto[i]);
            acumCaros++;
        }
    }

    printf("\n%-3sP. Mas Barato(s) (%d):\n","|", acumBaratos);

    for (int i = 0; i < acumBaratos; i++)
    {
        printf("%-3s%-22s\n","|",nombresProductosBaratos[i]);        
    }

    printf("\n%-3sP. Mas Caro(s) (%d):\n","|", acumCaros);
    for (int i = 0; i < acumCaros; i++)
    {
        printf("%-3s%-22s\n","|",nombresProductosCaros[i]);        
    }
    



    imprimirSeparadores();
}


void imprimirSeparadores()
{
    for (int i = 0; i < (4*25); i++)
    {
        printf("-");
    }
    printf("\n");
}