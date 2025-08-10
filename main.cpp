#include <iostream>
#include "Simulation.h"
int main() {
    if (!glfwInit()) {
        std::cerr << "Error initializing GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(SCREEN_SIZE, SCREEN_SIZE, "Graviity Simulation", NULL, NULL);
    if (!window) {
        std::cerr << "Could not create the window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glViewport(0, 0, SCREEN_SIZE, SCREEN_SIZE);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-SCREEN_SIZE / 2, SCREEN_SIZE / 2, -SCREEN_SIZE / 2, SCREEN_SIZE / 2, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float t = 0.0015;

    Simulation s;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
		double energy = s.calculateEnergy();
        s.drawSimulation(t);
        glfwSwapBuffers(window);
        glfwPollEvents();
		std::cout << "Energy: " << energy << std::endl;
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}
