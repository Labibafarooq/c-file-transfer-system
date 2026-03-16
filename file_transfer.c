#include <stdio.h>
#include <stdlib.h>
#include "file_transfer.h"

int transfer_file(const char *input_path, const char *output_path) {  
    FILE *source_file = fopen(input_path, "r");
    if (source_file == NULL) {
        perror("Failed to open the input file");
        return 1;
    }


    FILE *destination_file = fopen(output_path, "w");
    if (destination_file == NULL) {
        perror("Failed to open the output file");
        fclose(source_file);
        return 1;
    }


    char *data_buffer = (char *)malloc(64 * sizeof(char));
    if (data_buffer == NULL) {
        perror("Memory allocation error");
        fclose(source_file);
        fclose(destination_file);
        return 1;
    }


    size_t bytes_read;
    while ((bytes_read = fread(data_buffer, sizeof(char), 64, source_file)) > 0) {
        fwrite(data_buffer, sizeof(char), bytes_read, destination_file);
    }


    free(data_buffer);
    fclose(source_file);
    fclose(destination_file);
    return 0;
}
