//
// cubic
//

#include "file.h"

size_t loadBytes(const char *filePath, char *buffer, size_t bufferSize) {
    int fileHandle = open(filePath, O_RDONLY | O_BINARY);
    int bytesRead = read(fileHandle, buffer, bufferSize);
    close(fileHandle);
    return bytesRead;
}

size_t loadText(const char *filePath, char *buffer, size_t bufferSize) {
    size_t bytesRead = loadBytes(filePath, buffer, bufferSize);
    if (bufferSize > bytesRead) {
        buffer[bytesRead] = 0;
    }
    return bytesRead;
}
