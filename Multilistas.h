#pragma once
#include"Pilas.h"

/*##############################################################################################################################
									TDA Multilista -> Lista-Pila
##############################################################################################################################*/

struct multi
{
	int valor;
	struct multi* siguiente;
	struct pila* abajo;
};

/*##############################################################################################################################
									Prototipos de las Funciones
##############################################################################################################################*/

void menuMultilistas();
struct multi* crearMultilista(int valor);
void insertarPorInicioMultilista(struct multi** ppLista);
void insertarPorFondoMultilista(struct multi** ppLista);
void buscarElementoMultilista(struct multi* pLista, int valor);
void borrarMultilista(struct multi** ppLista);
void imprimirMultilista(struct multi* pLista);