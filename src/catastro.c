/*
 * catastro.c
 *
 *  Created on: 22 jun. 2022
 *      Author: Miguel Pinto
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catastro.h"



int listadoCatastro(Catastro* list, int tam)
{
	int i;
	int respuesta;

	respuesta=-1;

	if(list != NULL)
	{
		for(i=0;i<tam;i++)
		{
			printf("\nidCatastro: %d\nlocalidad: %s\nmanzana: %d\nparcela: %d\n",
				(list+i)->idCatastro, (list+i)->localidad, (list+i)->manzana, (list+i)->parcela);

			respuesta=0;
		}
	}
	return respuesta;
}

int ordenamientoCatastro(Catastro* list, int tam)
{
	int i;
	int j;
	int devuelve;
	Catastro guardado;

	devuelve=-1;

	if(list != NULL && tam>0)
	{
		devuelve=0;
		for(i=0;i<tam;i++)
		{
			for(j=i+1;j<tam-1;j++)
			{
				if((list+i)->idCatastro>=1000 && (list+j)->idCatastro>=1000)
				{
					if(strcmp((list+i)->localidad,(list+j)->localidad)<=0)
					{
						guardado=list[j];
						list[j]=list[i];
						list[i]=guardado;
					}

				}
			}
		 }
	}

	return devuelve;
}


void mostrarCatastro(Catastro catastro)
{
	printf("ID Catastro: %d \t Localidad:  %s \t Manzana: %d \t Parcela %d \n",
			catastro.idCatastro,
			catastro.localidad,
			catastro.manzana,
			catastro.parcela);
}

int printCatastro(Catastro* lista, int len)
{
	int retorno = -1;
	int i;

	if(lista != NULL && len > 0)
	{
		printf("LISTA CATASTRO:\n");
		for(i=0; i<len; i++)
		{
			printf("=========================================================================================\n");
			mostrarCatastro(*(lista+i));
			printf("=========================================================================================\n");
			retorno = 1;
		}
	}

	return retorno;
}



