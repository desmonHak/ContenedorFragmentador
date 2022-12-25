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
    * Esta funcion la usamos para copiar valores un array de 
    * tipo uint8_t a otro array del mismo tipo. 
    * sizeOrg especica la posicion desde la que empezar
    * escribir los nuevos valores y es una estructura de 
    * tipo _uint32_t donse se almacena un valor de.
    * 32bits.
    * sizeDst Es el tamaño de los datos finales.
    * 
    * char a[4] = (char*)"ab";
    * char b[4] = (char*)"cccc";
    * copyStrUint8Pointer(a, b, 0, 4);
    * 
    * El codigo anterior empieza a escribir en el array b
    * desde la posicion 0, 4 bytes, sobrescribiendo sus 
    * valores con los de a.
    */

    for (_uint32_t i = {0}; i._uint32_t < sizeDst._uint32_t; i._uint32_t++)
    {
        destino[i._uint32_t] = origen[i._uint32_t];
    }
}

void printUint8Hex(db *string, _uint32_t size)
{
    /*
    * Esta funcion imprime en formato hexadecimal los 
    * valores de un string de tipo uint8_t de tamaño size.
    * Su funcionamiento basico es mediante un array llamado
    * chars:
    * 
    * const ui8 chars[] = "0123456789abcdef";
    * 
    * que almacena los posibles valores hexadecimales, se
    * imprime estos haciendo uso de la operacion division
    * y modulo.
    * 
    * siendo n = 67 nuestro numero a pasar, la parte alta
    * de nuestro byte hexadecimal la podemos obtener con
    * la operacion division de tal manera que 67/16 es 4.
    * y con el modulo (67/16) obtenemos que la parte baja es 
    * es 3. Acediendo al array chars y obteniendo sus valores
    * en hex, el elemento en la posicion 3, es el caracter 
    * '3' y el de la posicion 4 es el caracter '4', por lo 
    * que nuestro valores es 0x43. si nos hubiera salida
    * 10 de valor, el elmento 10 de nuestro array es 'a'.
    */
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
    /*
    * Esta funcion imprime los caracteres uint8_t de
    * un array llamado string de tamaño size. Se
    * imprime caracter a caracter.
    */
    for (_uint32_t i = {0}; i._uint32_t < size._uint32_t; i._uint32_t++)
    {
        putchar(string[i._uint32_t]);
    }
    putchar(0x10);
}

void printUint16Hex(dw *string, _uint32_t size)
{
    /*
    * Esta funcion imprime los caracteres uint16_t de
    * un array llamado string de tamaño size. Se
    * realiza una conversion de un dato de 16 bits
    * a 2 datos de 8bits para imprimir cada valor de forma
    * correspondienteen formato hexadecimal al igual que en 
    * la funcion printUint8Hex(). La cantidad de caracteres 
    * de tipo de 8 bits impresos es el tamaño de size*2
    */
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
/*
 * Esta funcion imprime los caracteres uint16_t de
 * un array llmado string de tamaño size. Se
 * realiza una conversion de un dato de 16 bits
 * a 2 datos de 8bits para imprimir cada valor de forma
 * correspondiente. La cantidad de caracteres de tipo
 * de 8 bits impresos es el tamaño de size*2
 */
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