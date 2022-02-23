//
// cubic
//

#ifndef CUBIC_SHADER_PROGRAM_H
#define CUBIC_SHADER_PROGRAM_H

typedef struct shader_program_s shader_program_t;

struct shader_program_s {
    unsigned int programId;

    void (*use)(shader_program_t *program);
};

shader_program_t shader_program_new(
        const char *vertexSource,
        int vertexSourceLength,
        const char *fragmentSource,
        int fragmentSourceLength);

#endif //CUBIC_SHADER_PROGRAM_H
