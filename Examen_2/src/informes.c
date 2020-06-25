/*
 * informes.c
 *
 *  Created on: 25 jun. 2020
 *      Author: aleja
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "articulo.h"




void informes(LinkedList* pArrayList)
{
	int qArticulosPrecio;
	int qArticulosRubro;
	int tam;
	tam=ll_len(pArrayList);
	if (tam>0)
	{
		qArticulosPrecio=ll_count(pArrayList,cantidad_ArticulosPrecioMayor100);
		qArticulosRubro=ll_count(pArrayList,cantidad_ArticulosRubro);
		printf("\n\nLa cantidad con precio mayor a 100 es: %d\n",qArticulosPrecio);
		printf("\n\nLa cantidad de articulos del rubro 1 Cuidado de ropa es: %d\n",qArticulosRubro);

	}
	else
	{
		printf("\n\nEl sistema no posee articulos cargados\n");
	}


}
