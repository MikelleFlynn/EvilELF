#include "elf_support.h"
#include <stdio.h>

int main(int argc, char** argv){
    if(argc < 2){
        printf("Need to specify a path to a file as an argument\n");
        return 1;
    }
    Elf_Manager* manager = load_elf_file(argv[1]);
    printf("Loaded file: %s\n",manager->file_path);

    print_elf_header_table_overview(manager);

    change_shstrtab_section(manager);

    print_elf_header_table_overview(manager);

    write_elf_file(manager, argv[1]);
    free_manager(manager);

    return 0;
}