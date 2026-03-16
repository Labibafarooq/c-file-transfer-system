#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>  
#include <string.h>  
#include "file_transfer.h"

void show_help() {
    printf("Usage: file_transfer -i <input_file> -o <output_file>\n");
}

int main(int argc, char *argv[]) {
    const char *input_file = NULL, *output_file = NULL;
    char confirm[4];  
    int flag, status;

    
    for (flag = 0; (flag = getopt(argc, argv, "i:o:")) != -1;) {
        if (flag == 'i') {
            input_file = optarg;
        } else if (flag == 'o') {
            output_file = optarg;
        } else {
            show_help();
            return EXIT_FAILURE;
        }
    }

   
    if (!input_file || !output_file) {
        show_help();
        return EXIT_FAILURE;
    }

   
    if (access(input_file, F_OK) == -1) {
        printf("Error: The input file '%s' does not exist. Please check the file path and try again.\n", input_file);
        return EXIT_FAILURE;
    }
 
    if (access(output_file, F_OK) != -1) {
        printf("Warning: The output file '%s' already exists. Do you want to overwrite it?\n(Type 'yes' to confirm or type anything else to cancel): ", output_file);
        scanf("%3s", confirm);
        if (strcmp(confirm, "yes") != 0) {
            printf("The file transfer has been canceled. No changes were made.\n");
            return EXIT_FAILURE;
        }
    } else {
        printf("Notice: The output file '%s' does not exist. Would you like to create it?\n(Type 'yes' to create it or type anything else to cancel): ", output_file);
        scanf("%3s", confirm);
        if (strcmp(confirm, "yes") != 0) {
            printf("The file transfer has been canceled. No new file was created.\n");
            return EXIT_FAILURE;
        }
    }
 
    status = transfer_file(input_file, output_file);
    if (status == 0) {
        printf("Success: The file was successfully transferred from '%s' to '%s'.\n", input_file, output_file);
    } else {
        printf("Error: The file transfer failed. Please try again.\n");
    }

    return status;
}
