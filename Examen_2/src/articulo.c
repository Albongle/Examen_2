/*
 * articulo.c
 *
 *  Created on: 24 jun. 2020
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "articulo.h"

/** \brief estable el nombre del rubro en de acuerdo al valor recibido
 * \param idRubro es el valor a considerar para obtener el nombre del rubro
 * \param *rubroStr es el puntero donde se va a asignar el nombre del rubro si corresponde
 * \return 1 en caso exitoso, 0 en caso contrario.
 */
static int selectRubro(int idRubro, char* rubroStr);

eArticulo* eArticulo_new()
{
	eArticulo* this=(eArticulo*) malloc(sizeof(eArticulo));
	if(this!=NULL)
	{
		eArticulo_setId(this,0);
		eArticulo_setNombre(this,"");
		eArticulo_setPrecio(this,0);
		eArticulo_setMedida(this,"");
		eArticulo_setRubro(this,0);
	}
	return this;
}

eArticulo* eArticulo_newParametros(char* id_Articulo,char* nombre,char* medidaStr,char* precioStr, char* idRubroStr)
{
	eArticulo* this=eArticulo_new();

		if(this!=NULL && id_Articulo!=NULL && nombre!=NULL && precioStr!=NULL && medidaStr!=NULL && idRubroStr!=NULL)
		{
			eArticulo_setId(this,atoi(id_Articulo));
			eArticulo_setNombre(this,nombre);
			eArticulo_setPrecio(this,atof(precioStr));
			eArticulo_setMedida(this,medidaStr);
			eArticulo_setRubro(this,atoi(idRubroStr));

		}
		return this;

}


int eArticulo_setId(eArticulo* this,int id_Articulo)
{
	int ret=0;
	static int maxId=0;
	if (this!=NULL)
	{
		if(id_Articulo<0)
		{
			maxId++;
			this->id_Articulo=maxId;
		}
		else
		{
			if(id_Articulo>maxId)
			{
				maxId=id_Articulo;
			}
			this->id_Articulo=id_Articulo;
		}
		ret=1;
	}
	return ret;
}

int eArticulo_getId(eArticulo* this,int* id_Articulo)
{
	int ret=0;
		if (this!=NULL && id_Articulo !=NULL)
		{
			*id_Articulo=this->id_Articulo;
			ret=1;
		}
		return ret;

}

int eArticulo_setNombre(eArticulo* this,char* nombre)
{
	int ret=0;

	if (this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre_Articulo,nombre);
		ret=1;
	}
	return ret;
}

int eArticulo_getNombre(eArticulo* this,char* nombre)
{
	int ret=0;

	if (this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre_Articulo);
		ret=1;
	}
	return ret;
}


int eArticulo_setPrecio(eArticulo* this,float precio)
{
	int ret=0;

	if (this!=NULL && precio>=0)
	{
		this->precio=precio;
		ret=1;
	}
	return ret;
}

int eArticulo_getPrecio(eArticulo* this,float* precio)
{
	int ret=0;

	if (this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		ret=1;
	}
	return ret;
}


int eArticulo_setMedida(eArticulo* this,char* medida)
{
	int ret=0;

	if (this!=NULL && medida!=NULL)
	{
		strcpy(this->medida,medida);
		ret=1;
	}
	return ret;
}

int eArticulo_getMedida(eArticulo* this,char* medida)
{
	int ret=0;

	if (this!=NULL && medida!=NULL)
	{
		strcpy(medida,this->medida);
		ret=1;
	}
	return ret;
}


int eArticulo_setRubro(eArticulo* this,int idRubro)
{
	int ret=0;
	char rubroStr[128];


	if (this!=NULL && idRubro>=0)
	{
		selectRubro(idRubro,rubroStr);
		this->rubro.id_Rubro=idRubro;
		strcpy(this->rubro.nombre_Rubro,rubroStr);
		ret=1;
	}
	return ret;
}


int eArticulo_getRubro(eArticulo* this,char* rubroStr)
{
	int ret=0;

	if (this!=NULL && rubroStr!=NULL)
	{
		strcpy(rubroStr,this->rubro.nombre_Rubro);
		ret=1;
	}
	return ret;
}

