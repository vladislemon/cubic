//
// cubic
//

#ifndef CUBIC_FILE_H
#define CUBIC_FILE_H

#include <stddef.h>

size_t file_load(const char *filePath, char *buffer, size_t bufferSize);

size_t file_load_zero_terminated(const char *filePath, char *buffer, size_t bufferSize);

char *file_load_to_heap(const char *filePath, size_t *lengthOut);

char *file_load_to_heap_zero_terminated(const char *filePath, size_t *lengthOut);

#endif //CUBIC_FILE_H
