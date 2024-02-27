#include "Point3D.h"
#include "Vector3D.h"
#include <iostream>
using namespace std;

void Point3D::print()
{
        cout << "Point(" << m_a << ", " << m_b << ", " << m_c << ")" << endl;
}

void Point3D::moveByVector(const Vector3D &v)
{
        m_a += v.m_a;
        m_b += v.m_b;
        m_c += v.m_c;
}