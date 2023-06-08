#ifndef __OTHER_C_
#define __OTHER_C_

#include <stdio.h>
//#include <conio.h>
#include "type_data_c.h"
#include "colors.h"

const ui8 chars[] = "0123456789abcdef";

#define VarPoint_define(type_data, name) struct  { \
    type_data* pointer; \
    _uint32_t size; \
} name; 
// structura con un puntero  
// y su tamaño


void copyStrUint8Pointer(db *origen, db *destino, _uint32_t sizeOrg, _uint32_t sizeDst);
void printUint8Hex(db *string, _uint32_t size);
void printUint8Char(db *string, _uint32_t size);
void printUint16Hex(dw *string, _uint32_t size);
void printUint16Char(dw *string, _uint32_t size);
ui32 sizeStringUint8();

#include "other.c"
#endif