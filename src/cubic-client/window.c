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
    window_t window = {};
    window.handle = glfwCreateWindow(width, height, title, 0, 0);
    window.getWidth = window_getWidth;
    window.getHeight = window_getHeight;
    window.getTitle = window_getTitle;
    window.setTitle = window_setTitle;
    window.shouldClose = window_shouldClose;
    window.swapBuffers = window_swapBuffers;
    window.makeContextCurrent = window_makeContextCurrent;
    return window;
}
