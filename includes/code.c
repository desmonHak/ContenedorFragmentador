#ifndef __CODE_C_
#define __CODE_C_

#include <stdlib.h>

#include "type_data_c.h"
#include "code.h"
#include "other.h"

void write_MTF(MTF *MasterTableFile, OutputFile *File)
{
    /*
     * Escribimos el MTF en forma de archivo
     */
}



OutputFile InitFileOutput(ui8 *coments, _uint32_t size)
{
    OutputFile File = {
        .version = {
            0,
            {4} // longitud maxima de 4 para el campo de version
        },
        .name_file = {
            malloc(MAX_NAME_BYTES), {MAX_NAME_BYTES} // maximo MAX_NAME_BYTES bytes
        },
        .coments = {0, size},
    };

    File.version.pointer = (db *)malloc(File.version.size._uint32_t);
    copyStrUint8Pointer(VERSION, File.version.pointer, (_uint32_t){0}, File.version.size);

    File.coments.pointer = (db *)malloc(File.coments.size._uint32_t);
    copyStrUint8Pointer(coments, File.coments.pointer, (_uint32_t){0}, File.coments.size);

    return File;
}






void printSector(sector _sector)
{
    ui16 v = _sector.id_file._uint16_t;
    printf("ID archivo del sector: %d\n", v);
    printUint16Hex(&v, (_uint32_t){0x1});
    puts(" ");

    v = _sector.start_sector._uint16_t;
    printf("Inicio y final del sector: (%d-%d) = (", v, _sector.theend_sector._uint16_t);
    printUint16Hex(&v, (_uint32_t){0x1});

    v = _sector.theend_sector._uint16_t;
    putchar('-');
    printUint16Hex(&v, (_uint32_t){0x1});
    puts(") ");
}

void printIndice(indice _indice)
{
    printf("[*] Mombre del archivo: '%s'\n", _indice.name_file);
    printUint8Hex(_indice.name_file, (_uint32_t){MAX_NAME_BYTES});
    puts(" ");

    ui16 v = _indice.id_file._uint16_t;
    printf("[@] Valor ID del Indice: %d\n", v);
    printUint16Hex(&v, (_uint32_t){0x1});
    puts("");
    v = _indice.n_sectores._uint16_t;
    printf("[@] Numero de sectores del Indice: %d\n", v);
    printUint16Hex(&v, (_uint32_t){0x1});
    puts("");

    for (ui16 i = 0; i < v; i++)
    {
        printSector(_indice.sectores[i]);
    }
}

void printMTF(MTF MasterTableFiles)
{
    ui16 v = MasterTableFiles.n_file._uint16_t;
    printf("[+] Numero archivos contenidos: ");
    printUint16Hex(&v, (_uint32_t){0x1});
    puts("\n");

    for (ui16 i = 0; i < MasterTableFiles.n_file._uint16_t; i++)
    {
        printf("[+] Valores del indice start del MTF: \n");
        printIndice(MasterTableFiles.start_indices[i]);
        printf("[+] Valores del indice the end del MTF: \n");
        printIndice(MasterTableFiles.theend_indices[i]);
    }
}

void printOutputFile(OutputFile File)
{
    printf("[!] Comentario: '%s' \t\tsize: %d\n", File.coments.pointer, File.coments.size._uint32_t);
    printUint8Hex(File.coments.pointer, File.coments.size);
    puts(" ");

    printf("[!] Nombre del archivo final: '%s' \tsize: %d\n", File.name_file.pointer, File.name_file.size._uint32_t);
    printUint8Hex(File.name_file.pointer, File.name_file.size);
    puts(" ");

    printf("[!] Version del archivo: '%s' \t\tsize: %d\n", File.version.pointer, File.version.size._uint32_t);
    printUint8Hex(File.version.pointer, File.version.size);
    puts(" ");
}

#endif