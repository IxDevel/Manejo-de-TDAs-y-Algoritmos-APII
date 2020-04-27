#include "ListasSimples.h"
#include "DependenciasComunes.h"

void menuListasCirculares()
{
	short userOption = 0;
	struct lista* pLista = NULL;
	struct lista* pRes = NULL;
	while (userOption != 12)
	{
		LIMPIAR_CONSOLA
			printf_s("\n");
		centrado("*************************");
		centrado("* TDA: Listas simples *");
		centrado("*************************");
		printf_s("\n");
		printf_s("\n\t 1.-Insertar por cabeza");
		printf_s("\n\t 2.-Insertar por fondo");
		printf_s("\n\t 3.-Buscar un elemento");
		printf_s("\n\t 4.-Borrar un elemento");
		printf_s("\n\t 5.-Imprimir la circular");
		printf_s("\n\t 0.-Borrar toda la circular");
		printf_s("\n\t 12.-Volver al menú principal");
		switch (userOption = pedir_Short(TERMINAL_OPCION))
		{
		case 1: // Insertar por cabeza
			insertarPorInicioListaCircular(&pLista);
			break;
		case 2: // Insertar por fondo
			insertarPorFondoListaCircular(&pLista);
			break;
		case 3: // Buscar un elemento
			pRes = buscarElementoListaCircular(pLista, pedir_Short("Introduce el número a buscar"));
			if (pRes)
				printf_s("Se encontró el valor con la dirección de memoria: %p", pRes);
			else
				printf_s("No se encontró el valor o la circular está vacía");
			break;
		case 4: // Borrar un elemento
			borrarElementoListaCircular(&pLista, pedir_Short("Introduce el número a borrar"));
			break;
		case 5: // Imprimir circular
			imprimirListaCircular(pLista);
			break;
		case 0: // Borrar toda la circular
			borrarListaCircularCompleta(&pLista);
			break;
		case 12:
			borrarListaCircularCompleta(&pLista);
			return;
			break;
		default:
			mostrarError(OPCION_NO_VALIDA);
			PAUSA;
			break;
		}
	}
}

void insertarPorInicioListaCircular(struct lista** ppLista) 
{
	int valor = pedir_Short("Introduce el valor");
	if (*ppLista)
	{	
		struct lista* pUltimo = *ppLista;
		for ( ; pUltimo->siguiente != *ppLista; pUltimo = pUltimo->siguiente);
		struct lista *pAux = crearListaSimple(valor);
		pAux->siguiente = *ppLista;
		pUltimo->siguiente = pAux;
		*ppLista = pAux;
	}
	else
	{
		*ppLista = crearListaSimple(valor);
		(*ppLista)->siguiente = *ppLista;
	}
}

void insertarPorFondoListaCircular(struct lista** ppLista)
{
	int valor = pedir_Short("Introduce el valor");
	if (*ppLista)
	{
		struct lista* pUltimo = *ppLista;
		for (; pUltimo->siguiente != *ppLista; pUltimo = pUltimo->siguiente);
		pUltimo->siguiente = crearListaSimple(valor);
		pUltimo->siguiente->siguiente = *ppLista;
	}
	else
	{
		insertarPorInicioListaCircular(ppLista);
	}
}

struct lista* buscarElementoListaCircular(struct lista* pLista, int valor)
{
	if (pLista)
	{
		for (struct lista* pCabeza = pLista; pLista->valor != valor && pLista->siguiente != pCabeza; pLista = pLista->siguiente);
		if (pLista->valor == valor)
			return pLista;
		return NULL;
	}	
}

void borrarElementoListaCircular(struct lista** ppLista, int valor)
{
	struct lista* pLista = NULL;
	if (*ppLista)
	{
		if ((*ppLista)->valor == valor)
		{
			pLista = *ppLista;
			if ((*ppLista)->siguiente = *ppLista)
				*ppLista = NULL;
			else
				*ppLista = (*ppLista)->siguiente;
			free(pLista);
		}
		else
		{
			for (pLista = *ppLista; pLista->siguiente->valor != valor && pLista->siguiente->siguiente != *ppLista; pLista = pLista->siguiente);
			if (pLista->siguiente->valor == valor)
			{
				struct lista* pAux = pLista->siguiente;
				pLista->siguiente = pAux->siguiente;
				free(pAux);
			}
		}
	}
}

void borrarListaCircularCompleta(struct lista** ppLista)
{
	if (*ppLista)
	{
		for (struct lista* pLista = (*ppLista)->siguiente, *pAux = NULL; pLista->siguiente != *ppLista;)
		{
			pAux = pLista;
			pLista = pLista->siguiente;
			free(pAux);
		}
		free(*ppLista);
		*ppLista = NULL;
	}
}

void imprimirListaCircular(struct lista* pLista)
{
	LIMPIAR_CONSOLA	
	printf_s("\n\tLista circular: ");
	if (pLista)
	{
		printf_s("[%3d]->", pLista->valor);
		pLista = pLista->siguiente;
		for (struct lista* pCabeza = pLista;  pLista->siguiente != pCabeza; pLista = pLista->siguiente)
			printf_s("[%3d]->", pLista->valor);	
	}
	printf_s("NULL\n\n");
	PAUSA;
}