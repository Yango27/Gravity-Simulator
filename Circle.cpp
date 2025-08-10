#include "Circle.h"

Circle::Circle(float r, double mass, bool path, float color[3], double cx, double cy, double vx, double vy, double ax, double ay, int N)
{
    m_r = r; m_N = N; m_mass = mass;
    m_position[0] = cx; m_position[1] = cy; m_velocity[0] = vx; m_velocity[1] = vy; m_acc[0] = ax; m_acc[1] = ay;
    float arrayP[2];
    conversionMToPixel(m_position, arrayP);
    m_pathX.push_back(arrayP[0]);
    m_pathY.push_back(arrayP[1]);
    m_path = path;
    m_prevPosition[0] = 0.0;
    m_prevPosition[1] = 0.0;
    m_firstIteration = true;
    m_color[0] = color[0];
    m_color[1] = color[1];
    m_color[2] = color[2];
}

void Circle::drawCircle(float refP[2])
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(m_color[0], m_color[1], m_color[2]);
    float arrayP[2];
    conversionMToPixel(m_position, arrayP);
    arrayP[0] -= refP[0];
    arrayP[1] -= refP[1];
    glVertex2f(arrayP[0], arrayP[1]); //center of the circle

    for (int i = 0; i <= m_N; i++)
    {
        float angle = 2.0f * PI * i / m_N;
        float x = arrayP[0] + cos(angle) * m_r;
        float y = arrayP[1] + sin(angle) * m_r;
        glVertex2f(x, y);
    }
    glEnd();

    if (m_pathX.size() >= 2000)
    {
        m_pathX.erase(m_pathX.begin());
        m_pathY.erase(m_pathY.begin());
    }
    m_pathX.push_back(arrayP[0]);
    m_pathY.push_back(arrayP[1]);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < m_pathX.size(); i++)
    {
        glColor4f(m_color[0], m_color[1], m_color[2], i * 0.01);
        glVertex2f(m_pathX[i], m_pathY[i]);
    }
    glEnd();
}

void Circle::moveCircle(float t)
{
    m_velocity[0] += m_acc[0] * t;
    m_velocity[1] += m_acc[1] * t;

    if (m_firstIteration)
    {
        m_prevPosition[0] = m_position[0] - m_velocity[0] * t;
        m_prevPosition[1] = m_position[1] - m_velocity[1] * t;
        m_firstIteration = false;
    }

    double tempX = m_position[0];
    double tempY = m_position[1];

    m_position[0] = 2 * m_position[0] - m_prevPosition[0] + m_acc[0] * t * t;
    m_position[1] = 2 * m_position[1] - m_prevPosition[1] + m_acc[1] * t * t;

    m_prevPosition[0] = tempX;
    m_prevPosition[1] = tempY;
}

void Circle::setAcc(double ax, double ay)
{
    m_acc[0] = ax;
    m_acc[1] = ay;
}

void Circle::conversionMToPixel(double arrayM[2], float arrayP[2])
{
    arrayP[0] = (arrayM[0] / MAX_DISTANCE) * (SCREEN_SIZE / 2);
    arrayP[1] = (arrayM[1] / MAX_DISTANCE) * (SCREEN_SIZE / 2);
}

double Circle::getTotalV()
{
    return std::hypot(m_velocity[0], m_velocity[1]);
}