#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3D.h"

class Vector3D
{
private:
    double m_a, m_b, m_c;
public:
    Vector3D(double a = 0.0, double b = 0.0, double c = 0.0) : m_a(a), m_b(b), m_c(c) {}
    void print();
    friend void Point3D::moveByVector(const Vector3D &v);
};

#endif
