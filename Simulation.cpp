#include "Simulation.h"

void Simulation::drawSimulation(float t)
{
    calculateGrav();
    for (int i = 0; i < m_planets.size(); i++)
    {
		m_planets[i].moveCircle(t);
	}
    calculateGrav();
    for (int i = 0; i < m_planets.size(); i++)
    {
        m_planets[i].setNewVelocity(t);
	}
    float refP[2];
    calculateRefP(refP);
    for (int i = 0; i < m_planets.size(); i++)
    {
        m_planets[i].drawCircle(refP);
    }
}

void Simulation::calculateGrav()
{
    for (int i = 0; i < m_planets.size(); i++)
    {
        double gFx = 0, gFy = 0;
        for (int j = 0; j < m_planets.size(); j++)
        {
            if (j != i)
            {
                double dx = m_planets[i].getPositionX() - m_planets[j].getPositionX();
                double dy = m_planets[i].getPositionY() - m_planets[j].getPositionY();
                double r = std::hypot(dx, dy);

                double gF = (G * m_planets[j].getMass() * m_planets[i].getMass()) / (r * r);

                gFx += -gF * (dx / r);
                gFy += -gF * (dy / r);
            }
        }
        m_planets[i].setAcc(gFx / m_planets[i].getMass(), gFy / m_planets[i].getMass());
    }
}

void Simulation::calculateRefP(float refP[2])
{
    double refUA[2] = { 0.0,0.0 };
    for (int i = 0; i < m_planets.size(); i++)
    {
        refUA[0] += m_planets[i].getPositionX();
        refUA[1] += m_planets[i].getPositionY();
    }

    refUA[0] /= m_planets.size();
    refUA[1] /= m_planets.size();

    Circle::conversionMToPixel(refUA, refP);
}

double Simulation::calculateEnergy()
{
    double totalEnergy = 0;
    for (int i = 0; i < m_planets.size(); i++)
    {
        double potentialEnergy = 0;
        for (int j = i + 1; j < m_planets.size(); j++)
        {
            double dx = m_planets[i].getPositionX() - m_planets[j].getPositionX();
            double dy = m_planets[i].getPositionY() - m_planets[j].getPositionY();
            double r = std::hypot(dx, dy);
            potentialEnergy -= G * m_planets[i].getMass() * m_planets[j].getMass() / r;
        }
        double kineticEnergy = 0.5 * m_planets[i].getTotalV() * m_planets[i].getTotalV() * m_planets[i].getMass();
        totalEnergy += potentialEnergy + kineticEnergy;
    }
    return totalEnergy;
}