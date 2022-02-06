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
    window->makeContextCurrent(window);
    glewInit();
    double lastTime = glfwGetTime();
    while (!window->shouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex2f(-0.5f, -0.5f);
        glColor3f(0, 1, 0);
        glVertex2f(0.5f, -0.5f);
        glColor3f(0, 0, 1);
        glVertex2f(0, 0.5f);
        glEnd();
        window->swapBuffers(window);
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
    glfwSwapInterval(-1);
    window_t window = window_new(600, 400, "cubic");

    pthread_attr_t threadAttr;
    pthread_attr_init(&threadAttr);
    pthread_t thread;
    pthread_create(&thread, &threadAttr, renderFunc, &window);

    while (!window.shouldClose(&window)) {
        glfwWaitEvents();
    }
    glfwTerminate();
}
