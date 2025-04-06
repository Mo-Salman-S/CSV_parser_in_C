#include <stdio.h>
#include <stdlib.h>
#include "csv_parser.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_filename>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    if (!file) {
        perror("Failed to open file");  
        return 1;
    }

    char line[1024];
    int row = 0;

    while (fgets(line, sizeof(line), file)) {
        int num_fields = 0;  
        char** fields = parse_line(line, &num_fields);

        printf("Row %d:\n", ++row);
        for (int i = 0; i < num_fields; ++i) {  
            printf("Field %d: %s\n", i + 1, fields[i]);
        }
        free_fields(fields, num_fields);
    }

    fclose(file);
    return 0;
}
