//
// cubic
//

#include "shader_program.h"
#include <GL/glew.h>
#include <stdio.h>

void shader_program_use(shader_program_t *this) {
    glUseProgram(this->programId);
}

unsigned int create_program(
        const char *vertexSource,
        int vertexSourceLength,
        const char *fragmentSource,
        int fragmentSourceLength) {

    char buffer[1024];
    int logLength;
    unsigned int programId = glCreateProgram();
    GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vertexShaderId, 1, &vertexSource, &vertexSourceLength);
    glShaderSource(fragmentShaderId, 1, &fragmentSource, &fragmentSourceLength);
    glCompileShader(vertexShaderId);
    glGetShaderInfoLog(vertexShaderId, sizeof(buffer), &logLength, buffer);
    puts(buffer);
    glCompileShader(fragmentShaderId);
    glGetShaderInfoLog(fragmentShaderId, sizeof(buffer), &logLength, buffer);
    puts(buffer);
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);
    glValidateProgram(programId);
    glDetachShader(programId, vertexShaderId);
    glDetachShader(programId, fragmentShaderId);
    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
    return programId;
}

shader_program_t shader_program_new(
        const char *vertexSource,
        int vertexSourceLength,
        const char *fragmentSource,
        int fragmentSourceLength) {

    shader_program_t program = {};
    program.programId = create_program(vertexSource, vertexSourceLength, fragmentSource, fragmentSourceLength);
    program.use = shader_program_use;
    return program;
}
