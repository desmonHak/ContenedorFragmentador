#ifndef _STACK_C
#define _STACK_C	1
#include "stack.h"

/*
    espacio para las variables:
    var3 = 3bytes, var4 = 4 bytes...

    Leyenda para el mapa:
    var3 = A,   var5 = B
    var7 = Z

    +--------------+
    |   my_stack   | -> 5 * 3 = 15 bytes
    +--+--+--+--+--+
    |A |A |A |B |B | 
    +--+--+--+--+--+
    |B |B |B |Z |Z |
    +--+--+--+--+--+
    |Z |Z |Z |Z |Z |
    +--+--+--+--+--+

    typedef struct celda {
        ui16 base  = 0 x 00 00 == 0
        ui16 final = 0 x ff ff == 65.536
    } celda;

    funciones necesarias:
        - *celda get_data()

*/

#endif