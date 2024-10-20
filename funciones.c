#include <stdio.h>
#include <string.h>
#include "funciones.h"

//#define CANTIDAD_PRODUCTOS 10
//#define CANTIDAD_CARACTERES 22

int ingresarCantidadProductos()
{
    float cantidadProductosF;
    int cantidadProductosI;

    do
    {
        cantidadProductosF=0;
        cantidadProductosI=0;
        printf("Ingrese la cantidad de productos a registrar (1-10):\n%-5s",">>");
        scanf("%f", &cantidadProductosF);
        cantidadProductosI=(int)cantidadProductosF;

        if (cantidadProductosF<=0 || cantidadProductosF>10)
        {
            printf("Valor ingresado fuera de rango\n");
        }
        if (cantidadProductosF!=cantidadProductosI)
        {
            printf("No ingrese numeros decimales\n");
        }
        
    } while (cantidadProductosF<=0 || cantidadProductosF>10 || cantidadProductosF!=cantidadProductosI);

    return cantidadProductosI;
}


void ingresarNombresProductos(char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], int i)
{
    int longCadena=0;
    
    do
    {     
        strcpy(nombreProducto[i],""); //strcpy en C sirve para copiar el contenido de una cadena de caracteres en otra sobreescribe
        fflush(stdin);
        printf("Ingrese el NOMBRE del producto %d (MAX: 20 caracteres):\t", i + 1);
        while (nombreProducto[i][0]=='\0'||nombreProducto[i][0]=='\n')
        {
            fgets(nombreProducto[i], CANTIDAD_CARACTERES, stdin);
        }
        longCadena = strlen(nombreProducto[i]);

        if (nombreProducto[i][longCadena-1] != '\n')
        {
            printf("Error, el nombre tiene mas de 20 caracteres\n");
            while (getchar() != '\n');    // Descartar todos los caracteres hasta '\n' - Limpiar el buffer de entrada
        }      
        
    } while (nombreProducto[i][longCadena-1] != '\n');
    nombreProducto[i][longCadena-1]='\0';
}

void ingresarPreciosProductos(float preciosProductos[CANTIDAD_PRODUCTOS], int i, char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES])
{
    preciosProductos[i]=0;
    do
    {
        printf("Ingrese el PRECIO del producto %d (%s) (precio>0 y precio<=10000):\t", i + 1, nombreProducto[i]);
        scanf("%f", &preciosProductos[i]);

        if (preciosProductos[i] <= 0 || preciosProductos[i] > 10000)
        {
            printf("Valor ingresado fuera de rango\n");
        }

    } while (preciosProductos[i] <= 0 || preciosProductos[i] > 10000);
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
    int encontrado=0, longCadena=0;

    do
    {
        strcpy(productoBuscado, "");
        fflush(stdin);
        printf("Ingrese el nombre del producto a buscar:\t");
        while (productoBuscado[0] == '\0' || productoBuscado[0] == '\n')
        {
            fgets(productoBuscado, CANTIDAD_CARACTERES, stdin);
        }
        longCadena = strlen(productoBuscado);

        if (productoBuscado[longCadena - 1] != '\n')
        {
            printf("Error, el nombre tiene mas de 20 caracteres\n");
            while (getchar() != '\n'); // Descartar todos los caracteres hasta '\n' - Limpiar el buffer de entrada
        }
    } while (productoBuscado[longCadena - 1] != '\n');

    productoBuscado[longCadena - 1] = '\0';

    printf("\n");

    for (int i = 0; i < cantidadProductos; i++)
    {
        if (strcmp(nombreProducto[i], productoBuscado) == 0) // strcmp compara 2 cadenas y devulve 0 si son iguales
        {
            printf("El precio del producto %d (%s) es:\t$%.2f\n", i + 1, nombreProducto[i], preciosProductos[i]);
            encontrado = 1;
        }
    }
    if (encontrado == 0)
    {
        printf("No se encontro el producto buscado\n");
    }
}

void imprimirProductosPrecios(  int cantidadProductos, char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], 
                                float preciosProductos[CANTIDAD_PRODUCTOS])
{
    for (int i = 0; i < cantidadProductos; i++)
    {
        printf("%d.\t%-22s$%-22.2f\n", i+1, nombreProducto[i], preciosProductos[i]);
    }
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
}

void imprimirSeparadores()
{
    for (int i = 0; i < (4*25); i++)
    {
        printf("-");
    }
    printf("\n");
}

int menuFinal(  char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], 
                float preciosProductos[CANTIDAD_PRODUCTOS], 
                int cantidadProductos)
{
    int continuarI;
    float continuarF;
    float precioT=0, precioMin=10000, precioMax=0, precioP=0;

    imprimirSeparadores();
    do
    {
        continuarF = 0;
        continuarI = 0;

        printf("PRESIONE:\n1.Ingresar Nuevo Producto\n2.Buscar Producto\n3.Mostrar Productos\n4.Mostrar Resultados\n5.Terminar\n%-5s", ">>");
        scanf("%f", &continuarF);
        continuarI = (int)continuarF;

        if (continuarI != 1 && continuarI != 2 && continuarI != 3 && continuarI != 4 && continuarI != 5 || continuarF != continuarI)
        {
            printf("-Opcion NO valida-\n");
        }

    } while (continuarF != continuarI || continuarI != 1 && continuarI != 2 && continuarI != 3 && continuarI != 4 && continuarI != 5);


    switch (continuarI)
    {
    case 1:
        imprimirSeparadores();
        printf("INGRESAR NUEVO PRODUCTO\n");
        imprimirSeparadores();

        if (cantidadProductos<10)
        {
            cantidadProductos++;
            ingresarNombresProductos(nombreProducto, cantidadProductos-1);
            ingresarPreciosProductos(preciosProductos, cantidadProductos-1, nombreProducto);
        }else
        {
            cantidadProductos=10;
            printf("Ha alcanzado el maximo de productos a ingresar\n");
        }   
        break;
    case 2:
        imprimirSeparadores();
        printf("BUSQUEDA DE PRODUCTOS\n");
        imprimirSeparadores();

        buscarProducto(nombreProducto, preciosProductos, cantidadProductos);
        break;
    case 3:
        imprimirSeparadores();
        printf("PRODUCTOS\n");
        imprimirSeparadores();

        imprimirProductosPrecios(cantidadProductos, nombreProducto, preciosProductos);
        break;
    case 4:
        imprimirSeparadores();
        printf("RESULTADOS\n");
        imprimirSeparadores();

        for (int i = 0; i < cantidadProductos; i++)
        {
            precioT = obtenerPrecioTotal(precioT, preciosProductos, i);
            precioMin = obtenerPrecioMin(precioMin, preciosProductos, i);
            precioMax = obtenerPrecioMax(precioMax, preciosProductos, i);
        }

        precioP = obtenerPromedio(precioT, cantidadProductos);

        imprimirCalculos(precioT, precioMin, precioMax, precioP, cantidadProductos, nombreProducto, preciosProductos);
        break;
    default:
        break;
    }

    return continuarI;
}
