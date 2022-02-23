//
// cubic
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define CGLM_DEFINE_PRINTS

#include <cglm/cglm.h>
#include <stdio.h>
#include <pthread.h>
#include "window.h"
#include "cubic-core/file.h"
#include "shader_program.h"

static int windowWidth = 600;
static int windowHeight = 400;
static int windowSizeChanged = 1;
static float mouseX;
static float mouseY;

void *renderFunc(void *arg) {
    window_t *window = arg;
    window->makeContextCurrent(window);
    glewInit();

    size_t vertexLength;
    char *vertexSource = file_load_to_heap_zero_terminated("resources/shaders/main/vertex.glsl", &vertexLength);
    size_t fragmentLength;
    char *fragmentSource = file_load_to_heap_zero_terminated("resources/shaders/main/fragment.glsl", &fragmentLength);
    shader_program_t shaderProgram = shader_program_new(vertexSource, (int) vertexLength, fragmentSource,
                                                        (int) fragmentLength);
    free(vertexSource);
    free(fragmentSource);

    shaderProgram.use(&shaderProgram);
    unsigned int array;
    glGenVertexArrays(1, &array);
    glBindVertexArray(array);
    glEnable(GL_PROGRAM_POINT_SIZE);

    double lastTime = glfwGetTime();
    while (!window->shouldClose(window)) {
        if (windowSizeChanged) {
            glViewport(0, 0, windowWidth, windowHeight);
            glUniform2i(0, windowWidth, windowHeight);
            windowSizeChanged = 0;
        }
        glUniform2f(4, mouseX, mouseY);
        //glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        window->swapBuffers(window);
        char title[32];
        double time = glfwGetTime();
        sprintf(title, "cubic: dt=%.2fms", (time - lastTime) * 1000);
        window->setTitle(window, title);
        lastTime = time;
    }
    return 0;
}

typedef long long int big_big_puzo;

big_big_puzo puzo = 1;

void window_size_callback(GLFWwindow *window, int width, int height) {
    //printf("new window size = {%d, %d}\n", width, height);
    windowWidth = width;
    windowHeight = height;
    windowSizeChanged = 1;
}

void cursor_pos_callback(GLFWwindow *window, double x, double y) {
    //printf("new mouse pos = {%f, %f}\n", x, y);
    mouseX = (float) x;
    mouseY = (float) y;
}

int main() {
    mat4 matrix;
    glm_mat4_identity(matrix);
    glm_mat4_print(matrix, stdout);

    glfwInit();
    glfwSwapInterval(-1);
    window_t window = window_new(600, 400, "cubic");

    pthread_attr_t threadAttr;
    pthread_attr_init(&threadAttr);
    pthread_t thread;
    pthread_create(&thread, &threadAttr, renderFunc, &window);

    if (glfwRawMouseMotionSupported()) {
        glfwSetInputMode(window.handle, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
    }
    //glfwSetInputMode(window.handle, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    glfwSetWindowSizeCallback(window.handle, window_size_callback);
    glfwSetCursorPosCallback(window.handle, cursor_pos_callback);

    while (!window.shouldClose(&window)) {
        glfwWaitEvents();
    }
    glfwTerminate();
}
