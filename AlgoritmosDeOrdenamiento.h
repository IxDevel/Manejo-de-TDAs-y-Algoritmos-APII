#pragma once

void menuAlgoritmosDeOrdenamientoEnteros();
void crearArrayEnteros(int** pArrayInt, int* pNroElmentosArrayInt);
void imprimirArrayEnteros(int* const  arrayInt, int NroElementosArrayInt);
void aplicarIntercambioEnteros(int* const arrayInt, int nroElementosArrayInt);
void aplicarSeleccionEnteros(int* const arrayInt, int nroElementosArrayInt);
void aplicarBurbujaEnteros(int* const arrayInt, int nroElementosArrayInt);
void aplicarInsercionEnteros(int* const arrayInt, int nroElementosArrayInt);
void aplicarQuickSortEnteros(int* const arrayInt, int posIzquierda, int posDerecha);
void aplicarBusquedaBinariaEnteros(int* const  arrayInt, int nroElementosArrayInt, int valor);

void menuAlgoritmosDeOrdenamientoStrings();
void crearArrayStrings(char*** pArrayStrings, int* pNroElementosArrayStrings);
void imprimirArrayStrings(char** const  arrayStrings, int nroElementosArrayStrings);
void aplicarIntercambioStrings(char** const  arrayStrings, int nroElementosArrayStrings);
void aplicarSeleccionStrings(char** const  arrayStrings, int nroElementosArrayStrings);
void aplicarBurbujaStrings(char** const  arrayStrings, int nroElementosArrayStrings);
void aplicarInsercionStrings(char** const  arrayStrings, int nroElementosArrayStrings);
void aplicarQuickSortStrings(char** const  arrayStrings, int posIzquierda, int posDerecha);
void aplicarBusquedaBinariaStrings(char** const  arrayStrings, int nroElementosArrayStrings);
