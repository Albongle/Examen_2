#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "articulo.h"


int parser_ArticulosComoTexto(FILE* pFile , LinkedList* pArrayList)
{
	int ret=0;
	char buffer[5][128];
	int cant=0;
	eArticulo* pAuxArticulo=NULL;

	if(pFile!=NULL && pArrayList!=NULL)
	{
			 fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
			 while(!feof(pFile))
			 {
				 cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
			     if(cant<5)
			     {
			    	 ret=0;
			    	 break;
			     }
			     else
			     {
			    	 if((pAuxArticulo=eArticulo_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]))!=NULL)
			    	 {
			    		 ll_add(pArrayList,pAuxArticulo);
			    		 ret=1;
			    	 }
			    	 else
			    	 {
			    		 ret=-1;
			    		 break;
			    	 }
			     }
			 }
	}
    return ret;
}



int guardar_ArticuloscomoTexto(FILE* pFile,LinkedList* pArrayList)
{
	int ret=0;
	int tam;
	int i;
	char id[10];
	char articulo[128];
	char medida[32];
	char precio[30];
	char idRubro[10];
	int flag=0;
	int cant;
	char* titulo="ID,Articulo,Medida,Precio,RubroId\n";
	eArticulo* artiAux=NULL;

	if(pFile!=NULL &&  pArrayList!=NULL)
	{
		tam=ll_len(pArrayList);
		if(tam>0)
		{
			ll_map(pArrayList,eArticulo_DescuentoPorPrecio);
			fwrite(titulo,sizeof(char),strlen(titulo),pFile);
			for(i=0;i<tam;i++)
			{
				if((artiAux=ll_get(pArrayList,i))!=NULL)
				{

					if(eArticulos_getDatos(artiAux,id,articulo,medida,precio,idRubro))
					{
						cant=fprintf(pFile,"%s,%s,%s,%s,%s\n",id,articulo,medida,precio,idRubro);
						if(cant<6)
						{
							flag=1;
						}
					}
				}
			}
			if(flag>0)
			{
				ret=-1;
			}
			else
			{
				ret=1;
			}
		}
	}
	return ret;
}
