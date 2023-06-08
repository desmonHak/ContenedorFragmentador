#ifndef _STACK_H
    #define _STACK_H	1

    #include "type_data_c.h"

    #ifndef __DEV_OS_ON_ 
    /*
        poner la macro definida __DEV_OS_ON_ 
        a la hora deprogramar para evitar carga 
        la libreria estandar stdlib.h
    */
    #include <stdlib.h>

    /*
        macro para obtener una direcion de memoria que permita
        almacenar una cantidad de "num_data" datos del tipo
        "type_data". El tipo de direcion de memoria se define
        con "type_address"
    */

    #endif

    #ifdef __DEV_OS_ON_
        #ifndef __MEMORY_DINAMIC__
            #error El modo dev os a sido activado, debera incluir una cabecera llamada  \
            MemoryAddressBase.h donde se incluya un archivo llamado MemoryAddressBase.c \
            en la cual cree una funcion para la asignacion de memoria de forma dinamica, \
            esta funcion a de hacer una funcion similar a malloc. \
            dicho archivo a de definir una macro llamada __MEMORY_DINAMIC__ para poder \
            proseguir la compilacion. El formato de la funcion es el siguiente : \
            typo_dato_numerico malloc(typo_dato_numerico)
        #endif

        #define MemoryAddressBase(type_address, type_data, num_data) \
        (type_address*) malloc(sizeof(type_data) * sizeof(num_data))

    #endif

    /*
        macro para crear un stack del tipo de dato "type_data"
        con el nombre de "name" al cual se le asignara un valor
        de direcion base nulo.
    */
    #define CreateStack(type_data, name) type_data *name

    typedef struct var {    
        ui16 base;
        ui16 final;
    } var;
    
#include "stack.c"
#endif