#include <stdio.h>

#include "include/code.h"
#include "include/type_data_c.h"

int main()
{

    //indice *start_indices = null;
    //indice *theend_indices = null;

    INIT_SECTOR(sector1) // sector1 de indice 1
    sector1->id_file = sector1->theend_sector = UI16(0x0001);
    sector1->start_sector = UI16(0x0001);

    INIT_SECTOR(sector2) // sector1 de indice 2
    sector2->id_file = sector2->theend_sector = UI16(0x0001);
    sector2->start_sector = UI16(0x0001);

    INIT_INDICE(indice1) // Inicializar un indice
    strcpy((char*)indice1->name_file, "Hola.txt");
    indice1->id_file       = UI16(0x0001);
    indice1->n_sectores    = UI16(0x0001);
    indice1->sectores[0]   = sector1;

    INIT_INDICE(indice2) // Inicializar un indice
    strcpy((char*)indice2->name_file, "Hola.txt");
    indice2->id_file       = UI16(0x0001);
    indice2->n_sectores    = UI16(0x0001);
    indice2->sectores[0]   = sector2;

    /*MTF MasterTableFiles = {
        .n_file = (_uint16_t){0x0001},
        .start_indices = &indice1,
        .theend_indices = &indice2
    };*/

    INIT_MTF(MasterTableFiles)
    MasterTableFiles.n_file = UI16(0x0001);

    MasterTableFiles.start_indices = (indice **)malloc(sizeof(indice*) * 1);
    MasterTableFiles.start_indices[0] = indice1;

    MasterTableFiles.theend_indices = (indice **)malloc(sizeof(indice*) * 1);
    MasterTableFiles.theend_indices[0] = indice2;
    //set_MTF(&MasterTableFiles, UI16(0x0001), indice1, indice2);


    printMTF(MasterTableFiles);

    OutputFile File = InitFileOutput((db *)"Hello word", (_uint32_t){10});
    copyStrUint8Pointer((ui8 *)"fileOutput.bh", File.name_file.pointer, File.name_file.size, File.name_file.size);

    printOutputFile(File);
    printf("%zu\n", sizeof(MasterTableFiles));

    return 0;
}