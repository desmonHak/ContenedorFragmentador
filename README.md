# ContenedorFragmentador
Este programa permite juntar varios archivos en uno unico.

----
## Funcionamiento:

1. Se especifica el directorio(Carpeta) donde se encuentran los archivos  a agrupar. 

2. Una vez se ha situado la carpeta. El programa generar un mapa de la hubicacion de cada archivo. Una vez que se tiene la cantidad de archivo, se guardara en la estructura de datos `MTF`, en el apartado de n_file, el cual es una estructura que almacena un tipo de dato de 16bits sin signo, por lo que, se puede contenet una cantidad de 2**16 archivos. O al menos, es la cantidad que se le puede especificar al programa. Nuestra estructura `MTF` contiene 2 elementos del tipo de estructura `indice` puntero, el primer indice es denominado `start_indices` y es un array dinamico de indices. La segunda estructura se denomina `theend_indices` y al igual que `start_indices`, tambien almacena en nuestro programa los indices de cada archivo mediante un array de indices. 
Nuestro programa genera para cada archivo, dos elementos indices, uno de inicio y otro de final como copia de seguridad, por si se daña el indice de inicio o se ve modificado. Para nuestro programa, los elementos `start_indices[0]` y `theend_indices[0]` hacen referencia al indice de inicio y al indice final del archivo con `ID 0`.

----

- #### Estructura MTF(Master Table File) code y tamaño:

```C
typedef struct MTF
{                           // Master Table File
    _uint16_t n_file;       // numero de archivos contenidos(maximo 65536)
    indice **start_indices;  // indices de inicio
    indice **theend_indices; // indices de final
} MTF;
/*
 * MTF almacena el numero de archivos que se contiene
 * en el contenedor(n_file). start_indices contiene
 * los indices de inicio para los archivos, theend_indices.
 * el indice de inicio del archivo 1 y el indice de final es
 * start_indices[0] y theend_indices[0].
 */
```
|nombre             | Tamaño     |
|:-----------------:|:----------:|
|n_file             |`16 bit`    |
|start_indices      |`indefinido`|
|theend_indices     |`indefinido`|

|  Tamaño total de la estructura          |
|:---------------------------------------:|
|` 16 + ? + ? = minimo 16 Bits = 2Bytes ` |





----

### Estructura indice:

La estructura indice que se contiene en la estructura `MTF`, contiene el nombre del archivo en el campo `name_file`el cual es del tipo `unsigned char`(8bit) y es un array que puede contener nombres de hasta 16 caracteres. Contiene tambien el ID(identificador) del archivo en el campo denominado `id_file`el cual es una estructura de datos que almacena un valor de `16bits`=`2Bytes` que puede ir de `(0-2**16)`. Tambien tenemos un array de punteros dinamicos de sectores, este campo en nuestra estructura `indice` se llama `sectores`.

----

- #### Estructura indice code y tamaño:

```C
typedef struct indice
{
    ui8 name_file[MAX_NAME_BYTES]; 
    /* 
     * nombre del archivo inicial(maximo 16Bytes)
     * MAX_NAME_BYTES = 16
    */
    _uint16_t id_file;    // id del archivo(maximo 65536)
    _uint16_t n_sectores; // numero de sectores del indice(maximo 65536)
    sector **sectores;    // sectores que contiene este indice
} indice;

```
|nombre             | Tamaño                           |
|:-----------------:|:--------------------------------:|
|name_file          |`8 bit * 16 =  128bits = 16Bytes` |
|id_file            |`16 bits = 2Bytes`                |
|theend_indices     |`16 bits = 2Bytes`                |
|sector             |`indefinido`                      |

|  Tamaño total de la estructura                  |
|:-----------------------------------------------:|
|` 128 + 16 + 16 + ? = minimo 160Bits = 20Bytes ` |

----




### Estructura sector:

La estructura sector almacena el ID al que pertenece el mismo en su campo `id_file` que es una estructura de `16bits`. Contiene el inicio del sector en su campo `start_sector` y el final del mismo en su campo `theend_sector`, ambos son estructuras de `16bits`. El campo `theend_sector` contiene unvalor de `16bits` el cual es el resultado de sumar el `start_sector`(inicio del sector) mas el contenido del sector.
`start_sector = 16` y el contenido del sector son `16bytes`.
`theend_sector = start_sector + 16 = 32`.


----

- #### Estructura sector code y tamaño:
```C
typedef struct sector
{
    _uint16_t id_file;       // id del archivo(maximo 65536)
    _uint16_t start_sector;  // direcion de memroia del sector(maximo 65536)
    _uint16_t theend_sector; // final del sector(Maximo 65536)
} sector;
```
|nombre             | Tamaño                           |
|:-----------------:|:--------------------------------:|
|id_file            |`16 bits = 2Bytes`                |
|start_sector       |`16 bits = 2Bytes`                |
|theend_sector      |`16 bits = 2Bytes`                |

|  Tamaño total de la estructura    |
|:---------------------------------:|
|` 16 + 16 + 16 = 48Bits = 6Bytes ` |

----

# code.h y code.c

Estas estructuras mencionadas anteriormente se encuentran definidas en los archivos `code.h` y `code.c`. Tambien situamos definido lo siguiente:

```C
#define MAX_POINT (ui16)0xffff // 65536

#define MAX_NAME_BYTES (ui32)16 // cantidad maxima de bytes como nombre de archivos
#define VERSION (db *)"\x42\x48\x00\x01" // "BH10" = Black Hat 1.0
#define EXTENSION (db *)".bh"
```

- Donde se define la macro `MAX_POINT` como un valor del tipo `unsigned short = uint16_t` de valor `0xffff`.

- Se define la macro `MAX_NAME_BYTES` el cual es un valor del tipo `unsigned int = uint32_t` que almacena el valor maximo para los nombres de archivo + extension que es de `16Bytes`.

- Se define en la macro `VERSION` un conjunto de valores del tipo `unsigned char = uint8_t` el cual se escribe inicialmente en el archivo contenedor e identifica este tipo de archivos, tmb contiene la version del mismo.

- Se define en la macro `EXTENSION` un conjunto de valores del tipo `unsigned char = uint8_t` el cual es la extension de los archivos contenedores.

----
Como funciones encontramos las siguientes:
```C
OutputFile InitFileOutput(ui8 *coments, _uint32_t size);
void write_MTF(MTF *MasterTableFile, OutputFile *File);
void printOutputFile(OutputFile File);
void printMTF(MTF MasterTableFiles);
void printIndice(indice _indice);
void printSector(sector _sector);
```