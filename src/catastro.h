/*
 * catastro.h
 *
 *  Created on: 22 jun. 2022
 *      Author: Miguel Pinto
 */

#ifndef SRC_CATASTRO_H_
#define SRC_CATASTRO_H_

#include "vivienda.h"

struct
{
	int idCatastro;
	char localidad[20];
	int manzana;
	int parcela;
}typedef Catastro;

int listadoCatastro(Catastro* list, int tam);
int ordenamientoCatastro(Catastro* list, int tam);
void mostrarCatastro(Catastro catastro);
int printCatastro(Catastro* lista, int len);

#endif /* SRC_CATASTRO_H_ */
