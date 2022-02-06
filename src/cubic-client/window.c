//
// cubic
//

#include "window.h"

int window_getWidth(window_t *this) {
    return this->width;
}

int window_getHeight(window_t *this) {
    return this->height;
}

const char *window_getTitle(window_t *this) {
    return this->title;
}

void window_setTitle(window_t *this, const char *title) {
    glfwSetWindowTitle(this->handle, title);
    this->title = title;
}

int window_shouldClose(window_t *this) {
    return glfwWindowShouldClose(this->handle);
}

void window_swapBuffers(window_t *this) {
    glfwSwapBuffers(this->handle);
}

void window_makeContextCurrent(window_t *this) {
    glfwMakeContextCurrent(this->handle);
}

window_t window_new(int width, int height, const char *title) {
    window_t result = {};
    result.handle = glfwCreateWindow(width, height, title, 0, 0);
    result.getWidth = window_getWidth;
    result.getHeight = window_getHeight;
    result.getTitle = window_getTitle;
    result.setTitle = window_setTitle;
    result.shouldClose = window_shouldClose;
    result.swapBuffers = window_swapBuffers;
    result.makeContextCurrent = window_makeContextCurrent;
    return result;
}
