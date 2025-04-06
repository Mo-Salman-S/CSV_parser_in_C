#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv_parser.h"

#define INITIAL_CAPACITY 10

char** parse_line(const char* line, int* num_fields) {
    int capacity = INITIAL_CAPACITY;
    char** fields = malloc(capacity * sizeof(char*));
    *num_fields = 0;

    const char* ptr = line;
    while (*ptr != '\0' && *ptr != '\n') {
        char buffer[1024];
        int pos = 0;

        if (*ptr == '"') {
            ptr++;  // Skip opening quote
            while (*ptr && !(*ptr == '"' && (*(ptr + 1) == ',' || *(ptr + 1) == '\0' || *(ptr + 1) == '\n'))) {
                if (*ptr == '"' && *(ptr + 1) == '"') {
                    buffer[pos++] = '"';  // Handle escaped quote
                    ptr += 2;
                } else {
                    buffer[pos++] = *ptr++;
                }
            }
            if (*ptr == '"') ptr++;  // Skip closing quote
        } else {
            while (*ptr != ',' && *ptr != '\0' && *ptr != '\n') {
                buffer[pos++] = *ptr++;
            }
        }

        buffer[pos] = '\0';

        if (*num_fields >= capacity) {
            capacity *= 2;
            fields = realloc(fields, capacity * sizeof(char*));
        }

        fields[*num_fields] = malloc(strlen(buffer) + 1);
        strcpy(fields[*num_fields], buffer);
        (*num_fields)++;

        if (*ptr == ',') ptr++;  // Skip comma
    }

    return fields;
}

void free_fields(char** fields, int num_fields) {
    for (int i = 0; i < num_fields; ++i) {
        free(fields[i]);
    }
    free(fields);
}
