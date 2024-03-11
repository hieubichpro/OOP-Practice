#include <iostream>
#include <vector>
using namespace std;

class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;
 
public:
	Point(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{
 
	}
 
	friend std::ostream& operator<<(std::ostream &out, const Point &p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Shape
{
public:
    virtual ostream& print(ostream& out) const  = 0;
    friend ostream& operator<<(ostream& out, const Shape& s)
    {
        return s.print(out);
    }
    virtual ~Shape() {}
};

class Triangle : public Shape
{
private:
    Point m_a, m_b, m_c;
public:
    Triangle(Point a, Point b, Point c) : m_a(a), m_b(b), m_c(c) {}
    virtual ostream& print(ostream& out) const override
    {
        cout << "Triangle(" << m_a << ", " << m_b << ", " << m_c << ")" << endl; 
        return out;
    }
};

class Circle : public Shape
{
private:
    Point m_o;
    int m_r;
public:
    Circle(Point o, int r) : m_o(o), m_r(r) {}
    virtual ostream& print(ostream& out) const override
    {
        cout << "Circle(" << m_o << ", " << m_r << ")" << endl;
        return out;
    }
    int getRadius() const {return m_r;}
};

// int main()
// {
//     Circle c(Point(1, 2, 3), 7);
//     std::cout << c << '\n';
 
//     Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
//     std::cout << t << '\n';
 
//     return 0;
// }

int getLargestRadius(const vector<Shape*> &v)
{
    int maxSoFar = -1;
    for (auto &s : v)
    {
        auto tmp = dynamic_cast<Circle*>(s);
        if (tmp)
            maxSoFar = max(maxSoFar, tmp->getRadius());
    }
    return maxSoFar;
}

int main()
{
	vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));
 
	// Вывод элементов вектора v здесь
    for (auto const& elem: v)
        cout << *elem << endl;
 
    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // реализуйте эту функцию
	for (auto const &element : v)
		delete element;
	// Удаление элементов вектора v здесь
}