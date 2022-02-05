//
// cubic
//

#ifndef CUBIC_FILE_H
#define CUBIC_FILE_H

#include <io.h>
#include <fcntl.h>

size_t loadBytes(const char *filePath, char *buffer, size_t bufferSize);

size_t loadText(const char *filePath, char *buffer, size_t bufferSize);

#endif //CUBIC_FILE_H
