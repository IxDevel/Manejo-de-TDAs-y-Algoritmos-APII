#pragma once

/*##############################################################################################################################
									TDA Pila
##############################################################################################################################*/

struct pila {
	int valor;
	struct pila* siguiente;
};

/*##############################################################################################################################
									Primitivas de Pila
##############################################################################################################################*/

int vacio(struct pila* pPila);
int tope(struct pila* pPila);
void apilar(struct pila** ppPila, int x);
void desapilar(struct pila** ppPila);

/*##############################################################################################################################
									Prototipos de las funciones
##############################################################################################################################*/

void menuPilas();
void insertarPorFondoPila(struct pila** ppPila, int valor);
void buscarElementoPila(struct pila** ppPila, int valor);
void borrarElementoPila(struct pila** ppPila, int valor);
void borrarPilaCompleta(struct pila** ppPila);
void imprimirPila(struct pila** ppPila);
void voltearPila(struct pila** ppPila);
