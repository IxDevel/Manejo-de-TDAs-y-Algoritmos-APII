#include"DependenciasComunes.h"

/*#############################################################################################################
									Variables Globales
#############################################################################################################*/

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Manejador del color de la consola -> Colorsitos...

/*#################################################################################################################################
									Definiciones de funciones para el manejo de datos
#################################################################################################################################*/

int es_Numero(const char cadena[], eTipoNumero tipo)  // Verifica si la cadena contiene solo números
{
	int n = 0;
	short cantidad_de_puntos = 0;
	for (unsigned int i = (cadena[0] == '-') ? 1 : 0; i < strlen(cadena); i++)
	{
		n = (int)cadena[i];
		if (tipo == Entero)
		{
			if (n < 48 || n > 57)
				return 0;
		}
		else
		{
			if (cadena[i] == '.')
				cantidad_de_puntos++;
			else if (n < 48 || n > 57)
				return 0;
			if (cantidad_de_puntos > 1)
				return 0;
		}
	}
	if (cadena[0] != '\n')
		return 1;
	else
		return 0;
}

short int pedir_Boolean(const char* const pregunta) // Solicita un entero booleano
{
	char cadena[STRLONG_2];
	do
	{
		pedir_Cadena(cadena, STRLONG_2, pregunta);
	} while (!es_Numero(cadena, Entero) && cadena[1] != '\0');
	return (cadena[0] == '0') ? 0 : 1;
};

short int pedir_Short(const char* const pregunta) // Solicita un entero corto
{
	int s = 0;
	char cadena[STRLONG_2];
	do
	{
		pedir_Cadena(cadena, STRLONG_2, pregunta);
		s = atoi(cadena);
	} while ((strlen(cadena) > 6) || (!es_Numero(cadena, Entero)) || (s > SHRT_MAX) || (s < SHRT_MIN));
	return (short)s;
};

int pedir_Int(const char* const pregunta) // Solicita un entero
{
	long int s = 0;
	char cadena[STRLONG_2];
	do
	{
		pedir_Cadena(cadena, STRLONG_2, pregunta);
		s = atoi(cadena);
	} while ((strlen(cadena) > 10) || (!es_Numero(cadena, Entero)) || (s > INT_MAX) || (s < INT_MIN));
	return (int)s;
}

long int pedir_Long(const char* const pregunta) // Solicita un entero largo
{
	long int s = 0;
	char cadena[STRLONG_2];
	do
	{
		pedir_Cadena(cadena, STRLONG_2, pregunta);
		s = atoi(cadena);
	} while ((strlen(cadena) > 19) || (!es_Numero(cadena, Entero)) || (s > LONG_MAX) || (s < LONG_MIN));
	return (long int)s;
};

float pedir_Float(const char* const pregunta) // Solicita un real de presicion simple
{
	char cadena[STRLONG_2];
	double s = 0;
	do
	{
		pedir_Cadena(cadena, STRLONG_2, pregunta);
		s = atof(cadena);
	} while ((strlen(cadena) > 38) || (!es_Numero(cadena, Decimal)) || (s > FLT_MAX) || (s < -FLT_MAX));
	return (float)s;
};

double pedir_Double(const char* const pregunta) // Solicita un real de presicion doble
{
	char cadena[STRLONG_2];
	double s = 0;
	do
	{
		pedir_Cadena(cadena, STRLONG_2, pregunta);
		s = (double)atof(cadena);
	} while ((strlen(cadena) > 38) || (!es_Numero(cadena, Decimal)) || (s > FLT_MAX) || (s < -FLT_MAX));
	return (double)s;
};

int verificar_Caracteres_Invalidos(char* cad)
{
	for (short int i = 0; i < strlen(cad); i++)
		if (cad[i] == ';')
			return 1;
	return 0;
}

void pedir_Cadena(char* cad, int longitud_maxima_de_la_cadena, const char* const msg)  // Solicita una cadena al usuario
{
	do
	{
		if (msg)
			printf_s("\n\t %s: ", msg);
		fgets(cad, longitud_maxima_de_la_cadena, TECLADO);
		cad[strlen(cad) - 1] = '\0';
		fflush(TECLADO);                                    //seria lindo verificar para los nombres que solo contengan letras -> Listo
		if (cad[0] == '\0' || verificar_Caracteres_Invalidos(cad))
			mostrarError(TODO_MENOS_ESPECIALES);
		else
			break;
	} while (1);
	_strupr_s(cad, STRLONG_2);
}

int pedir_Codigo(const char* const pregunta)
{
	int codigo = 0;
	do
	{
		codigo = pedir_Int(pregunta);
		if (codigo > 0)
			break;
		else
			mostrarError(COD_NO_VALIDO);
	} while (1);
	return codigo;
}

int verificar_Solo_Letras(char* cad) // NUEVO -> Verifica si el usuario solo inserta letras -> Ideal para nombres
{
	for (int i = 0; i < strlen(cad); i++)
		if (cad[i] < 'A' || cad[i] > 'Z')
			if (cad[i] != ' ')
				return 0;
	if (cad[0] == ' ')
		return 0;
	return 1;
}

void pedir_Solo_Letras(char* cad, int longitud_maxima_de_la_cadena, const char* const msg) // NUEVO -> Funcion que pide solo letras
{
	do
	{
		pedir_Cadena(cad, STRLONG_2, msg);
		if (verificar_Solo_Letras(cad))
			break;
		else
			mostrarError(SOLO_LETRAS);
	} while (1);
}

