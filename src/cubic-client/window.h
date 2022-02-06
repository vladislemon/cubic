//
// cubic
//

#ifndef CUBIC_WINDOW_H
#define CUBIC_WINDOW_H

#include <GLFW/glfw3.h>

typedef struct window_s window_t;

struct window_s {
    int width;
    int height;
    const char *title;
    GLFWwindow *handle;

    int (*getWidth)(window_t *window);
    int (*getHeight)(window_t *window);
    const char *(*getTitle)(window_t *window);
    void (*setTitle)(window_t *window, const char *title);
    int (*shouldClose)(window_t *window);
    void (*swapBuffers)(window_t *window);
    void (*makeContextCurrent)(window_t *window);
};

window_t window_new(int width, int height, const char *title);

#endif //CUBIC_WINDOW_H
