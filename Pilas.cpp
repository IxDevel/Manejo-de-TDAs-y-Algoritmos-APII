#include "DependenciasComunes.h"
#include "Pilas.h"

void menuPilas()
{
	short userOption = 0;
	struct pila* pPila = NULL;
	while (userOption != 12)
	{
		LIMPIAR_CONSOLA
			printf_s("\n");
		centrado("*************************");
		centrado("* TDA: Pilas *");
		centrado("*************************");
		printf_s("\n");
		printf_s("\n\t 1.-Insertar por cabeza");
		printf_s("\n\t 2.-Insertar por fondo");
		printf_s("\n\t 3.-Buscar un elemento");
		printf_s("\n\t 4.-Borrar un elemento");
		printf_s("\n\t 5.-Imprimir la pila");
		printf_s("\n\t 6.-Invertir la pila");
		printf_s("\n\t 0.-Borrar toda la pila");
		printf_s("\n\t 12.-Volver al menú principal");
		switch (userOption = pedir_Short(TERMINAL_OPCION))
		{
		case 1: // Insertar por cabeza
			apilar(&pPila, pedir_Int("Introduce el nuevo valor"));
			break;
		case 2: // Insertar por fondo
			insertarPorFondoPila(&pPila, pedir_Int("Introduce el nuevo valor"));
			break;
		case 3: // Buscar un elemento
			buscarElementoPila(&pPila, pedir_Int("Intoduce el valor a buscar"));
			PAUSA
			break;
		case 4: // Borrar un elemento
			borrarElementoPila(&pPila, pedir_Int("Introduce el valor a borrar"));
			break;
		case 5: // Imprimir lista
			LIMPIAR_CONSOLA
			printf_s("\n\tPila: ");
			imprimirPila(&pPila);
			printf_s("\n");
			PAUSA
			break;
		case 6: // Voltear Pila
			voltearPila(&pPila);
			PAUSA
				break;
		case 0: // Borrar toda la lista
			borrarPilaCompleta(&pPila);
			break;
		case 12:
			borrarPilaCompleta(&pPila);
			return;
			break;
		default:
			mostrarError(OPCION_NO_VALIDA);
			PAUSA;
			break;
		}
	}
}

/*##############################################################################################################################
									TDA -> Primitivas
##############################################################################################################################*/

int vacio(struct pila* pPila) {
	return	pPila == NULL;
}

int tope(struct pila* pPila) {
	if (!vacio(pPila))
		return pPila->valor;
	return 0;
}

void apilar(struct pila** ppPila, int x) {
	struct pila* pPila = new pila;
	pPila->valor = x;
	pPila->siguiente = *ppPila;
	*ppPila = pPila;
}

void desapilar(struct pila **ppPila) {
	struct pila* pPila = *ppPila;
	if (!vacio(pPila)) {
		*ppPila = (*ppPila)->siguiente;
		delete pPila;
	}
}
/*##############################################################################################################################
									TDA -> Funciones
##############################################################################################################################*/

void insertarPorFondoPila(struct pila** ppPila, int val) {
	if(!vacio(*ppPila)) {
		int num = tope(*ppPila);
		desapilar(ppPila);
		insertarPorFondoPila(ppPila, val);
		apilar(ppPila, num);
	}
	else
		apilar(ppPila, val);
}

void buscarElementoPila(struct pila** ppPila, int valor) {
	if (!vacio(*ppPila)) {
		int num = tope(*ppPila);
		if (num == valor) {
			printf_s("El valor se encuentra en la pila");
			return;
		}
		desapilar(ppPila);
		buscarElementoPila(ppPila, valor);
		apilar(ppPila, num);
	}
	printf_s("El valor no se encuentra o la pila está vacia");
}

void borrarElementoPila(struct pila** ppPila, int valor) {
	if (!vacio(*ppPila)) {
		int num = tope(*ppPila);
		desapilar(ppPila);
		if (num == valor)
			return;
		borrarElementoPila(ppPila, valor);
		apilar(ppPila, num);
	}
}

// Otra versión
void borrarElementoPila2(struct pila** ppPila, int valor) {
	if (!vacio(*ppPila)) {
		int num = tope(*ppPila);
		desapilar(ppPila);
		borrarElementoPila(ppPila, valor);
		if (num != valor)
			apilar(ppPila, num);
	}
}

void borrarPilaCompleta(struct pila** ppPila) {
	if (!vacio(*ppPila)) {
		desapilar(ppPila);
		borrarPilaCompleta(ppPila);
	}
}

void imprimirPila(struct pila** ppPila) {
	if (!vacio(*ppPila)) {
		int num = tope(*ppPila);
		desapilar(ppPila);
		printf_s("[%2d]", num);
		imprimirPila(ppPila);
		apilar(ppPila, num);
	}
}

void voltearPila(struct pila **ppPila) {
	if (!vacio(*ppPila)) {
		int num = tope(*ppPila);
		desapilar(ppPila);
		voltearPila(ppPila);
		insertarPorFondoPila(ppPila, num);
	}
}
