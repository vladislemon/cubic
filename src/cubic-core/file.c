//
// cubic
//

#include "file.h"
#include <stdlib.h>
#include <stdio.h>

size_t file_load(const char *filePath, char *buffer, size_t bufferSize) {
    FILE *file = fopen(filePath, "rb");
    size_t bytesRead = fread(buffer, 1, bufferSize, file);
    fclose(file);
    return bytesRead;
}

size_t file_load_zero_terminated(const char *filePath, char *buffer, size_t bufferSize) {
    size_t bytesRead = file_load(filePath, buffer, bufferSize);
    if (bufferSize > bytesRead) {
        buffer[bytesRead] = 0;
    }
    return bytesRead;
}

char *file_load_to_heap(const char *filePath, size_t *lengthOut) {
    FILE *file = fopen(filePath, "rb");
    fseek(file, 0, SEEK_END);
    size_t length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = malloc(length);
    size_t bytesRead = fread(buffer, 1, length, file);
    fclose(file);
    lengthOut[0] = bytesRead;
    return buffer;
}

char *file_load_to_heap_zero_terminated(const char *filePath, size_t *lengthOut) {
    FILE *file = fopen(filePath, "rb");
    fseek(file, 0, SEEK_END);
    size_t length = ftell(file) + 1;
    fseek(file, 0, SEEK_SET);
    char *buffer = malloc(length);
    size_t bytesRead = fread(buffer, 1, length, file);
    fclose(file);
    buffer[bytesRead] = 0;
    lengthOut[0] = bytesRead;
    return buffer;
}
