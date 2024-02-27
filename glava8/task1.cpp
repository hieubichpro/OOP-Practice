#include <iostream>
#include <cmath>

using namespace std;
class Point
{
private:
    double m_a, m_b;
public:
    Point(double a = 0.0, double b = 0.0) : m_a(a), m_b(b) {}
    void print() {cout << "Point(" << m_a << ", " << m_b << ")" << endl;}
    // double distanceTo(const Point& p2)
    // {
    //     return sqrt((p2.m_b - m_b) * (p2.m_b - m_b) + (p2.m_a - m_a) * (p2.m_b - m_b));
    // }
    friend double distanceFrom(const Point& p1, const Point& p2);
};

double distanceFrom(const Point& p1, const Point& p2)
{
    return sqrt((p2.m_b - p1.m_b) * (p2.m_b - p1.m_b) + (p2.m_a - p1.m_a) * (p2.m_a - p1.m_a));
}

int main()
{
    Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
    cout << distanceFrom(first, second) << endl;
    // std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
 
    return 0;
}