static int selectRubro(int idRubro, char* rubroStr)
{
	int ret=0;

	if (idRubro>=0 && idRubro <5)
	{
		switch(idRubro)
		{
			case 0: {strcpy(rubroStr,"");break;}
			case 1: {strcpy(rubroStr,"CUIDADO DE ROPA");break;}
			case 2: {strcpy(rubroStr,"LIMPIEZA Y DESINFECCION");break;}
			case 3: {strcpy(rubroStr,"CUIDADO PERSONAL E HIGIENE");break;}
			case 4: {strcpy(rubroStr,"CUIDADO DEL AUTOMOTOR");break;}
		}
		ret=1;
	}
	return ret;
}

int eArticulo_getIdRubro(eArticulo* this,int* idRubro)
{
	int ret=0;

	if (this!=NULL && idRubro!=NULL)
	{
		*idRubro=this->rubro.id_Rubro;
		ret=1;
	}
	return ret;
}



int eArticulo_delete(eArticulo* this)
{
	int ret=0;
	if(this!=NULL)
	{
		free(this);
		ret=1;
	}
	return ret;
}


int eArticulos_getDatos(eArticulo* this,char* id,char* articulo,char* medida, char* precio, char* idRubro)
{
	int ret=0;

	if (this!=NULL && id!=NULL && articulo!=NULL && medida!=NULL && precio!=NULL && idRubro!=NULL)
	{
		sprintf(id,"%d",this->id_Articulo);
		strcpy(articulo,this->nombre_Articulo);
		strcpy(medida,this->medida);
		sprintf(precio,"%.2f",this->precio);
		strcpy(medida,this->medida);
		sprintf(idRubro,"%d",this->rubro.id_Rubro);

		ret=1;
	}
return ret;
}


int eArticulos_Print(eArticulo* this)
{
	int ret=0;
	int id_Articulo;
	char nombre[128];
	float precio;
	char medida[32];
	char rubroStr[128];

	if (this!=NULL)
	{
		if(eArticulo_getId(this,&id_Articulo))
		{
			if(eArticulo_getNombre(this,nombre))
			{
				if(eArticulo_getPrecio(this,&precio))
				{
					if(eArticulo_getMedida(this,medida))
					{
						if(eArticulo_getRubro(this, rubroStr))
						{
							printf("%d\t%-30.30s\t%-6.5s\t%-10.2f\t\t%-30.30s\n",id_Articulo,nombre,medida,precio,rubroStr);
						}
						ret=1;
					}
				}
			}
		}
	}

	return ret;
}


int eArticulo_OrdenPorArticulo(void* art1,void* art2)
{
	int ret=0;
	char nomArt1[128];
	char nombArt2[128];
	eArticulo* artiAux1= NULL;
	eArticulo* artiAux2= NULL;

	if(art1 != NULL && art2!= NULL)
	{
		artiAux1= (eArticulo*)art1;
		artiAux2= (eArticulo*)art2;
		if(eArticulo_getNombre(artiAux1,nomArt1) && eArticulo_getNombre(artiAux2,nombArt2))
		{
			if((stricmp(nomArt1,nombArt2))>0)
			{
				ret=1;
			}
			else if((stricmp(nomArt1,nombArt2))<0)
			{
				ret=-1;
			}

		}

	}
	return ret;
}



void eArticulo_DescuentoPorPrecio(void* art)
{
	float precio;
	int idRubro;
	int descPrecio=0;
	float precioFinal;
	eArticulo* artiAux= NULL;

	if(art != NULL)
	{
		artiAux=(eArticulo*)art;
		eArticulo_getIdRubro(artiAux,&idRubro);
		eArticulo_getPrecio(artiAux,&precio);
		if(idRubro==1 && precio>=120)
		{
			descPrecio=20;
		}
		else if(idRubro==2 && precio<=200)
		{
			descPrecio=10;
		}
		precioFinal=precio-(precio*(float)descPrecio/100);
		eArticulo_setPrecio(artiAux,precioFinal);
	}


}


int cantidad_ArticulosPrecioMayor100(void* pElement)
{
	int returnAux=0;
	float precio;

	if(pElement!=NULL)
	{
		pElement=(eArticulo*) pElement;

		if(eArticulo_getPrecio(pElement,&precio))
		{
			if(precio>100)
				{
					returnAux=1;
				}
			}
		}


	return returnAux;
}


int cantidad_ArticulosRubro(void* pElement)
{
	int returnAux=0;
	int idRubro;


	if(pElement!=NULL)
	{
		pElement=(eArticulo*) pElement;

		if(eArticulo_getIdRubro(pElement,&idRubro))
		{
			if(idRubro==1)
				{
					returnAux=1;
				}
		}


	}
	return returnAux;
}
