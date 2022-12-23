#ifndef __CODE_C_
#define __CODE_C_

#include <stdlib.h>

#include "type_data_c.h"
#include "code.h"
#include "other.h"

void write_MTF(MTF *MasterTableFile, OutputFile *File){
    /*
     * Escribimos el MTF en forma de archivo
    */
}

OutputFile InitFileOutput(ui8 *coments, _uint32_t size){
    OutputFile File = {
        .version = {
            0,
            4 // longitud maxima de 4 para el campo de version
        },
        .name_file = {
            (ui8*)malloc(MAX_NAME_BYTES),
            MAX_NAME_BYTES // maximo MAX_NAME_BYTES bytes
        },
        .coments = {
            0,
            {size._uint32_t}
        },
    };

    File.version.pointer = (db*)malloc(File.version.size._uint32_t);
    copyStrUint8Pointer(VERSION, File.version.pointer, (_uint32_t){File.version.size._uint32_t}, (_uint32_t){File.version.size._uint32_t});

    File.coments.pointer = (db*)malloc(File.coments.size._uint32_t);
    copyStrUint8Pointer(coments, File.coments.pointer, (_uint32_t){File.coments.size._uint32_t}, (_uint32_t){File.coments.size._uint32_t});

    return File;
}
#endif