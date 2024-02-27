#ifndef POINT3D_H
#define POINT3D_H

class Vector3D;

class Point3D
{
private:
    double m_a, m_b, m_c;
public:
    Point3D(double a = 0.0, double b = 0.0, double c = 0.0) : m_a(a), m_b(b), m_c(c) {}
    void print();
    void moveByVector(const Vector3D &v);
};

#endif