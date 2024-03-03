#include <iostream>
using namespace std;

// class Point
// {
// private:
//     double m_x, m_y, m_z;
// public:
//     Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z) {}
//     friend ostream& operator<<(ostream &out, const Point& p);
//     friend istream& operator>>(istream &in, Point& p);
// };

// ostream& operator<<(ostream &out, const Point& p)
// {
//     out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")" << endl;
//     return out;
// }
// istream& operator>>(istream &in, Point& p)
// {
//     in >> p.m_x;
//     in >> p.m_y;
//     in >> p.m_z;
//     return in;
// }

// int main()
// {
//     std::cout << "Enter a point: \n";
 
//     Point point;
//     std::cin >> point;
 
//     std::cout << "You entered: " << point << '\n';
 
//     return 0;
// }

class Fraction
{
private:
    int m_a;
    int m_b;
public:
    Fraction(int a = 0, int b = 1) : m_a(a), m_b(b)
    {
        reduce();
    }
	static int nod(int a, int b)
	{
		return b == 0 ? a : nod(b, a % b);
	}
    void reduce()
    {
        int n = nod(m_a, m_b);
        m_a /= n;
        m_b /= n;
    }
    friend ostream& operator<<(ostream &out, const Fraction& f);
    friend istream& operator>>(istream &in, Fraction& f);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
};

ostream& operator<<(ostream &out, const Fraction& f)
{
    out << f.m_a << "/" << f.m_b << endl;
    return out;
}

istream& operator>>(istream &in, Fraction& f)
{
    in >> f.m_a;
    in >> f.m_b;
    return in;
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return Fraction(f1.m_a * f2.m_a, f1.m_b * f2.m_b);
}

int main()
{
 
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;
 
	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;
 
	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';
 
	return 0;
}