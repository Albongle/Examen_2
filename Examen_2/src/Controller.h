

/** \brief Carga los datos de los articulos desde el archivo data.csv (modo texto).
 *
 * \param path char* es la referencia del archivo
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los articulos
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayList);

/** \brief Listar articulos
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los articulos
 * \return int
 *
 */
int controller_List(LinkedList* pArrayList);
/** \brief Ordenar articulos
 *
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los articulos
 * \return int
 *
 */
int controller_sort(LinkedList* pArrayList);


/** \brief Guarda los datos de los articulos en el archivo data.csv (modo texto).
 * \param path char* es la referencia del archivo
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los articulos
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList);

/** \brief libera momoria en los momentos necesarios.
 *
 * \param pArrayListEmployee LinkedList*es el listado que almacena las posiciones de memorias de los articulos
 * \return int
 *
 */

int controller_memoryFree(LinkedList* pArrayList);


