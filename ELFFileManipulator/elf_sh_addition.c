#include "elf_support.h"
#include <stdio.h>

int main(int argc, char** argv){
    if(argc < 2){
        printf("Need to specify a path to a file as an argument\n");
        return 1;
    }
   
    //const value to increase size of section header entries with
    const int ADDENDUM = 64;

    const char* file_path = "/home/reu24/EvilELF/ELFFileManipulator/example.c";

    const char* output_file_path = "ModifiedElfOutput/example"; // Adjust output path as needed
    Elf_Manager* manager = load_elf_file(argv[1]);

    // Write the modified ELF file with extended section headers filled with 0xFF
    write_elf_file_extension(manager, output_file_path, ADDENDUM);
    // Modify the section headers
    extend_sections(manager, ADDENDUM);

    // Write the modified ELF file
    write_elf_file_extension(manager, file_path, ADDENDUM);

    // Clean up (assuming you have a function for this)
    free_manager(manager);

    return 0;
}

