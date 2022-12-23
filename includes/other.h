#ifndef __OTHER_C_
#define __OTHER_C_

#include "type_data_c.h"

#define VarPoint_define(type_data, name) struct  { \
    type_data* pointer; \
    _uint32_t size; \
} name; 
// structura con un puntero  
// y su tamaño


void copyStrUint8Pointer(db *origen, db *destino, _uint32_t sizeOrg, _uint32_t sizeDst);
void printUint8Hex(db *string, _uint32_t size);
void printUint8Char(db *string, _uint32_t size);

#include "other.c"
#endif