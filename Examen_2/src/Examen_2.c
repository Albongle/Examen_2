/*
 ============================================================================
 Name        : Examen_2.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "articulo.h"
#include "controller.h"
#include "parser.h"
#include "informes.h"
#define ARCH "mapeado.csv"



int menu();



int main()
{
	system("COLOR 1F");
	setbuf(stdout, NULL);
    int opcion;

    LinkedList* listaArticulos= ll_newLinkedList();
    do{
    	system("CLS()");
    	printf("\t\t****Linkedist posee %d  en su lista****\n\n",ll_len(listaArticulos));
    	opcion=menu();
        switch(opcion)
        {
            case 1:
            {
            	controller_loadFromText(listaArticulos);
            	break;
            }
            case 2:
            {
            	controller_sort(listaArticulos);
            	break;
            }
            case 3:
            {
            	controller_List(listaArticulos);
            	break;
            }
            case 4:
            {
            	 controller_saveAsText(ARCH,listaArticulos);
            	break;
            }
            case 5:
            {
            	informes(listaArticulos);
            	break;
            }

            default:
            {
            	controller_memoryFree(listaArticulos);
            	break;
            }
        }
        system("PAUSE()");
    }while(opcion != 6);


    return 0;
}



int menu()
{
	int opcion=-1;
	printf("Menu de opciones\n\n");
	printf("1-Cargar archivo\n");
	printf("2-Ordenar la lista\n");
	printf("3-Imprimir\n");
	printf("4-Generar Informe\n");
	printf("5-Informe de Articulos\n");
	printf("6-Salir\n");
	fflush(stdin);
	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",1,6,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}

return opcion;
}
