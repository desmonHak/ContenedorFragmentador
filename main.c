#include <stdio.h>

#include "includes/code.h"
#include "includes/type_data_c.h"

int main(){

    OutputFile File = InitFileOutput((db *)"Hello word", (_uint32_t){10});

    printf("%s, %d\n", File.coments.pointer, File.coments.size._uint32_t);
    printf("%s, %d\n", File.name_file.pointer, File.name_file.size._uint32_t);

    printf("%s, %d\n", File.version.pointer, File.version.size._uint32_t);
    printUint8Hex(File.version.pointer, (_uint32_t){File.version.size._uint32_t});
    printUint8Char(File.version.pointer, (_uint32_t){File.version.size._uint32_t});
    
    //printf("%d\n", sizeStringUint8(File.coments));

    return 0;
}