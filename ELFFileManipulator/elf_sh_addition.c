#include "elf_support.h"
#include <stdio.h>

//I just took away the extend section function
int main(int argc, char** argv){
    if(argc < 2){
        printf("Need to specify a path to a file as an argument\n");
        return 1;
    }
   
    //const value to increase size of section header entries with
    const int ADDENDUM = 64;

    Elf_Manager* manager = load_elf_file(argv[1]);
    printf("Loaded file: %s\n",manager->file_path);

    // Write the modified ELF file with extended section headers filled with 0xFF
    write_elf_file_extension(manager, argv[1], ADDENDUM);

    // Clean up (assuming you have a function for this)
    free_manager(manager);

    return 0;
}

