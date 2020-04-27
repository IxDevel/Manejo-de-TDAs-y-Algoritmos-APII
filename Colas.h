#pragma once

/*##############################################################################################################################
									TDA Cola
##############################################################################################################################*/

struct cola {
	int valor;
	struct cola* siguiente;
};

/*##############################################################################################################################
									Primitivas de Cola
##############################################################################################################################*/

int vacio(struct cola* pCola);
int tope(struct cola* pCola);
void encolar(struct cola** ppCola, int x);
void desencolar(struct cola** ppCola);

/*##############################################################################################################################
									Prototipos de las Funciones
##############################################################################################################################*/

void menuColas();
void buscarElementoCola(struct cola** ppCola, int valor);
void borrarElementoCola(struct cola** ppCola, int valor);
void borrarColaCompleta(struct cola** ppCola);
void imprimirCola(struct cola** ppCola);
void voltearCola(struct cola** ppCola);
