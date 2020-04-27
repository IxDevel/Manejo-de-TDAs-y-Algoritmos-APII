#include "DependenciasComunes.h"
#include "Multilistas.h"

void menuMultilistas() {
	short userOption = 0;
	struct multi* lista = NULL;
	while (userOption != 12) 
	{
		LIMPIAR_CONSOLA
		printf_s("\n");
		centrado("***********************************");
		centrado("* TDA: Multilistas -> Lista->pila *");
		centrado("***********************************");
		printf_s("\n");
		printf_s("\n\t 1.-Insertar por cabeza");
		printf_s("\n\t 2.-Insertar por fondo");
		printf_s("\n\t 3.-Buscar un elemento");
		printf_s("\n\t 4.-Imprimir la lista");
		printf_s("\n\t 0.-Borrar toda la lista");
		printf_s("\n\t 12.-Volver al menú principal");
		switch (userOption = pedir_Short(TERMINAL_OPCION)) 
		{
		case 1: // Insertar por cabeza
			insertarPorInicioMultilista(&lista);
			break;
		case 2: // Insertar por fondo
			insertarPorFondoMultilista(&lista);
			break;
		case 3: // Buscar un elemento
			buscarElementoMultilista(lista, pedir_Int("Introduce el valor a buscar"));
			break;
		case 4: // Imprimir lista
			imprimirMultilista(lista);
			break;
		case 0: // Borrar toda la lista
			borrarMultilista(&lista);
			break;
		case 12:
			borrarMultilista(&lista);
			return;
			break;
		default:
			mostrarError(OPCION_NO_VALIDA);
			PAUSA;
			break;
		}
	}
}

struct multi* crearMultilista(int valor) {
	struct multi* lista = new multi;
	lista->valor = valor;
	lista->siguiente = NULL;
	lista->abajo = NULL;
	return lista;
}

void insertarPorInicioMultilista(struct multi** ppLista) {
	int valor = pedir_Int("Introduce el nuevo valor");
	struct multi* lista = crearMultilista(valor);
	lista->siguiente = *ppLista;
	*ppLista = lista;
}

void insertarPorFondoMultilista(struct multi** ppLista) {

	if (*ppLista) {
		int valor = pedir_Int("Introduce el nuevo valor");
		struct multi* pLista = *ppLista;
		for (	; pLista->siguiente; pLista = pLista->siguiente);
		pLista->siguiente = crearMultilista(valor);
	}
	else
		insertarPorInicioMultilista(ppLista);
}

void buscarElementoMultilista(struct multi* pLista, int valor) {
	if (pLista) {
		for (; pLista; pLista = pLista->siguiente) {
			if (pLista->valor = valor)
				printf_s("\n\tEncontré el valor en la multilista\n");
			buscarElementoPila(&pLista->abajo, valor);
		}
	}
	printf_s("\n\tLa multilista está vacia o no tiene el valor\n");
}

void borrarMultilista(struct multi** ppLista) {
	if (*ppLista) {
		borrarMultilista(&(*ppLista)->siguiente);
		borrarPilaCompleta(&(*ppLista)->abajo);
		delete *ppLista;
		*ppLista = NULL;
	}
}

void imprimirMultilista(struct multi* pLista) {
	LIMPIAR_CONSOLA
	if (pLista)
		for (; pLista; pLista = pLista->siguiente) {
			printf_s("\n\t Multilista: [%2d] Pila: ", pLista->valor);
			imprimirPila(&pLista->abajo);
		}
	printf_s("\n");
	PAUSA
}