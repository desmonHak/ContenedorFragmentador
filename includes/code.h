#ifndef __CODE_H_
#define __CODE_H_

#include "type_data_c.h"
#include "other.h"

#define MAX_POINT (ui16)0xffff // 65536

#define MAX_NAME_BYTES (ui32)16          // cantidad maxima de bytes como nombre de archivos
#define VERSION (db *)"\x42\x48\x00\x01" // "BH10" = Black Hat 1.0
#define EXTENSION (db *)".bh"

typedef struct sector
{
    _uint16_t id_file;       // id del archivo(maximo 65536)
    _uint16_t start_sector;  // direcion de memroia del sector(maximo 65536)
    _uint16_t theend_sector; // final del sector(Maximo 65536)
} sector;

typedef struct indice
{
    ui8 name_file[MAX_NAME_BYTES]; // nombre del archivo inicial(maximo 16Bytes)
    _uint16_t id_file;             // id del archivo(maximo 65536)
    _uint16_t n_sectores;          // numero de sectores del indice(maximo 65536)
    sector **sectores;              // sectores que contiene este indice
} indice;

typedef struct MTF
{                           // Master Table File
    _uint16_t n_file;       // numero de archivos contenidos(maximo 65536)
    indice **start_indices;  // indices de inicio
    indice **theend_indices; // indices de final
} MTF;

typedef struct
{
    // uint8_t version[4]; // Version del software
    VarPoint_define(db, version)
        // uint8_t name_file[MAX_NAME_BYTES]; // nombre del archivo de salida(Maximo 16Bytes)
        VarPoint_define(db, name_file)
        // uint8_t *coments; // comentarios opcionales
        VarPoint_define(db, coments)
} OutputFile;

/*
 * MTF almacena el numero de archivos que se contiene
 * en el contenedor(n_file). start_indices contiene
 * los indices de inicio para los archivos, theend_indices.
 * el indice de inicio del archivo 1 y el indice de final es
 * start_indices[0] y theend_indices[0].
 *
 */

OutputFile InitFileOutput(ui8 *coments, _uint32_t size);
void write_MTF(MTF *MasterTableFile, OutputFile *File);
void printOutputFile(OutputFile File);
void printMTF(MTF MasterTableFiles);
void printIndice(indice _indice);
void printSector(sector _sector);

#include "code.c"
#endif