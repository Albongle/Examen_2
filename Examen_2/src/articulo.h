/*
 * articulo.h
 *
 *  Created on: 24 jun. 2020
 *      Author: aleja
 */

#ifndef ARTICULO_H_
#define ARTICULO_H_


typedef struct eRubro {
	int id_Rubro;
	char nombre_Rubro[128];

}eRubro;

typedef struct eArticulo {
	int id_Articulo;
	char nombre_Articulo[128];
	float precio;
	char medida[32];
	eRubro rubro;
	float monto;
}eArticulo;


/** \brief reserva memoria para una estructura de tipo articulo inicializa los campos,
 * retornado su posicion de moemora.
 * \param void
 * \return Employee* retorna el puntero a la estructura
 */
eArticulo* eArticulo_new();
/** \brief reserva memoria para una estructura de tipo articulo y carga la informacion enviada,
 *  retornado su posicion de moemora.
 * \param id_Articulo, es el Id a cargar para la estructura
 * \param nombre, es el nombre a cargar para la estructura
 * \param medidaStr, es la medida a cargar para la estructura
 * \param precioStr, es el precio a cargar para la estructura
 * \param idRubroStr, es el Id del rubro a cagar para al cual pertence el elemento de esa estructura
 * \return Employee* retorna el puntero a la estructura
 */
eArticulo* eArticulo_newParametros(char* id_Articulo,char* nombre,char* medidaStr,char* precioStr, char* idRubroStr);
/** \brief funcion usada para cargar el Id .
 * \param this, es el puntero de la estructura
 * \param id, es el valor que se va asignar
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eArticulo_setId(eArticulo* this,int id_Articulo);
/** \brief funcion usada para obtener el Id.
 * \param this, es el puntero de la estructura
 * \param *id, es el puntero donde se va a guardar el id
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eArticulo_getId(eArticulo* this,int* id_Articulo);
/** \brief funcion usada para cargar el nombre .
 * \param this, es el puntero de la estructura
 * \param nombre, es el valor que se va asignar
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eArticulo_setNombre(eArticulo* this,char* nombre);
/** \brief funcion usada para obtener el nombre.
 * \param this, es el puntero de la estructura
 * \param *nombre, es el puntero donde se va a guardar el nombre
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eArticulo_getNombre(eArticulo* this,char* nombre);
/** \brief funcion usada para cargar el precio .
 * \param this, es el puntero de la estructura
 * \param precio, es el valor que se va asignar
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eArticulo_setPrecio(eArticulo* this,float precio);
/** \brief funcion usada para obtener el precio.
 * \param this, es el puntero de la estructura
 * \param *precio, es el puntero donde se va a guardar el precio
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eArticulo_getPrecio(eArticulo* this,float* precio);
/** \brief funcion usada para cargar la medida .
 * \param this, es el puntero de la estructura
 * \param medida, es el valor que se va asignar
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eArticulo_setMedida(eArticulo* this,char* medida);
/** \brief funcion usada para obtener el medida.
 * \param this, es el puntero de la estructura
 * \param *medida, es el puntero donde se va a guardar la medida
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eArticulo_getMedida(eArticulo* this,char* medida);
/** \brief funcion usada para cargar el id de Rubro .
 * \param this, es el puntero de la estructura
 * \param idRubro, es el valor que se va asignar
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eArticulo_setRubro(eArticulo* this,int idRubro);
/** \brief funcion usada para obtener el nombre del rubro.
 * \param this, es el puntero de la estructura
 * \param *rubroStr, es el puntero donde se va a guardar el nombre del rubro
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eArticulo_getRubro(eArticulo* this,char* rubroStr);
/** \brief funcion usada para obtener el id del rubro.
 * \param this, es el puntero de la estructura
 * \param *idRubro, es el puntero donde se va a guardar el id del rubro
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eArticulo_getIdRubro(eArticulo* this,int* idRubro);

/** \brief funcion usada para obtener todos los datos de un articulo como string
 * \param this, es el puntero de la estructura de articulo
 * \param *id, es el puntero donde se va a guardar el id
 * \param *articulo, es el puntero donde se va a guardar el nombre del articulo obtenido
 * \param *medida, es el puntero donde se van a guardar la medida del articulo
 * \param *precio, es el puntero donde se guardara el precio del articulo
 * \param *idRubro, es el puntero donde se guardara el id del rubro al cual pertence del articulo
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */

int eArticulos_getDatos(eArticulo* this,char* id,char* articulo,char* medida, char* precio, char* idRubro);
/** \brief funcion usada para eliminar un articulo.
 * \param this, es el puntero de la estructura de articulo
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eArticulo_delete(eArticulo* this);
/** \brief funcion usada para imprimir un articulo.
 * \param this, es el puntero de la estructura
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eArticulos_Print(eArticulo* this);
/** \brief funcion criterio utilizada para relizar el ordenamiento por nombre de articulo
 * en caso que estos sean igual compara por sueldo
 * \param art1, es el puntero usado para obetener los datos a comparar con art2
 * \param art2, es el puntero usado para obetener los datos a comparar con art1
 * \return int 1 en caso que la comparacion sea valida, -1 en caso contrario
 */
int eArticulo_OrdenPorArticulo(void* art1,void* art2);
/** \brief funcion criterio utilizada para aplicar el descuento al campo precio
 * en caso que estos sean igual compara por sueldo
 * \param art, es el puntero usado para obetener los datos del articulo y aplicar descuento en caso que corresponda
 */
void eArticulo_DescuentoPorPrecio(void* art);


int cantidad_ArticulosPrecioMayor100(void* pElement);

int cantidad_ArticulosRubro(void* pElement);
#endif /* ARTICULO_H_ */
