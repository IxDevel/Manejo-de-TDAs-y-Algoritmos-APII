#include "DependenciasComunes.h"
#include "AlgoritmosDeOrdenamiento.h"

void menuAlgoritmosDeOrdenamientoEnteros() 
{
	int* arrayInt = NULL;
	int nroElmentosArrayInt = 0;
	short userOption = 0;
	while (userOption != 12)
	{
		LIMPIAR_CONSOLA
		printf_s("\n");
		centrado("*************************");
		centrado("* Menú algoritmos de ordenamiento sobre enteros*");
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
		case 1: // Crear array de enteros
			crearArrayEnteros(&arrayInt, &nroElmentosArrayInt);
			break;
		//case 2: // crear array de cadenas
		//	break;
		case 2: // Imprimir array de enteros
			imprimirArrayEnteros(arrayInt, nroElmentosArrayInt);
			break;
		//case 4: // Imprimir array de cadenas
		//	break;
		case 3: // Aplicar intercambio en enteros
			aplicarIntercambioEnteros(arrayInt, nroElmentosArrayInt);
			break;
		case 4: // Aplicar selección en enteros
			aplicarSeleccionEnteros(arrayInt, nroElmentosArrayInt);
			break;
		case 5: // Aplicar burbuja en enteros
			aplicarBurbujaEnteros(arrayInt, nroElmentosArrayInt);
			break;
		case 6: // Aplicar baraja en enteros
			aplicarInsercionEnteros(arrayInt, nroElmentosArrayInt);
			break;
		case 7: // Aplicar quick sort en enteros
			aplicarQuickSortEnteros(arrayInt, 0, nroElmentosArrayInt - 1);
			break;
		case 8: // Aplicar búsqueda binaria en enteros
			aplicarIntercambioEnteros(arrayInt, nroElmentosArrayInt);
			// Es muy importante que el array esté ordenado para poder aplicar la búsqueda binaria
			// y debe la busqueda binara estar en un orden en específico, es decir de mayor a menor o de mayor a menor
			aplicarBusquedaBinariaEnteros(arrayInt, nroElmentosArrayInt, pedir_Short("Introduce el valor a buscar"));
			break;
		case 12:
			free(arrayInt);
			break;
		default:
			mostrarError(OPCION_NO_VALIDA);
			PAUSA;
			break;
		}
	}
}

void crearArrayEnteros(int** pArrayInt, int* nroElementosArrayInt)
{
	LIMPIAR_CONSOLA
	free(*pArrayInt);
	*nroElementosArrayInt = pedir_Int("Introduce el número de elementos del array");
	*pArrayInt = (int*) malloc(sizeof(int) * (*nroElementosArrayInt));
	for (int i = 0; i < *nroElementosArrayInt; i++)
	{
		printf_s("\n\tElemento %3d ", i + 1);
		(*pArrayInt)[i] = pedir_Int("Introduce el valor");
	}		
}

void imprimirArrayEnteros(int* const arrayInt, int nroElementosArrayInt)
{
	LIMPIAR_CONSOLA
	printf_s("\n\tArray de enteros: ");
	for (int i = 0; i < nroElementosArrayInt; i++)
		printf_s("[%3d]", arrayInt[i]);
	printf_s("\n");
	PAUSA
}

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void aplicarIntercambioEnteros(int* const arrayInt, int nroElementosArrayInt)
{
	for (int i = 0; i < nroElementosArrayInt; i++)
		for (int j = i + 1; j < nroElementosArrayInt; j++)
			if (arrayInt[j] < arrayInt[i])
				swap(arrayInt + j, arrayInt + i);

}

void aplicarSeleccionEnteros(int* const arrayInt, int nroElementosArrayInt)
{
	int minPos = 0;
	for (int i = 0; i < nroElementosArrayInt; i++)
	{
		minPos = i;
		for (int j = i + 1; j < nroElementosArrayInt; j++)
		{
			if (arrayInt[j] < arrayInt[minPos])
				minPos = j;
		}
		if (minPos != i)
			swap(arrayInt + minPos, arrayInt + i);
	}

}

void aplicarBurbujaEnteros(int* const arrayInt, int nroElementosInt)
{
	int contadorDeIntercambios;
	for (int i = 0; i < nroElementosInt - 1; i++) 
	{
		contadorDeIntercambios = 0;
		for (int j = 0; j < nroElementosInt - 1; j++)
			if (arrayInt[j] > arrayInt[j + 1])
			{
				contadorDeIntercambios++;
				swap(arrayInt + j, arrayInt + j + 1);
			}
		if (contadorDeIntercambios = 0)
			break;
	}

}

void aplicarInsercionEnteros(int* const arrayInt, int nroElementosInt)
{
	for (int i = 0; i < nroElementosInt - 1; i++)
		for (int j = i + 1; j > 0; j--)
			if (arrayInt[j] > arrayInt[j - 1])
				swap(arrayInt + j, arrayInt + j - 1);
			else
				break;
}

void aplicarQuickSortEnteros(int* const arrayInt, int posIzquierda, int posDerecha)
{
	if (posIzquierda >= posDerecha)
		return;
	int m = posIzquierda, n = posDerecha + 1, pivote = arrayInt[posIzquierda];
	while (1)
	{
		do {
			m++;
		} while (arrayInt[m] <= pivote && m < posDerecha);
		do
		{
			n--;
		} while (arrayInt[n] >= pivote && n > posIzquierda);
		if (m >= n)
			break;
		swap(&arrayInt[m], &arrayInt[n]);
	}
	arrayInt[posIzquierda] = arrayInt[n];
	arrayInt[n] = pivote;
	aplicarQuickSortEnteros(arrayInt, posIzquierda, n - 1);
	aplicarQuickSortEnteros(arrayInt, n + 1, posDerecha);
}

void aplicarBusquedaBinariaEnteros(int* const arrayInt, int nroElementosArrayInt, int valor)
{
	LIMPIAR_CONSOLA
	int primero = 0;
	int ultimo = nroElementosArrayInt - 1;
	for (int medio = (primero + ultimo)/2 ; primero <= ultimo; medio = (primero + ultimo)/2)
	{
		if (arrayInt[medio] < valor)
			primero = medio + 1;
		else if (arrayInt[medio] > valor)
			ultimo = medio - 1;
		else {
			printf_s("\n\tEl %3d, se encuentra en la posicición: %3d\n", valor, medio + 1);
			break;
		}
			
	}
	if (primero > ultimo)
		printf_s("\n\tEl %3d, no se encuentra en el array\n", valor);
	PAUSA
}