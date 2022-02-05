//
// cubic
//

#include "window.h"

void window_setTitle(window_t *this, const char *title) {
    glfwSetWindowTitle(this->handle, title);
    this->title = title;
}

window_t window_new(int width, int height, const char *title) {
    window_t result = {};
    result.handle = glfwCreateWindow(width, height, title, 0, 0);
    result.setTitle = window_setTitle;
    return result;
}
