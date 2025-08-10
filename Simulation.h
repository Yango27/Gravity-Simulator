#pragma once
#include "Circle.h"
const double G = 4 * PI * PI;

class Simulation
{
public:
    Simulation()
    {
        float red[3] = { 1.0f, 0.0f, 0.0f };
        float green[3] = { 0.0f, 1.0f, 0.0f };
        float blue[3] = { 0.0f, 0.0f, 1.0f };

        double mass = 1.0;
        int N = 40;

        double v = 1.5 * PI;

        Circle planeta1(
            10.0f, mass, true, red,
            1.0, 0.0,
            0.0, v / 2,
            0.0, 0.0, N
        );

        Circle planeta2(
            10.0f, mass, true, green,
            -0.5, sqrt(3) / 2,
            -v * sqrt(3) / 2, -v * 0.5,
            0.0, 0.0, N
        );

        Circle planeta3(
            10.0f, mass, true, blue,
            -0.5, -sqrt(3) / 2,
            v * sqrt(3) / 2, -v * 0.5,
            0.0, 0.0, N
        );

        m_planets.push_back(planeta1);
        m_planets.push_back(planeta2);
        m_planets.push_back(planeta3);
    }
    void drawSimulation(float t);
    double calculateEnergy();
private:
    std::vector<Circle> m_planets;
    void calculateGrav();
    void calculateRefP(float refP[2]);
};