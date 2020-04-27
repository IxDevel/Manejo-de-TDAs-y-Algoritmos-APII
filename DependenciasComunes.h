#pragma once
#include <stdio.h> // Librería salida básica de C
#include <stdlib.h> // Librería estandar básica de C
#include <string.h> // Librería para el manejo de strings en C
#include <windows.h> // Librería de Windows en C -> Colores y cosas por el estilo
#include <conio.h> // Librería para la consola (Console input output)
#include <limits.h> // Librería para máxima y mínima longitud de enteros
#include <float.h>  // Librería para máxima y mínima longitud de reales
#include <wchar.h> // Librería Fancy 1
#include <locale.h> // Librería Fancy 2

/*################################################################################################################################
									Definiciones de Pre-Prosesador
#################################################################################################################################*/

#define TECLADO stdin // Entrada (por defecto -> Teclado)
#define ERRORES stderr // Salida de Errores (por defecto -> Monitor)
#define TERMINAL_OPCION "Opcion:>>> " // Terminal (Decorativo)
#define PANTALLA stdout // Salida (por defecto -> Monitor)
#define COLOR_TEXTO_POR_DEFECTO 7 // Texto por defecto
#define COLOR_ELEMENTOS_MENU 95 // Color de los elementos del menu
#define COLOR_DE_LOS_ERRORES 12 // Color de los errores
#define COLOR_DE_LOS_CUMPLIDOS 10 // Color de las tareas cumplidas
#define COPYRIGHT "Todos los derechos reservados" // Para la joda :)
#define STRLONG_1 25 // Longitud minima de una cadena
#define STRLONG_2 50 // Longitud media de una cadena
#define STRLONG_3 100 // Longitud maxima de una cadena
#define ENTER 13 // Tecla enter del teclado
#define ESCAPE 27 // Tecla de escape del teclado

// Cadenas de errores
#define OPCION_NO_VALIDA "Opción no válida" // Mensaje de error
#define COD_NO_VALIDO "El código introducido no es válido"
#define TEL_NO_VALIDO "El teléfono inválido"
#define EMAIL_INVALIDO "El formato de correo inválido"

#define SOLO_LETRAS "Solo puede contener letras y espacios"
#define SOLO_LETRAS_NUMEROS "Solo puede contener letras, numeros y espcios"
#define TODO_MENOS_ESPECIALES "No puede conter caracteres especiales"

// Semántico
#define PAUSA system("pause");
#define LIMPIAR_CONSOLA system("cls");
#define RETROCEDER "\n\n\t Presione ESC para retroceder\n\n"

/*################################################################################################################################
												Datos enumerados
#################################################################################################################################*/

// Enumerados Opcionales
enum eFormatosImp { Completo = 0, Basico, Especifico, Repetitivo }; // Para mostrar los TDAs
enum eTipoNumero { Entero = 1, Decimal };

/*#############################################################################################################
									Prototipos de Funciones de Manejo de Datos
#############################################################################################################*/

// ####### Manejo de numeros #########
int es_Numero(const char cadena[], eTipoNumero tipo); // Verifica si la cadena contiene solo números
short int pedir_Boolean(const char* const pregunta); // Solicita un entero booleano
short int pedir_Short(const char* const pregunta); // Solicita un entero corto
int pedir_Int(const char* const pregunta); // Solicita un entero
long int pedir_Long(const char* const pregunta); // Solicita un entero largo
float pedir_Float(const char* const pregunta); // Solicita un real de presicion simple
double pedir_Double(const char* const pregunta); // Solicita un real de presicion doble

// ####### Manejo de numeros #########
void pedir_Cadena(char* cad, int longitud_maxima_de_la_cadena, const char* const msg);  // Solicita una cadena usuario

// ####### Manejo mensajes -> Impresión #########
void mostrarError(const char* const msg); // Imprime errores
void mostrarCumplido(const char* const msg); // Imprime trabajos cumplidos
void centrado(const char str[STRLONG_2]); // Centra un título en consola