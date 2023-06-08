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
        //background_color_custom(RGB_CREATE(origen[i._uint32_t], 12, origen[i._uint32_t]));
        //setConsoleColor(i._uint32_t % C_LIGHTWHITE, i._uint32_t % C_WHITE);
        destino[i._uint32_t] = origen[i._uint32_t];
        //resetColorTerminal();
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
    #define WORD_SIZE 256/8
    #define BLOCK_SLICES (256*4)/8
    printf_color("\t #{FG:red}#{BG:green}|#{BG:reset}");
    for (_uint32_t i = {0}; i._uint32_t < size._uint32_t; i._uint32_t++)
    {
        //putchar(chars[string[i._uint32_t] / 16]);
        //putchar(chars[string[i._uint32_t] % 16]);
        //putchar('|');

        //printf_color(" #{FG:blue}%.2X#{FG:red} #{BG:green}|#{BG:reset}", string[i._uint32_t]);
        unsigned int Avalue1, Avalue2, Avalue3;//, Bvalue1, Bvalue2, Bvalue3;
        int values[] = {12, 19, 5, 9, 3, 16};
        //int _size = sizeof(values) / sizeof(values[0]);

        generate_three_values(string[i._uint32_t], &Avalue1, &Avalue2, &Avalue3, values[0],values[1],values[2],values[3],values[4],values[5]);
        //shuffle_array(values, _size);
        //generate_three_values(string[i._uint32_t] %64, &Bvalue1, &Bvalue2, &Bvalue3, values[0],values[1],values[2],values[3],values[4],values[5]);

        /*printf_color("#{FG:%d;%d;%d}#{BG:%d;%d;%d} %.2X #{BG:green}#{FG:red}|#{BG:reset}", \
            Avalue1, Avalue2, Avalue3,  Bvalue1, Bvalue2, Bvalue3, string[i._uint32_t]);*/
        printf_color("#{FG:%d;%d;%d} %.2X #{BG:green}#{FG:red}|#{BG:reset}", \
            Avalue1, Avalue2, Avalue3,  string[i._uint32_t]);

        //printf_color(" #{FG:red}#{BG:green}|#{BG:reset}");
        if ((i._uint32_t+1) % (BLOCK_SLICES / 8) == 0){
            resetColorTerminal();
            printf_color("\n\t");
        }
        if ((i._uint32_t+1) % (WORD_SIZE / 8) == 0 && i._uint32_t+1 < size._uint32_t)
            printf_color(" #{FG:red}#{BG:green}|#{BG:reset}");
    }
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
    #undef WORD_SIZE
    #undef BLOCK_SLICES
    #define WORD_SIZE 256/16
    #define BLOCK_SLICES (256*4)/16
    printf(" |");
    for (_uint32_t i = {0}; i._uint32_t < size._uint32_t; i._uint32_t++)
    {
        //putchar(chars[string[i._uint32_t] / 16]);
        //putchar(chars[string[i._uint32_t] % 16]);
        //putchar('|');
        printf("%.4X|", string[i._uint32_t]);
        if ((i._uint32_t+1) % (BLOCK_SLICES /16) == 0)
            printf("\n");
        if ((i._uint32_t+1) % (WORD_SIZE /16) == 0 && i._uint32_t+1 < size._uint32_t)
            printf(" |");
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