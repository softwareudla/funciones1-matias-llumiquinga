#define CANTIDAD_PRODUCTOS 10
#define CANTIDAD_CARACTERES 22

int ingresarCantidadProductos();
void ingresarNombresProductos(char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], int i);
void ingresarPreciosProductos(float preciosProductos[CANTIDAD_PRODUCTOS], int i, char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES]);

float obtenerPrecioTotal(float precioTotal, float preciosProductos[CANTIDAD_PRODUCTOS], int i);
float obtenerPrecioMin(float min, float preciosProductos[CANTIDAD_PRODUCTOS], int i);
float obtenerPrecioMax(float max, float preciosProductos[CANTIDAD_PRODUCTOS], int i);
float obtenerPromedio(float precioTotal, int cantiddProductos);

void buscarProducto(char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], 
                    float preciosProductos[CANTIDAD_PRODUCTOS], 
                    int cantidadProductos);

void imprimirProductosPrecios(  int cantidadProductos, char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], 
                                float preciosProductos[CANTIDAD_PRODUCTOS]);

void imprimirCalculos(  float precioTotal, float min, float max, float promedio,
                        int cantidadProductos, 
                        char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], 
                        float preciosProductos[CANTIDAD_PRODUCTOS]);

void imprimirSeparadores();
