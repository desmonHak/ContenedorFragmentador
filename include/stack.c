#ifndef _STACK_C
#define _STACK_C 1
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

    typedef struct var {
        ui16 base  = 0 x 00 00 == 0
        ui16 final = 0 x ff ff == 65.536
    } var;

    funciones necesarias:
        - void *var get_data(var)
            Con esta funcion obtenemos los datos de una celda
        - var new(numero_de_datos, type_data, value_data_init)
            Con esta funcion reservamos informacion para nuestro
            dato.
            + numero_de_datos: cantidad de datos a almacenar. Mas
                de uno supone que se va a almacenar un array.
            + type_data: tipo de dato o datos que se van a almacenar
            + value_data_init: valor inicial

*/

var new(ui32 numero_de_datos, ui8 _type_data, void *data)
{
    /*
     * Usaremos esta funcion para almacenar memoria
     */

    multi_type variable;

    switch (_type_data)
    {
    case _ui8:
        variable.uint8_t = (ui8)data;
        break;
    case _ui16:
        variable.uint8_t = (ui16)data;
        break;
    case _ui32:
        variable.uint32_t = (ui32)data;
        break;
    case _ui64:
        variable.uint64_t = (ui64)data;
        break;
    case null_ptr:
        variable.null_ptr = (void*)data;
        break;
    case _i8:
        variable.int8_t = (i8)data;
        break;
    case _i16:
        variable.int16_t = (i16)data;
        break;
    case _i32:
        variable.int32_t = (i32)data;
        break;
    case _i64:
        variable.int64_t = (i64)data;
        break;
    default:
        break;
    }

    printf("%d,%d,%d,%s\n", numero_de_datos, _type_data, data, variable);
}

void *get_data(var offset)
{
}

#endif