int verificar_Solo_Numeros_Letras_Espcios_Puntos_Y_Comas(char* cad) // NUEVO -> Verifica que sea una cadena de texto normal
{
	for (int i = 0; i < strlen(cad); i++)
		if (cad[i] < 'A' || cad[i] > 'Z')
			if (cad[i] < '0' || cad[i] > '9')
				if (cad[i] != ' ' && cad[i] != '.' && cad[i] != ',')
					return 0;
	if (cad[0] == ' ')
		return 0;
	return 1;
}

void pedir_Solo_Numeros_Letras_Espcios_Puntos_Y_Comas(char* cad, int longitud_maxima_de_la_cadena, const char* const msg) // NUEVO -> Pide esos requerimientos a la entrada
{
	do
	{
		pedir_Cadena(cad, STRLONG_2, msg);
		if (verificar_Solo_Numeros_Letras_Espcios_Puntos_Y_Comas(cad))
			break;
		else
			mostrarError(SOLO_LETRAS_NUMEROS);
	} while (1);
}

int verificar_Correo(char* cad) // NUEVO -> Verifica un formato de correo **@*.*
{
	short int puntos = 0;
	short int arrobas = 0;
	short int pisos = 0;
	short int numeros = 0;
	for (int i = 0; i < strlen(cad); i++)
	{
		if (cad[i] == '@')
			arrobas += 1;
		else if (cad[i] == '.')
		{
			puntos += 1;
			if (cad[i - 1] == '@' || cad[i + 1] == '\0')
				return 0;
		}
		else if (cad[i] == '_')
		{
			pisos += 1;
			if (arrobas || cad[i + 1] == '@')
				return 0;
		}
		else if (cad[i] >= '0' && cad[i] <= '9')
			numeros += 1;
		else if (cad[i] < 'A' || cad[i] > 'Z')
			return 0;
	}
	//printf("%i %i %i", arrobas, puntos, pisos); -> De control nada más
	if (arrobas == 0 || puntos == 0 || pisos == strlen(cad) - 2 || numeros == strlen(cad) - 2)
		return 0;
	else
		return 1;
}

void pedir_Correo(char* cad, int longitud_maxima_de_la_cadena, const char* const msg) // NUEVO -> Función que pide el correo
{
	do
	{
		pedir_Cadena(cad, STRLONG_2, msg);
		if (verificar_Correo(cad))
			break;
		else
			mostrarError(EMAIL_INVALIDO);
	} while (1);
}

int verificar_Telefono(char* codigo_area, char* numero_telefono) // NUEVO -> Verifica si el telefono introducido es valido
{
	char cAreas[][4] = { "212", "412", "416", "424", "426" }; // codigos de area
	int p = 0;
	if (es_Numero(codigo_area, Entero) && strlen(codigo_area) == 3)
	{
		for (int i = 0; i < 5; i++)
			if (strcmp(codigo_area, cAreas[i]) == 0)
				p = 1;
		if (!p)
			return 0;
	}
	else
		return 0;
	if (es_Numero(numero_telefono, Entero) && strlen(numero_telefono) == 7) // Nuevo
	{
		if (numero_telefono[0] == '0' && strcmp(codigo_area, cAreas[0]) == 0)
			return 0;
	}
	else
		return 0;
	return 1;
}

void pedir_Telefono(char* cad, int longitud_maxima_de_la_cadena, const char* const msg) // NUEVO -> Función que pide el telefono
{
	char codigo_area[STRLONG_2];
	char numero_telefono[STRLONG_2];
	char mas[] = "-";
	do
	{
		pedir_Cadena(codigo_area, STRLONG_2, "Introduce el código de area (3 digitos)");
		pedir_Cadena(numero_telefono, STRLONG_2, "Introduce el numero telefónico");
		if (verificar_Telefono(codigo_area, numero_telefono))
			break;
		else
			mostrarError(TEL_NO_VALIDO);
	} while (1);
	strcat_s(codigo_area, mas);
	strcat_s(codigo_area, numero_telefono);
	strcpy_s(cad, STRLONG_2 - 1, codigo_area);
}

void mostrarError(const char* const msg) // Imprime errores
{
	SetConsoleTextAttribute(hConsole, COLOR_DE_LOS_ERRORES);
	printf_s("\n\n\t%s\n\n", msg);
	SetConsoleTextAttribute(hConsole, COLOR_TEXTO_POR_DEFECTO);
}

void mostrarCumplido(const char* const msg) // Imprime trabajos cumplidos
{
	SetConsoleTextAttribute(hConsole, COLOR_DE_LOS_CUMPLIDOS);
	printf_s("\n\n\t%s\n\n", msg);
	SetConsoleTextAttribute(hConsole, COLOR_TEXTO_POR_DEFECTO);
}
void mostrar_Elemento_Del_Menu(int n, const char* const msg, int c)  // Imprime los elementos del menu
{
	printf_s("\n\t ");
	SetConsoleTextAttribute(hConsole, (WORD)c); // PONLO MORADO
	if (n >= 0)
		printf_s("<%i>>> %s \n", n, msg);
	else
		printf_s("%s \n", msg);
	SetConsoleTextAttribute(hConsole, COLOR_TEXTO_POR_DEFECTO);
}

void centrado(const char str[STRLONG_2]) // Centra un titulo en consola
{
	int pad = ((strnlen(str, STRLONG_2)) >= 80 ? 0 : (80 - strnlen(str, STRLONG_2))) / 2;
	printf("%*.*s%s\n", pad, pad, " ", str);
}
