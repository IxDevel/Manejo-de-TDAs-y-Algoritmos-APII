#include "DependenciasComunes.h"
#include "Colas.h"

void menuColas()
{
	short userOption = 0;
	struct cola* pCola = NULL;
	while (userOption != 12)
	{
		LIMPIAR_CONSOLA
			printf_s("\n");
		centrado("*************************");
		centrado("* TDA: Colas *");
		centrado("*************************");
		printf_s("\n");
		printf_s("\n\t 1.-Encolar");
		printf_s("\n\t 2.-Desencolar");
		printf_s("\n\t 3.-Imprimir cola");
		printf_s("\n\t 4.-Buscar un elemento");
		printf_s("\n\t 5.-Borrar un elemento");
		printf_s("\n\t 6.-Invertir la cola");
		printf_s("\n\t 0.-Borrar toda la cola");
		printf_s("\n\t 12.-Volver al menú principal");
		switch (userOption = pedir_Short(TERMINAL_OPCION))
		{
		case 1: // Encolar
			encolar(&pCola, pedir_Int("Introduce el nuevo valor"));
			break;
		case 2: // Desencolar
			desencolar(&pCola);
			break;
		case 3: // Imprimir cola
			LIMPIAR_CONSOLA
			printf_s("\n\t Cola: ");
			imprimirCola(&pCola);
			printf_s("\n\t");
			voltearCola(&pCola);
			PAUSA
			break;
		case 4: // Buscar elemento
			LIMPIAR_CONSOLA
			buscarElementoCola(&pCola, pedir_Int("Introduce el valor a buscar"));
			voltearCola(&pCola);
			printf_s("\n\t");
			PAUSA
			break;
		case 5: // Borrar elemento
			borrarElementoCola(&pCola, pedir_Int("Introduce el elemento a eliminar"));
			voltearCola(&pCola);
			break;
		case 6: // Voltear cola
			voltearCola(&pCola);
			break;
		case 0: // Borrar toda la lista
			borrarColaCompleta(&pCola);
			break;
		case 12:
			borrarColaCompleta(&pCola);
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

int vacio(struct cola* pCola) {
	return pCola == NULL;
}

int tope(struct cola* pCola) {
	if (!vacio(pCola))
		return pCola->valor;
	return 0;
}

// Siempre se inserta en el fondo, ya que se debe desencolar por el inicio para mejorar el redimiento
void encolar(struct cola** ppCola, int x) {

	if (!vacio(*ppCola)) {
		struct cola* pCola = *ppCola;
		for (; pCola->siguiente; pCola = pCola->siguiente);
		pCola->siguiente = new cola;
		pCola->siguiente->valor = x;
		pCola->siguiente->siguiente = NULL;
	}
	else {
		*ppCola = new cola;
		(*ppCola)->valor = x;
		(*ppCola)->siguiente = NULL;
	}
}

// Siempre se desencola al inicio para mejorar el rendimiento
void desencolar(struct cola** ppCola) {
	if (!vacio(*ppCola)) {
		struct cola* pCola = *ppCola;
		*ppCola = (*ppCola)->siguiente;
	}
}

/*##############################################################################################################################
									TDA -> Funciones
##############################################################################################################################*/

void buscarElementoCola(struct cola** ppCola, int valor) {
	if (!vacio(*ppCola)) {
		int num = tope(*ppCola);
		if (num == valor)
			printf_s("\n\tEl elemento se encuenta en la cola\n");
		desencolar(ppCola);
		buscarElementoCola(ppCola, valor);
		encolar(ppCola, num);
	}
}

void borrarElementoCola(struct cola** ppCola, int valor) {
	if (!vacio(*ppCola)) {
		int num = tope(*ppCola);
		desencolar(ppCola);
		borrarElementoCola(ppCola, valor);
		if (num != valor)
			encolar(ppCola, num);
	}
}

void borrarColaCompleta(struct cola** ppCola) {
	if (!vacio(*ppCola)) {
		desencolar(ppCola);
		borrarColaCompleta(ppCola);
	}
}

void imprimirCola(struct cola** ppCola) {
	if (!vacio(*ppCola)) {
		int num = tope(*ppCola);
		printf_s("[%2d]", num);
		desencolar(ppCola);
		imprimirCola(ppCola);
		encolar(ppCola, num);
	}
}

void voltearCola(struct cola** ppCola) {
	if (!vacio(*ppCola)) {
		int num = tope(*ppCola);
		desencolar(ppCola);
		voltearCola(ppCola);
		encolar(ppCola, num);
	}
}
