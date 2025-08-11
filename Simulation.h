#pragma once
#include "Circle.h"
const double G = 4 * PI * PI;

class Simulation
{
public:
    Simulation()
    {
        float color1[3] = { 1.0f, 0.0f, 0.0f };
        float color2[3] = { 0.0f, 1.0f, 0.0f };
        float color3[3] = { 0.0f, 0.0f, 1.0f };

        float radius = 10.0f;
        bool path = true;
        
        Circle body1(radius, 1, path, color1);
        Circle body2(radius, 3.00274e-6, path, color2, 1, 0, 0, 1);
        Circle body3(radius, 3.00274e-4, path, color3, 1.5, 0, 0, 1);

        m_planets.push_back(body1);
        m_planets.push_back(body2);
        m_planets.push_back(body3);
    }
    void drawSimulation(float t);
    double calculateEnergy();
private:
    std::vector<Circle> m_planets;
    void calculateGrav();
    void calculateRefP(float refP[2]);
};