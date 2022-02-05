//
// cubic
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <pthread.h>
#include "window.h"

void *renderFunc(void *arg) {
    window_t *window = arg;
    double lastTime = glfwGetTime();
    while (!glfwWindowShouldClose(window->handle)) {
        glfwSwapBuffers(window->handle);
        char title[32];
        double time = glfwGetTime();
        sprintf(title, "cubic: dt=%.2fms", (time - lastTime) * 1000);
        window->setTitle(window, title);
        lastTime = time;
    }
    return 0;
}

int main() {
    glfwInit();
    window_t window = window_new(600, 400, "cubic");
    glfwMakeContextCurrent(window.handle);
    glewInit();
    glfwSwapInterval(-1);

    pthread_attr_t threadAttr;
    pthread_attr_init(&threadAttr);
    pthread_t thread;
    pthread_create(&thread, &threadAttr, renderFunc, &window);

    while (!glfwWindowShouldClose(window.handle)) {
        glfwWaitEvents();
    }
    glfwTerminate();
}
