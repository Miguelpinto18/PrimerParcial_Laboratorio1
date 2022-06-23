/*
 ======================================================================================================================================================
 Name        : Primer parcial
 Author      : Miguel Pinto
 DIV	     : D
 Description : Se necesita gestionar el Censo Nacional 2022 y para eso se deberá desarrollar lo siguiente:
 ======================================================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "censistas.h"
#include "validaciones.h"
#include "vivienda.h"
#include "catastro.h"

#define CANTIDAD 500
#define CENSISTAS 3
#define CATASTROS 5

int main(void)
{
	setbuf(stdout, NULL);

	int validacion;
	int respuesta;
	int id;
	int subMenu;

	Vivienda casas[CANTIDAD];
	Censista sensadores[CENSISTAS];
	Catastro catastro[]={{1000, "Avellaneda", 28, 1540}, {1001, "Lanus", 43, 1789}, {1002, "Quilmes", 32, 1624}, {1003, "La Plata", 67, 1677},{1004, "Lomas de Zamora", 32, 1923}};

	//printf("%d", catastro[0].manzana);

	id=20000;

	initViviendas(casas,CANTIDAD);
	initcensista(sensadores);

//MENU
	do
	{
		getValidacionMaximoMinimo(&respuesta,"\nIngrese un numero: \n"
				" 1. Altas\n"
				" 2. Modificar vivienda\n"
				" 3. Baja vivienda\n"
				" 4. Listar viviendas\n"
				" 5. Listar censistas\n"
				" 6. Listar catastro\n"
				" 7. Informes\n"
				" 8. Salir ", "\nERROR, Reingrese un numero valido(1-10)\n"
					" 1. Altas\n"
					" 2. Modificar vivienda \n"
					" 3. Baja vivienda\n"
					" 4. Listar viviendas \n"
					" 5. Listar censistas\n"
					" 6. Listar catastro\n"
				    " 7. Informes\n"
					" 8. Salir ", 1, 10);

		validacion=contadorViviendasRegistradas(casas,CANTIDAD);


		switch(respuesta)
			{
				case 1:
					id++;
					alta(casas,id,CANTIDAD);
					printf("\nEl ID de esta vivienda es: %d\n", id);
				break;

				case 2:
					if(validacion!=0)
					{
						modificacion(casas,CANTIDAD);
					}
					else
					{
						printf("\nNo hay viviendas ingresadas, por favor ingrese una vivienda antes.\n");
					}
				break;

				case 3:
					if(validacion!=0)
					{
						baja(casas,CANTIDAD);
					}
					else
					{
						printf("\nNo hay viviendas ingresadas, por favor ingrese una vivienda antes.\n");
					}
				break;

				case 4:
					if(validacion!=0)
					{
						ordenamientoViviendas(casas,CANTIDAD);
						mostrarViviendas(casas,CANTIDAD);
					}
					else
					{
						printf("\nNo hay viviendas ingresadas, por favor ingrese una vivienda antes.\n");
					}
				break;

				case 5:
					if(validacion!=0)
					{
						censistaPorVivienda(casas,CANTIDAD,sensadores, CENSISTAS);
					}
					else
					{
						printf("\nNo hay viviendas ingresadas, por favor ingrese una vivienda antes.\n");
					}
				break;

				case 6:
					 ordenamientoCatastro(catastro,20);
					 printCatastro(catastro, CATASTROS);
				break;

				case 7:
					getValidacionMaximoMinimo(&subMenu,"\nIngrese un numero: \n"
								" 1. Elija un tipo de vivienda\n"
								" 2. Elija una localidad\n"
								" 3. Cantidad de viviendas censadas\n"
								" 4. Elija un censista\n"
								" 5. Cantidad de viviendas de tipo “casa” censadas\n"
								" 6. Cantidad de viviendas de tipo “departamento” de la localidad de Lanús\n"
								" 7. Salir ", "\nERROR, Reingrese un numero valido\n", 1,7);

					switch(subMenu)
					{
						case 1:
							tipoVivienda(casas, CANTIDAD);
						break;

						case 2:

						break;

						case 5:

						break;



					}


			}

	}while(respuesta!=11);

	return 0;
}


