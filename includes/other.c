#ifndef __OTHER_H_
#define __OTHER_H_
#include "code.h"

ui32 sizeStringUint8()
{
    return 0;
}

void copyStrUint8Pointer(db *origen, db *destino, _uint32_t sizeOrg, _uint32_t sizeDst)
{
    /*
     * string de origen.
     * string de destino al que copiar los datos.
     * sizeOrg posicion desde la que empezar a escribir los nuevos valores.
     * sizeDst Tamaño de los datos Finales.
     *
     * char a[4];
     * char b[4];
     * copyStrUint8Pointer(a, b, 0, 4);
     */

    for (_uint32_t i = {0}; i._uint32_t < sizeDst._uint32_t; i._uint32_t++)
    {
        destino[i._uint32_t] = origen[i._uint32_t];
    }
}

void printUint8Hex(db *string, _uint32_t size)
{
    putchar('|');
    for (_uint32_t i = {0}; i._uint32_t < size._uint32_t; i._uint32_t++)
    {
        putchar(chars[string[i._uint32_t] / 16]);
        putchar(chars[string[i._uint32_t] % 16]);
        putchar('|');
    }
    putchar(0x10);
}

void printUint8Char(db *string, _uint32_t size)
{
    for (_uint32_t i = {0}; i._uint32_t < size._uint32_t; i._uint32_t++)
    {
        putchar(string[i._uint32_t]);
    }
    putchar(0x10);
}

void printUint16Hex(dw *string, _uint32_t size)
{
    putchar('|');
    for (_uint32_t i = {0}; i._uint32_t < size._uint32_t; i._uint32_t++)
    {
        db val = *((db *)&string[i._uint32_t] + 1); // parte alta
        putchar(chars[val / 16]);
        putchar(chars[val % 16]);
        putchar(' ');

        val = *((db *)&string[i._uint32_t] + 0); // parte baja
        putchar(chars[val / 16]);
        putchar(chars[val % 16]);
        putchar('|');
    }
}
void printUint16Char(dw *string, _uint32_t size)
{
    putchar('|');
    for (_uint32_t i = {0}; i._uint32_t < size._uint32_t; i._uint32_t++)
    {
        db val = (db)(string[i._uint32_t] & 0xff00);
        putchar(val);
        putchar(' ');
        val = string[i._uint32_t] & 0x00ff;
        putchar(val);
        putchar('|');
    }
}

#include "other.h"
#endif