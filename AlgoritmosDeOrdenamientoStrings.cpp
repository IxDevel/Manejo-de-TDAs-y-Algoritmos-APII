#include "DependenciasComunes.h"
#include "AlgoritmosDeOrdenamiento.h"
#include <string.h>

void borrarArrayStrings(char*** arrayStrings, int* nroElementosArrayStrings);

void menuAlgoritmosDeOrdenamientoStrings()
{
	char** arrayStrings = NULL;
	int nroElmentosArrayStrings = 0;
	short userOption = 0;
	while (userOption != 12)
	{
		LIMPIAR_CONSOLA
			printf_s("\n");
		centrado("*************************");
		centrado("* Menú algoritmos de ordenamiento sobre cadenas *");
		centrado("*************************");
		printf_s("\n");
		printf_s("\n\t 1.-Crear un array");
		printf_s("\n\t 2.-Imprimir array");
		printf_s("\n\t 3.-Aplicar intercambio");
		printf_s("\n\t 4.-Aplicar selección");
		printf_s("\n\t 5.-Aplicar burbuja");
		printf_s("\n\t 6.-Aplicar inserción");
		printf_s("\n\t 7.-Aplicar quicksort");
		printf_s("\n\t 8.-Aplicar búsqueda binaria");
		printf_s("\n\t 12.-Salir");
		switch (userOption = pedir_Short(TERMINAL_OPCION))
		{
			case 1: // Crear array de cadenas
				crearArrayStrings(&arrayStrings, &nroElmentosArrayStrings);
				break;
			case 2: // Imprimir array de cadenas
				imprimirArrayStrings(arrayStrings, nroElmentosArrayStrings);
				break;
			case 3: // Aplicar intercambio en cadenas
				aplicarIntercambioStrings(arrayStrings, nroElmentosArrayStrings);
				break;
			case 4: // Aplicar selección en cadenas
				aplicarIntercambioStrings(arrayStrings, nroElmentosArrayStrings);
				break;
			case 5: // Aplicar burbuja en enteros
				aplicarBurbujaStrings(arrayStrings, nroElmentosArrayStrings);
				break;
			case 6: // Aplicar baraja en enteros
				aplicarInsercionStrings(arrayStrings, nroElmentosArrayStrings);
				break;
			case 7: // Aplicar quick sort en cadenas
				aplicarQuickSortStrings(arrayStrings, 0, nroElmentosArrayStrings - 1);
				break;
			case 8: // Aplicar búsqueda binaria en cadenas
				aplicarIntercambioStrings(arrayStrings, nroElmentosArrayStrings);
				aplicarBusquedaBinariaStrings(arrayStrings, nroElmentosArrayStrings);
				break;
			case 12:
				borrarArrayStrings(&arrayStrings, &nroElmentosArrayStrings);
				break;
			default:
				mostrarError(OPCION_NO_VALIDA);
				PAUSA;
				break;
		}
	}
}

void crearArrayStrings(char*** pArrayStrings, int* pNroElementosArrayStrings)
{
	LIMPIAR_CONSOLA
	borrarArrayStrings(pArrayStrings, pNroElementosArrayStrings);
	do 
	{
		*pNroElementosArrayStrings = pedir_Int("Introduce el número de cadenas");
	} while (*pNroElementosArrayStrings < 0);
	*pArrayStrings = (char**) malloc(sizeof(char*) * (*pNroElementosArrayStrings));
	for (int i = 0; i < *pNroElementosArrayStrings; i++)
	{
		printf_s("\n\tElemento %3d ", i + 1);
		(*pArrayStrings)[i] = (char*) malloc(sizeof(char) * STRLONG_3 + 1);
		pedir_Cadena((*pArrayStrings)[i], STRLONG_3, "Introduce la cadena (Max 100 caracteres)");
	}
}

void imprimirArrayStrings(char** const  arrayStrings, int nroElementosArrayStrings)
{
	LIMPIAR_CONSOLA
		for (int i = 0; i < nroElementosArrayStrings; i++)
			printf_s("\n\t[%3d] %s", i + 1, arrayStrings[i]);
	printf_s("\n");
	PAUSA
}

// Esto se puede debido a que no son char* const array, es decir que todos los char array[] son punteros constantes
// No confundir con punteros a constantes ejm const char
void swap(char** stringA, char** stringB)
{
	char* c = *stringA;
	*stringA = *stringB;
	*stringB = c;
}

