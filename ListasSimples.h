#pragma once

/*##############################################################################################################################
									TDA Lista simple
##############################################################################################################################*/

struct lista
{
	int valor;
	struct lista* siguiente;
};

/*##############################################################################################################################
									Prototipos de las Funciones
##############################################################################################################################*/

void menuListasSimples();
struct lista* crearListaSimple(int valor);
void insertarPorInicioListaSimple(struct lista** ppLista);
void insertarPorFondoListaSimple(struct lista** ppLista);
struct lista* buscarElementoListaSimple(struct lista* pLista, int valor);
void borrarElementoListaSimple(struct lista **ppLista, int valor);
void borrarListaSimpleCompleta(struct lista** ppLista);
void imprimirListaSimple(struct lista* pLista);

void menuListasCirculares();
void insertarPorInicioListaCircular(struct lista** ppLista);
void insertarPorFondoListaCircular(struct lista** ppLista);
struct lista* buscarElementoListaCircular(struct lista* pLista, int valor);
void borrarElementoListaCircular(struct lista** ppLista, int valor);
void borrarListaCircularCompleta(struct lista** ppLista);
void imprimirListaCircular(struct lista* pLista);