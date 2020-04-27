#include"DependenciasComunes.h"
#include"TDAs.h"
#include"AlgoritmosDeOrdenamiento.h"

void menuPrincipal() {
	short userOption = 0;
	while (userOption != 12) {
		LIMPIAR_CONSOLA
		printf_s("\n");
		centrado("*************************");
		centrado("* Menú principal *");
		centrado("*************************");
		printf_s("\n");
		printf_s("\n\t 1.-Algoritmos aplicados sobre arrays");
		printf_s("\n\t 2.-Listas simplemente enlazadas");
		printf_s("\n\t 3.-Listas doblemente enlazadas");
		printf_s("\n\t 4.-Listas circulares");
		printf_s("\n\t 5.-Multilistas");
		printf_s("\n\t 6.-Mallas");
		printf_s("\n\t 7.-Pilas");
		printf_s("\n\t 8.-Colas");
		printf_s("\n\t 12.-Salir");
		switch (userOption = pedir_Short(TERMINAL_OPCION)) {
		case 1: // Algoritmos aplicados sobre arrays
			if (!pedir_Short("Introduce 0 para trabjar con cadenas o 1 para enteros"))
				menuAlgoritmosDeOrdenamientoStrings();
			else
				menuAlgoritmosDeOrdenamientoEnteros();
			break;
		case 2: // Listas simplemente enlazadas
			menuListasSimples();
			break;
		case 3: // Listas doblemente enlazadas
			menuListasDobles();
			break;
		case 4: // Listas circulares
			menuListasCirculares();
			break;
		case 5: // Multilistas
			menuMultilistas();
			break;
		case 6: // Mallas
			break;
		case 7: // Pilas
			menuPilas();
			break;
		case 8: // Colas
			menuColas();
			break;
		case 12:
			mostrarError("¿Está seguro que desea salir?");
			printf("\t12 para salir del programa, cualquier otro para continuar");
			userOption = pedir_Short(TERMINAL_OPCION);
			break;
		default:
			mostrarError(OPCION_NO_VALIDA);
			PAUSA;
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, ""); // Esto nos permite imprimir cosas con ascentos
	menuPrincipal();
}

