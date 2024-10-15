#define CANTIDAD_PRODUCTOS 10
#define CANTIDAD_CARACTERES 22

void inicializarPreciosProductos(float preciosProductos[CANTIDAD_PRODUCTOS]);
int ingresarCantidadProductos();
void ingresarNombresProductos(char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES], int cantidadProductos);
void ingresarPreciosProductos(  float preciosProductos[CANTIDAD_PRODUCTOS], int cantidadProductos, 
                                char nombreProducto[CANTIDAD_PRODUCTOS][CANTIDAD_CARACTERES]);

float obtenerPrecioTotal(float preciosProductos[CANTIDAD_PRODUCTOS], int cantidadProductos);
float obtenerPrecioMin(float preciosProductos[CANTIDAD_PRODUCTOS], int cantidadProductos);
float obtenerPrecioMax(float preciosProductos[CANTIDAD_PRODUCTOS], int cantidadProductos);
float obtenerPromedio(float preciosProductos[CANTIDAD_PRODUCTOS], int cantidadProductos);

