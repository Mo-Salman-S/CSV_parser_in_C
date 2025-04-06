#ifndef CSV_PARSER_H
#define CSV_PARSER_H

char** parse_line(const char* line, int* num_fields);
void free_fields(char** fields, int num_fields);

#endif