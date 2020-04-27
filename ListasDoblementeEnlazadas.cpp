#include"ListasDoblementeEnlazadas.h"
#include"DependenciasComunes.h"

void menuListasDobles()
{
	short userOption = 0;
	struct doble* pLista = NULL;
	struct doble* pRes = NULL;
	while (userOption != 12)
	{
		LIMPIAR_CONSOLA
			printf_s("\n");
		centrado("*************************");
		centrado("* TDA: Listas doblemente enlazadas *");
		centrado("*************************");
		printf_s("\n");
		printf_s("\n\t 1.-Insertar por cabeza");
		printf_s("\n\t 2.-Insertar por fondo");
		printf_s("\n\t 3.-Buscar un elemento");
		printf_s("\n\t 4.-Borrar un elemento");
		printf_s("\n\t 5.-Imprimir la lista");
		printf_s("\n\t 0.-Borrar toda la lista");
		printf_s("\n\t 12.-Volver al menú principal");
		switch (userOption = pedir_Short(TERMINAL_OPCION))
		{
		case 1: // Insertar por cabeza
			insertarPorInicioListaDoble(&pLista);
			break;
		case 2: // Insertar por fondo
			insertarPorFondoListaDoble(&pLista);
			break;
		case 3: // Buscar un elemento
			pRes = buscarElementoListaDoble(pLista, pedir_Short("Introduce el número a buscar"));
			if (pRes)
				printf_s("Se encontró el valor con la dirección de memoria: %p", pRes);
			else
				printf_s("No se encontró el valor o la lista está vacía");
			break;
		case 4: // Borrar un elemento
			borrarElementoListaDoble(&pLista, pedir_Short("Introduce el número a borrar:"));
			break;
		case 5: // Imprimir lista
			imprimirListaDoble(pLista);
			imprimirListaDobleInverso(pLista);
			break;
		case 0: // Borrar toda la lista
			borrarListaDobleCompleta(&pLista);
			break;
		case 12:
			borrarListaDobleCompleta(&pLista);
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
									TDA -> Funciones
##############################################################################################################################*/

/*  El utilizar una función para crear las listas nos evita errores por no inicializarlas correctamete,
	esto suele pasar muy frecuentemente y generalmente nos damos cuenta cuando buscamos o insertamos*/
struct doble* crearListaDoble(int valor)
{
	struct doble* pLista = new struct doble;
	pLista->valor = valor;
	pLista->siguiente = NULL;
	pLista->anterior = NULL;
	return pLista;
}

void insertarPorInicioListaDoble(struct doble** ppLista)
{
	struct doble* pLista = crearListaDoble(pedir_Short("Introduce el valor"));
	pLista->siguiente = *ppLista;
	if(*ppLista)
		(*ppLista)->anterior = pLista;
	*ppLista = pLista;
}

void insertarPorFondoListaDoble(struct doble** ppLista) 
{
	struct doble* pNueva = crearListaDoble(pedir_Int("Ingrese el valor"));
	if (*ppLista)
	{
		struct doble* pLista = *ppLista;
		for (; pLista->siguiente; pLista = pLista->siguiente);
		pLista->siguiente = pNueva;
		pNueva->anterior = pLista;
	}
	else
		*ppLista = pNueva;
}


struct doble* buscarElementoListaDoble(struct doble* pLista, int valor)
{
	for (; pLista && pLista->valor != valor; pLista = pLista->siguiente);
	return pLista;
}

void borrarElementoListaDoble(struct doble** ppLista, int valor) 
{
	struct doble* pAux = NULL;
	if (*ppLista)
		if ((*ppLista)->valor == valor)
		{
			pAux = *ppLista;
			*ppLista = (*ppLista)->siguiente;
			if(*ppLista)
				(*ppLista)->anterior = NULL;
			free(pAux);
		}
		else
		{
			struct doble* pLista = *ppLista;
			for (; pLista && pLista->siguiente; pLista = pLista->siguiente)
				if (pLista->siguiente->valor == valor)
				{
					pAux = pLista->siguiente;
					pLista->siguiente = pAux->siguiente;
					if (pLista->siguiente)
						pLista->siguiente->anterior = pLista;
					free(pAux);
				}
		}
}

void borrarListaDobleCompleta(struct doble** ppLista)
{
	if (*ppLista)
	{
		borrarListaDobleCompleta(&(*ppLista)->siguiente);
		free((*ppLista));
		(*ppLista) = NULL;
	}
}


void imprimirListaDoble(struct doble* pLista)
{
	LIMPIAR_CONSOLA
		printf_s("\n\tLista doble al derecho: ");
	if (pLista)
	{
		for (; pLista; pLista = pLista->siguiente)
			printf_s("[%3d]->", pLista->valor);
		printf_s("NULL\n\n");
	}
	else
		printf_s("NULL\n\n");
	PAUSA
}

void imprimirListaDobleInverso(struct doble* pLista)
{
	LIMPIAR_CONSOLA
		printf_s("\n\tLista doble al inverso: ");
	// Para comprobar que esta enlazada con la anterior
	for (; pLista && pLista->siguiente; pLista = pLista->siguiente);
	if(pLista)
		for(; pLista; pLista = pLista->anterior)
			printf_s("[%3d]->", pLista->valor);
	printf_s("NULL\n\n");
	PAUSA
}

// La versión recursiva sería:
void imprimirListaDobleInversoRecursiva(struct doble* pLista)
{
	if (pLista) 
	{
		imprimirListaDobleInversoRecursiva(pLista->siguiente);
		printf_s("[%3d]->", pLista->valor);
	}
	printf_s("NULL\n\n");
}

