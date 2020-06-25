#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "articulo.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"



int controller_loadFromText(LinkedList* pArrayList)
{
	FILE* txt;
	char path[512];

	int result;


	fflush(stdin);
	printf("\nIngrese el nombre del archivo\n");
	scanf("%s",path);
	txt=fopen(path,"r");;

	if(txt == NULL)
	{
		printf("\n\n****Cargar de Articulos mediante archivo TXT****\n\nNo se pudo abrir el archivo\n");
	}
	else if((result=parser_ArticulosComoTexto(txt ,pArrayList)))
	{
		printf("\n\n****Cargar de Articulos mediante archivo TXT****\n\nSe cargaron los Articulos\n");
		fclose(txt);
	}
	else if(result==-1)
	{
		printf("\n\n****Cargar de Articulos mediante archivo TXT****\n\nNo hay mas espacio para almacenar toda la informacion del archivo\n");
		fclose(txt);
	}
	else
	{
		printf("\n\n****Cargar de Articulos mediante archivo TXT****\n\nHubo un error al momento de la lectura del archivo\n");
		fclose(txt);

	}

    return 1;
}


int controller_List(LinkedList* pArrayList)
{
	eArticulo* articuloAux=NULL;
	int i;
	int tam;
	if ((tam=ll_len(pArrayList))>0)
	{
		system("CLS()");
		printf("\n\n\t\t\t\t****Listado de Articulos****\n");
		printf("\n\n\nId\tArticulo\t\t\tMedida\tprecio\t\t\tRubro\n");
		for (i=0;i<tam;i++)
		{
			articuloAux=ll_get(pArrayList,i);
			if(articuloAux!=NULL)
			{
				eArticulos_Print(articuloAux);
			}
		}
	}
	else
	{
		printf("\n\n\nEl sistema no posee Articulos\n");
	}

	return 1;
}


int controller_sort(LinkedList* pArrayList)
{
    int tam;
    int sentido;
	tam=ll_len(pArrayList);
	if(tam>0)
	{
		fflush(stdin);
		printf("\n\n*****Se va a ordenar por nombre de articulo*****\n");
		if(utn_getNumero(&sentido,"\nElija el criterio de orden\n0-Descendente\n1-Ascendente\n","Error, verifique los datos ingresados, quedan %d intentos\n",0,1,3))
		{
			printf("\n\nSe esta realizando el ordenamiento...\n");
			ll_sort(pArrayList,eArticulo_OrdenPorArticulo,sentido);
			printf("\n\nSe realizo el ordenamiento\n");
		}
		else
		{
			printf("No se reconocio el ingreso, se cancelo el ordenamiento\n");
		}
	}
	else
	{
		printf("\n\n\nEl sitema no posee articulos para ordenar\n");
	}


	return 1;
}


int controller_saveAsText(char* path , LinkedList* pArrayList)
{
	FILE* txt;
	FILE* auxTxt;
	int ret=0;
	int tam;
	int flag=0;
	int result=0;
	char pregunta;
	if(path!=NULL && pArrayList!=NULL)
	{
		tam=ll_len(pArrayList);
		if(tam>0)
		{
			if((auxTxt=fopen(path,"r"))!=NULL)
			{
				fclose(auxTxt);
				printf("\n\nYa existe un arhivo con ese nombre\n");
				flag=1;
				if((utn_getCaracter(&pregunta,"Desea continuar de todos modos? (s/n):\n","Error verifique los datos ingresados, quedan %d reintentos","sn\n",3)))
				{
					if(pregunta=='s')
					{
						flag=0;
					}
				}
				else
				{
					printf("\n\nsupero el maximo de posibilidades\n");
				}
			}
			if(flag==0)
			{
				if((txt=fopen(path,"w"))==NULL)
				{
					printf("El archivo no puede ser abierto\n");
				}
				else
				{
					if((result=guardar_ArticuloscomoTexto(txt,pArrayList)))
					{

						printf("\n\n\nSe genero el archivo de texto con el listado de Articulos\n");
					}
					else if(result<0)
					{
						printf("\n\n\nSe genero el archivo de texto con el listado de Articulos pero algunos registros no se pudieron guardar\n");
					}
					else
					{
						printf("\n\n\nNo se pudo generar el archivo de texto\n");
					}
					fclose(txt);
				}
			}
			else
			{
				printf("se cancelo la accion\n");
			}
		}
		else
		{
			printf("\n\n\nEl sitema no posee Articulos\n");
		}
	}
	return ret;

}


int controller_memoryFree(LinkedList* pArrayList)
{
	eArticulo* artiAux=NULL;
	int ret=0;
	int i;
	int tam;


	if (pArrayList!=NULL)
	{
		tam=ll_len(pArrayList);
		if(tam>0)
		{
			for(i=0;i<tam;i++)
			{
				{
					artiAux=ll_get(pArrayList,i);
					eArticulo_delete(artiAux);
				}
			}

			ll_clear(pArrayList);
			ret=1;
		}
	}
return ret;
}

