#include "elf_support.h"
#include <stdio.h>

int main(int argc, char** argv) {
    if(argc < 2){
        printf("Need to specify a path to a file as an argument\n");
        return 1;
    }

    Elf_Manager* manager = load_elf_file(argv[1]);
    printf("Loaded file: %s\n",manager->file_path);

    // Inserting dead code
    insert_dead_code(manager);

    // Printing modified section
    printf("Modified .main section:\n");
    for (int i = 0; i < manager->s_hdr[0].sh_size; ++i) {
        printf("%02X ", manager->file_sections[0][i]);
        if ((i + 1) % 8 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    // Freeing allocated memory
    free_manager(manager);

    return 0;
}