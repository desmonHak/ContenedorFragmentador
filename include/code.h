#ifndef __CODE_H_
#define __CODE_H_

#include <stdlib.h>

#include "type_data_c.h"
#include "other.h"

#define MAX_POINT (ui16)0xffff // 65536

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__NT__)
#include <windows.h>
#define MAX_NAME_BYTES (ui32)MAX_PATH
#elif defined(__linux__)
#define MAX_NAME_BYTES (ui32)255          // cantidad maxima de bytes como nombre de archivos
#endif

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

#define INIT_MTF(MasterTableFiles) \
    MTF MasterTableFiles = (MTF){ \
        .n_file         = UI16(0x0001), \
        .start_indices  = NULL, \
        .theend_indices = NULL  \
    }; 

#define INIT_SECTOR(my_sector) \
    sector *my_sector = (sector *)malloc(sizeof(sector) * 1); \
            my_sector->id_file       = UI16(0x0000); \
            my_sector->start_sector  = UI16(0x0000); \
            my_sector->theend_sector = UI16(0x0000); 

#define INIT_INDICE(my_indice) \
    indice *my_indice = (indice *)malloc(sizeof(indice) * 1); \
            my_indice->id_file    = UI16(0x0000); \
            my_indice->n_sectores = UI16(0x0000); \
            my_indice->sectores   = (sector **)malloc(sizeof(sector*) * 1); 


/*
 * MTF almacena el numero de archivos que se contiene
 * en el contenedor(n_file). start_indices contiene
 * los indices de inicio para los archivos, theend_indices.
 * el indice de inicio del archivo 1 y el indice de final es
 * start_indices[0] y theend_indices[0].
 */

OutputFile InitFileOutput(ui8 *coments, _uint32_t size);
void write_MTF(MTF MasterTableFile, OutputFile File);
void printOutputFile(OutputFile File);
void printMTF(MTF MasterTableFiles);
void printIndice(indice *_indice);
void printSector(sector *_sector);

#include "code.c"
#endif