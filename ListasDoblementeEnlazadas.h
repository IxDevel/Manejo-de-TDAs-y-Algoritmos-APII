#pragma once

/*##############################################################################################################################
									TDA Lista simple
##############################################################################################################################*/

struct doble
{
	int valor;
	struct doble* anterior;
	struct doble* siguiente;
};

/*##############################################################################################################################
									Prototipos de las Funciones
##############################################################################################################################*/

void menuListasDobles();
struct doble* crearListaDoble(int valor);
void insertarPorInicioListaDoble(struct doble** ppLista);
void insertarPorFondoListaDoble(struct doble** ppLista);
struct doble* buscarElementoListaDoble(struct doble* pLista, int valor);
void borrarElementoListaDoble(struct doble** ppLista, int valor);
void borrarListaDobleCompleta(struct doble** ppLista);
void imprimirListaDoble(struct doble* pLista);
void imprimirListaDobleInverso(struct doble* pLista);