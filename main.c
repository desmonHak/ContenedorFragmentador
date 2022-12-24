#include <stdio.h>

#include "includes/code.h"
#include "includes/type_data_c.h"

int main()
{

    //indice *start_indices = null;
    //indice *theend_indices = null;

    sector sector1 = (sector){
        .id_file = (_uint16_t) {0x0001},
        .start_sector = (_uint16_t) {0x0000},
        .theend_sector = (_uint16_t) {0x0001},
    };
    sector sector2 = (sector){
        .id_file = (_uint16_t) {0x0001},
        .start_sector = (_uint16_t) {0x0000},
        .theend_sector = (_uint16_t) {0x0001},
    };
    indice indice1 = (indice){
            .name_file = "Hola.txt",
            .id_file = (_uint16_t) {0x0001},
            .n_sectores = (_uint16_t) {0x0001},
            .sectores = &sector1
    };
    indice indice2 = (indice){
            .name_file = "Hola.txt",
            .id_file = (_uint16_t) {0x0001},
            .n_sectores = (_uint16_t) {0x0001},
            .sectores = &sector2
    };
    MTF MasterTableFiles = {
        .n_file = (_uint16_t){0x0001},
        .start_indices = &indice1,
        .theend_indices = &indice2
    };

    printMTF(MasterTableFiles);

    OutputFile File = InitFileOutput((db *)"Hello word", (_uint32_t){10});
    copyStrUint8Pointer((ui8 *)"fileOutput.bh", File.name_file.pointer, File.name_file.size, File.name_file.size);

    printOutputFile(File);
    printf("%ld\n", sizeof(MasterTableFiles));

    return 0;
}