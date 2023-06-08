#ifndef __CODE_C_
#define __CODE_C_

#include "code.h"
#include "other.h"

void set_MTF(MTF *MasterTableFile, _uint16_t n_file, indice **start_indices, indice **theend_indices){

}

void write_MTF(MTF MasterTableFile, OutputFile File)
{
    /*
    * Esta funcion escribe el contenedor final y recibe
    * como parametros una estrutura del tipo MTF llamada
    * MasterTableFile donde se definen una colecion de
    * sectores e indices. Como siguiente parametro recibe
    * una estructura del tipo OutputFile llamada File
    * donde se almacena informacion relacionada al 
    * archivo de salida (archivo contenedor).
    */
}

OutputFile InitFileOutput(ui8 *coments, _uint32_t size)
{
    /*
     * Esta funcion devuelve una estructura del tipo
     * OutputFile que a sido previamente difinida y
     * que contiene punteros de memoria dinamica para arrays.
     *
     * - coments es un conjunto de valores de tipo
     * uint8_t donde se puede almacenar informacion
     * extra como comentarios y etc.
     *
     * - size es una estructura de tipo _uint32_t el cual
     * almacena un valor de tipo uint32_t que especifica
     * el tamaño del parametro coments, si el tamaño se
     * size es menor que el tamaño real de coments,
     * solo se almacenara la cantidad especificada por size.
     */
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

void printSector(sector *_sector)
{
    /*
    * Esta funcion recibe como parametro una estructura de
    * tipo sector llamado _sector, para la impresion de sus
    * valores.
    * 
    * Imprime el ID del archivo al que pertenece este sector.
    * el inicio de los datos alojados de este sector en el
    * archivo contenedor y el final.
    */
    ui16 v = _sector->id_file._uint16_t;
    printf("ID archivo del sector: %d\n", v);
    printUint16Hex(&v, (_uint32_t){0x1});
    puts(" ");

    v = _sector->start_sector._uint16_t;
    printf("Inicio y final del sector: (%d-%d) = (", v, _sector->theend_sector._uint16_t);
    printUint16Hex(&v, (_uint32_t){0x1});

    v = _sector->theend_sector._uint16_t;
    putchar('-');
    printUint16Hex(&v, (_uint32_t){0x1});
    puts(") ");
}

void printIndice(indice *_indice)
{
    /*
    * Esta funcion recibe como parametro una estructura del
    * tipo indice llamada _indice para la impresion de
    * sus valores. 
    * 
    * Imprime el valor ID del indice y el numero de sectores
    * que almacenado, ademas imprime los valores de cada
    * sector almacenado en este indice mediante la funcion
    * printSector().
    */
    printf("[*] Mombre del archivo: '%s'\n", _indice->name_file);
    printUint8Hex(_indice->name_file, (_uint32_t){MAX_NAME_BYTES});
    puts(" ");

    ui16 v = _indice->id_file._uint16_t;
    printf("[@] Valor ID del Indice: %d\n", v);
    printUint16Hex(&v, (_uint32_t){0x1});
    puts("");
    v = _indice->n_sectores._uint16_t;
    printf("[@] Numero de sectores del Indice: %d\n", v);
    printUint16Hex(&v, (_uint32_t){0x1});
    puts("");

    for (ui16 i = 0; i < v; i++)
    {
        printSector(_indice->sectores[i]);
    }
}

void printMTF(MTF MasterTableFiles)
{
    /*
    * Esta funcion recibe como parametro una estructura del 
    * tipo MTF llamada MasterTableFiles para imprinmir sus
    * valores.
    * 
    * Imprime la cantidad de archivos que contiene el 
    * archivo contenedor. He imprime haciendo uso de
    * la funcion printIndice() los indice de inicio y final
    * de cada archivo contenido en el archivo contenedor.
    */
//    ui16 v = MasterTableFiles.n_file._uint16_t;
    printf("[+] Numero archivos contenidos: ");
    //printUint16Hex(&v, (_uint32_t){0x1});
    printf("%.2X", 0x1);
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
    /*
    * Esta funcion recibe como valor una estrutura del
    * tipo OutputFile llamada File para imprimir sus
    * valores en formato hexadecimal.
    * 
    * Imprime los valores de los ID`s de los sectores.
    * El valor del sector de inicio y el del sector final.
    */
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