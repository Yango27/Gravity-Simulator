#pragma once
#include <GLFW/glfw3.h>
#include <cmath>
#include <vector>
const float PI = 3.14159265358979323846f;
const int SCREEN_SIZE = 800;
const double MAX_DISTANCE = 2; // in AU, you can change this to adjust the scale of the simulation

class Circle
{
public:

	Circle() : m_r(0.0f), m_N(0), m_mass(0.0), m_path(false)
	{
		m_position[0] = 0.0; m_position[1] = 0.0; m_velocity[0] = 0.0; m_velocity[1] = 0.0; m_acc[0] = 0.0; m_acc[1] = 0.0;
		m_color[0] = 0.0f; m_color[1] = 0.0f; m_color[2] = 0.0f;
		m_prevAcc[0] = 0.0; m_prevAcc[1] = 0.0;
	}
	Circle(float r, double mass, float color[3], double cx = 0.0, double cy = 0.0, double vx = 0.0, double vy = 0.0, double ax = 0.0, double ay = 0.0, bool path = true, int N = 40);
	void drawCircle(float refP[2]);
	void moveCircle(float t);
	void setAcc(double ax, double ay);
	static void conversionMToPixel(double arrayM[2], float arrayP[2]);
	double getPositionX() { return m_position[0]; }
	double getPositionY() { return m_position[1]; }
	double getMass() { return m_mass; }
	double getPositionXMeters() { return 149597870700 * m_position[0]; }
	double getPositionYMeters() { return 149597870700 * m_position[1]; }
	double getMassKg() { return 1.989e30 * m_mass; }
	double getVelocityX() { return m_velocity[0]; }
	double getVelocityY() { return m_velocity[1]; }
	double getTotalV();
	void setNewVelocity(float t);

private:

	double m_position[2];
	double m_velocity[2];
	double m_acc[2];
	double m_prevAcc[2];
	float m_color[3];
	float m_r; //radius
	double m_mass;
	int m_N;
	std::vector<float> m_pathX;
	std::vector<float> m_pathY;
	bool m_path;
};