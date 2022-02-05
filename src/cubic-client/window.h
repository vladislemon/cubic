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

    void (*setTitle)(window_t *window, const char *title);
};

window_t window_new(int width, int height, const char *title);

#endif //CUBIC_WINDOW_H
