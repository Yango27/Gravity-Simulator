#include <iostream>
#include "Simulation.h"
#include <future>
#include <thread>
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

	float t = 0.00015; //delat time in years, adjust as needed for simulation speed, 
	//just as a warning, the larger the value, the faster the simulation, but also less accurate it will be, and vice versa.

    Simulation s;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		auto fut = std::async(&Simulation::calculateEnergy, &s);
        s.drawSimulation(t);

        glfwSwapBuffers(window);
        glfwPollEvents();

        double energy = fut.get();
		std::cout << "Energy: " << energy << std::endl;
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}
