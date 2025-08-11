#pragma once
#include "Circle.h"
const double G = 4 * PI * PI;

class Simulation
{
public:
	Simulation() //!!REMEMBER, THE UNITS FOR MASS ARE IN SOLAR MASSES, AND THE DISTANCES ARE IN AU (ASTRONOMICAL UNITS), ALSO TIME IS IN YEARS!!
    {
        /*
        Circle(float r, double mass, float color[3], 
        double cx = 0.0, double cy = 0.0, double vx = 0.0, double vy = 0.0, 
        double ax = 0.0, double ay = 0.0, bool path = true, int N = 40);
        
		-- this is the constructor for the Circle class, which is used to create the bodies in the simulation.
		-> r is the radius of the circle drawn, does not affect the simulation, just in the visual.
		-> mass is the mass of the body in solar masses.
		-> color is an array of 3 floats that defines the color of the body in RGB format from 0 to 1.
		-> cx and cy are the coordinates of the center of the circle in AU.
		-> vx and vy are the velocity of the body in AU/year.
		-> ax and ay are the acceleration of the body in AU/year^2.
		-> path is a boolean that defines if the path of the body is drawn or not.
		-> N is the number of segments used to draw the circle, more segments means a smoother circle.

		--- i recommend just setting, radius and color for a better understanding of the simulation, 
        mass, center and velocity (for obvious reasons) 
		the rest is not really necessary, as the acceleration is calculated by the simulation itself.
		You can see the are already default values for acceleration, path and segments (N), so don't even need to worry about them.

		!!Remember to push the bodies to the vector after creating them, so they can be simulated!!
        */
        float color1[3] = { 1.0f, 0.0f, 0.0f }; //defines color
        float color2[3] = { 0.0f, 1.0f, 0.0f }; //for the bodies
        float color3[3] = { 0.0f, 0.0f, 1.0f }; //rgb format from 0 to 1

        float radius1 = 15.0f; //makes the circles 
        float radius2 = 10.0f; //bigger or smaller
        float radius3 = 10.0f; //(does not affect on the simulation, just in the visual)
        
        Circle body1(radius1, 1, color1); //creates the bodies
        Circle body2(radius2, 3.00274e-6, color2, 1, 0, 0, 1); //using the Circle constructor
        Circle body3(radius3, 3.00274e-4, color3, 1.5, 0, 0, 1);

        m_planets.push_back(body1); //push the bodies
        m_planets.push_back(body2); //to the vector
        m_planets.push_back(body3); //so they can be simulated
    }
    void drawSimulation(float t);
    double calculateEnergy();

private:
    std::vector<Circle> m_planets;
    void calculateGrav();
    void calculateRefP(float refP[2]);
};