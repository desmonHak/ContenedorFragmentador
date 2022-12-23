#ifndef __OTHER_H_
#define __OTHER_H_

#include <stdio.h>

#include "code.h"
#include "type_data_c.h"

/*uint32_t sizeStringUint8(uint8_t *string){
    return sizeof(string) / sizeof(uint8_t);
}*/

void copyStrUint8Pointer(db *origen, db *destino, _uint32_t sizeOrg, _uint32_t sizeDst){
    /*
     * string de origen.
     * string de destino al que copiar los datos. 
     * sizeOrg Destino del origen, o datos origen a copiar.
     * sizeDst tamaño del array de destino.
    */

    for(_uint32_t i = {0}; i._uint32_t < sizeDst._uint32_t; i._uint32_t++){
        destino[i._uint32_t] = origen[i._uint32_t];
    }
}

void printUint8Hex(db *string, _uint32_t size){
    ui8 chars[] = "0123456789abcdef";
    for(_uint32_t i = {0}; i._uint32_t < size._uint32_t; i._uint32_t++){
        putchar(chars[string[i._uint32_t]/16]);
        putchar(chars[string[i._uint32_t]%16]);
        putchar(' ');
    }
}

void printUint8Char(db *string, _uint32_t size){
    for(_uint32_t i = {0}; i._uint32_t < size._uint32_t; i._uint32_t++){
        putchar(string[i._uint32_t]);
    }
    putchar(0x10);
}



#include "other.h"
#endif