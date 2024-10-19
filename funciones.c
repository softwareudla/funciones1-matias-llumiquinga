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



void ingresarNombresProductos(char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], int i)
{
    fflush(stdin);
    printf("Ingrese el nombre del producto %d:\t", i + 1);
    scanf("%s", nombreProducto[i]);
}

void ingresarPreciosProductos(float preciosProductos[CANTIDAD_PRODUCTOS], int i, char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES])
{

    printf("Ingrese el precio del producto %d (%s) (precio>0 y precio<=10000):\t", i + 1, nombreProducto[i]);
    scanf("%f", &preciosProductos[i]);

    if (preciosProductos[i] <= 0 || preciosProductos[i] > 10000)
    {
        printf("Valor ingresado fuera de rango\n");
        i--;
    }
}



float obtenerPrecioTotal(float precioTotal, float preciosProductos[CANTIDAD_PRODUCTOS], int i)
{
    precioTotal = precioTotal + preciosProductos[i];
    return precioTotal;
}

float obtenerPrecioMin(float min, float preciosProductos[CANTIDAD_PRODUCTOS], int i)
{
    if (preciosProductos[i] < min)
    {
        min = preciosProductos[i];
    }
    return min;
}

float obtenerPrecioMax(float max, float preciosProductos[CANTIDAD_PRODUCTOS], int i)
{
    if (preciosProductos[i] > max)
    {
        max = preciosProductos[i];
    }
    return max;
}

float obtenerPromedio(float precioTotal, int cantiddProductos)
{
    float promedio=0;
    promedio = precioTotal/cantiddProductos;
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
        scanf("%s", productoBuscado);

        printf("\n");
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
        printf("\n");


        printf("Presione 0 para buscar otro producto y cualquier numero entero para terminar:\t");
        scanf("%d", &continuar);

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

    printf("\n%-3sP. Mas Barato(s) (Cantidad: %d):\n","|", acumBaratos);

    for (int i = 0; i < acumBaratos; i++)
    {
        printf("%-3s%-22s\n","|",nombresProductosBaratos[i]);        
    }

    printf("\n%-3sP. Mas Caro(s) (Cantidad: %d):\n","|", acumCaros);
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