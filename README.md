# Manejo-de-TDAs-y-Algoritmos-APII
 En el presente repositorio encontraran codigo e información sobre los TDAs y algoritmos vistos en algoritmos y programación 2.

 ## Herramientas necesarias

 Este código fue diseñado utilizando Visual Studio Community 2019 y por ende utiliza directivas y ciertas funciones propias del compilador Visual C++. Si utilizan Code::Blocks, DevC u otro, deben ajustar ciertas ciertas funciones de entrada y salida.

 Por ejemplo:
 Los printf_s deben cambiarlos por printf.

 En las versione anteriores se permitía el uso de las funciones sin el "_s", pero por motivos de seguridad ya no se permite.

 Si utilizan versiones anteriores de Visual Studio es muy probable que no tengan problemas con el código. 

 ## Estructura del código

 El código se encuentra estructurado en archivos de encabezado ".h" y de implementación ".cpp"

### Algoritmos de Ordenamiento (En revisón)

En esta sección encontrarán el código relacinado con los algortimos de ordenamiento sobre enteros:

- Intercambio
- Selección
- Burbuja
- Inserción o baraja
- Quicksort (con pivote a la izquierda)
- Búsqueda binaria

Adicionalmente se incluyen estos para cadenas de caracteres o strings.

### Listas

Las listas representan a la base de todas las TDAs, para efectos prácticos a cada estructura se le dá un nombre en específico, como pila, cola, doble, circular... Una simple inspección les revelará que es la misma lista con un elemento más o menos.

De estas se implementaron:

- Listas simplemente enlazadas
- Listas doblemente enlazadas
- Listas simplemente enlazadas ciculares
- Listas doblemente enlazadas circulares
- Multilistas
- Mallas (Sin incluir)

### Pilas y Colas

Estas estructuras, si bien no dejan de ser listas en el fondo, "obligan" al usuario a usar primitivas para trabajarlas. Dentro de estas tenemos:

- Pilas 
- Colas

### Dependencias comunes.h

En esta sección les he preparado unas funciones, que pueden utilizar, para elaborar sus proyectos. La idea, sobre todo con C, es emplear funciones para controlar la entrada y salida de datos. Dentro de las ventajas de esto tenemos:

- Validar que una entrada sea de un tipo de datos.
- Validar formatos o estructuras entre los datos.
- Evitar problemas de desbordamientos.
- Controlar el lenguaje y la codificación de los caracteres.
- Utilizar constantes y macros.

## Recomendaciones generales

- Les aconsejo que le hechen un vistazo a la sección dependencias comunes.
- Lean el código para manejar las TDAs y realizen los ejercicios recomendados por el profesor.
- Escriban a mano las rutinas de las TDAs y algoritmos remplazando los ciclos for por whiles.

## Punteros

-  ¿Que son los punteros?

Los punteros son variables enteras que almacenan la dirección de memoria de las estructuras. Estos se encuentran generalmente configuradas para un tipo de dato (entero, real, pila, char...)

En la práctica existen 4 tipos de punteros básicos

- Punteros a datos -> int *p;
- Punteros a datos constantes -> int const *p;
- Punteros constantes a datos -> const int *p;
- Punteros constantes a datos constantes -> const int const *p;

También auque no lo crean, existen punteros dobles , triples, cuádruples y más. Para la mayoría de los casos usarás punteros dobles y simples.

- ¿Para que me sirve lo anterior?

Para el enfoque del curso ustedes necesitarán saber lo siguiente:

- Los "punteros a datos" nos sirven para poder modificar los valores dentro de las funciones.

- Los arrays, como int array[], en el fondo son "punteros constantes a datos" y esta es la manera en la cual pueden ser pasados a las funciones, cabe destacar que no necesitan utilizar el operador "&" ya que en el fondo son punteros.

- Cuando se pasa por valor a un puntero se está pasando la dirección de memoria del dato al cual apuntan.

- Cuando dentro de una función necesitas modificar a donde apunta un puntero dentro de una función, caso de las pilas, colas y la inserción de elementos, necesitas utilizar un puntero doble.

- Las cadenas que uno obtiene de scanf son "punteros a datos constantes" y por este motivo se les conoce como cadenas literales. Si desean modificar una cadena deben crear un array de n + 1 letras para almacenarla usando strcpy()

- Cuando se usan punteros, aún si solo se usan para leer datos, se debe tener en consideración que se deben limpiar para evitar datos basura producto de la reasignación de los mismos.

- De lo anterior se deduce que C no implementa un recolector de basura y esto es muy importante.

## Malloc(), free(), new y delete

En C se emplean los siguientes métodos para el manejo de memoria dinamicamente:

- Malloc(), calloc(), alloc()...

puntero al dato = (cast al tipo de dato) malloc(sizeof(tipo de dato) * numero_de_datos);

Crearemos un array:
```shell
int *array = (int *) malloc(sizeof(int)*10);
```

Para liberar la memoria utilizamos la siguiente instrucción
```shell
free(array);
array = NULL;
```

En el curso se utilizará la forma en que se hace en C++, es decir utilizarán "new" y "delete" en vez de "malloc()" y "free()". Es importante no mezclar ambos tipos manejo de memoria si se entan trabajando objetos o estructuras complejas.

 ## Licencia

 La licencia de es repositorio es MIT, la idea es que aprendan y puedan utilizar el código fuente para lo que requieran, siempre y cuando respeten los términos de la misma.