void aplicarIntercambioStrings(char** const  arrayStrings, int nroElementosArrayStrings)
{

	for (int i = 0; i < nroElementosArrayStrings; i++)
		for (int j = i + 1; j < nroElementosArrayStrings; j++)
			if (strcmp(arrayStrings[i], arrayStrings[j]) > 0)
				swap(&arrayStrings[i], &arrayStrings[j]);
}

void aplicarSeleccionStrings(char** const  arrayStrings, int nroElementosArrayStrings)
{
	int minPos = 0;
	for (int i = 0; i < nroElementosArrayStrings; i++)
	{
		minPos = i;
		for (int j = i + 1; j < nroElementosArrayStrings; j++)
			if (strcmp(arrayStrings[minPos], arrayStrings[j]) > 0)
				minPos = j;
		if (minPos != i)
			swap(&arrayStrings[minPos], &arrayStrings[i]);
	}
}
		

void aplicarBurbujaStrings(char** const  arrayStrings, int nroElementosArrayStrings)
{
	for (int i = 0, cont = 1; (i < nroElementosArrayStrings - 1) && (cont != 0); i++)
	{
		cont = 0;
		for(int j = 0; j < nroElementosArrayStrings - 1; j++)
			if (strcmp(arrayStrings[j], arrayStrings[j + 1]) > 0)
			{
				swap(&arrayStrings[j], &arrayStrings[j + 1]);
				cont++;
			}
	}
}

void aplicarInsercionStrings(char** const  arrayStrings, int nroElementosArrayStrings)
{
	for (int i = 0; i < nroElementosArrayStrings - 1; i++)
		for (int j = i + 1; j > 0; j--)
			if (strcmp(arrayStrings[j], arrayStrings[j - 1]) < 0)
				swap(&arrayStrings[j], &arrayStrings[j - 1]);
			else
				break;
}

void aplicarQuickSortStrings(char** const  arrayStrings, int posIzquierda, int posDerecha)
{
	if (posIzquierda >= posDerecha) 
		return;
	int m = posIzquierda, n = posDerecha + 1;
	char* pivote = arrayStrings[posIzquierda];
	while (1)
	{
		do 
		{
			m++;
		} while (strcmp(arrayStrings[m], pivote) < 1 && m < posDerecha);
		do 
		{
			n--;
		} while (strcmp(arrayStrings[n], pivote) > -1 && n > posIzquierda);
		if (m >= n)
			break;
		swap(&arrayStrings[n], &arrayStrings[m]);
	}
	arrayStrings[posIzquierda] = arrayStrings[n];
	arrayStrings[n] = pivote;
	aplicarQuickSortStrings(arrayStrings, posIzquierda, n - 1);
	aplicarQuickSortStrings(arrayStrings, n + 1, posDerecha);
}

void aplicarBusquedaBinariaStrings(char** const  arrayStrings, int nroElementosArrayStrings)
{
	LIMPIAR_CONSOLA
	int primero = 0;
	int ultimo = nroElementosArrayStrings - 1;
	char* valor = (char*) malloc(sizeof(char) * STRLONG_3 + 1);
	pedir_Cadena(valor, STRLONG_1, "Introduce la cadena a buscar");
	for (int medio = (primero + ultimo) / 2; primero <= ultimo; medio = (primero + ultimo) / 2)
	{
		if (strcmp(arrayStrings[medio], valor) < 0)
			primero = medio + 1;
		else if (strcmp(arrayStrings[medio], valor) > 0)
			ultimo = medio - 1;
		else {
			printf_s("\n\tLa cadena: %s, se encuentra en la posicición: %3d\n", valor, medio + 1);
			break;
		}

	}
	if (primero > ultimo)
		printf_s("\n\tLa cadena %s, no se encuentra en el array\n", valor);
	PAUSA
}

void borrarArrayStrings(char*** pArrayStrings, int* pNroElementosArrayStrings) 
{
	for (int i = 0; i < *pNroElementosArrayStrings; i++)
		free((*pArrayStrings)[i]);
	free((*pArrayStrings));
	(*pArrayStrings) = NULL;
	*pNroElementosArrayStrings = 0;
}