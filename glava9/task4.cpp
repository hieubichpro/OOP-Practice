#include <iostream>
#include <cmath>
using namespace std;

class FixedPoint
{
private:
    int16_t m_base;
    int16_t m_decimal;
public:
    FixedPoint(int16_t base = 0, int16_t decimal = 0) : m_base(base), m_decimal(decimal)
    {
        if (m_base < 0.0 || m_decimal < 0.0)
        {
            // Проверяем целую часть
            if (m_base > 0.0)
                m_base = -m_base;
            // Проверяем дробную часть
            if (m_decimal > 0.0)
                m_decimal = -m_decimal;
        }
    }

    FixedPoint(double num = 0.0)
    {
        m_base = round(num);
        m_decimal = round((num - m_base) * 100);
    }

    operator double() const
	{
		return m_base + static_cast<double>(m_decimal) / 100;
	}
    friend ostream& operator<<(ostream& out, const FixedPoint& fp);

    friend istream& operator>>(istream& in, FixedPoint& fp)
    {
        double tmp; in >> tmp;
        fp = FixedPoint(tmp);
        return in;
    }
    
    friend bool operator==(const FixedPoint& fp1, const FixedPoint& fp2)
    {
        return (fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal);
    }

    friend FixedPoint operator+(const FixedPoint& fp1, const FixedPoint &fp2)
    {
        return FixedPoint(static_cast<double>(fp1) + static_cast<double>(fp2));
    }

    FixedPoint operator-()
    {
        return FixedPoint(-m_base, -m_decimal);
    }
};


ostream& operator<<(ostream &out, const FixedPoint& fp)
{
    out << static_cast<double>(fp);
    return out;
}

// int main()
// {
// 	// FixedPoint a(37, 58);
// 	// std::cout << a << '\n';
 
// 	// FixedPoint b(-3, 9);
// 	// std::cout << b << '\n';
 
// 	// FixedPoint c(4, -7);
// 	// std::cout << c << '\n';
 
// 	// FixedPoint d(-5, -7);
// 	// std::cout << d << '\n';
 
// 	// FixedPoint e(0, -3);
// 	// std::cout << e << '\n';
 
// 	// std::cout << static_cast<double>(e) << '\n';

// 	// FixedPoint a(0.03);
// 	// std::cout << a << '\n';
 
// 	// FixedPoint b(-0.03);
// 	// std::cout << b << '\n';
 
// 	// FixedPoint c(4.01); // сохранится, как 4.0099999..., поэтому нам нужно это всё округлить
// 	// std::cout << c << '\n';
 
// 	// FixedPoint d(-4.01); // сохранится, как -4.0099999..., поэтому нам нужно это всё округлить
// 	// std::cout << d << '\n';
// 	// return 0;
//     cout << boolalpha << endl;
// }

void SomeTest()
{
	std::cout << std::boolalpha;
	std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) << '\n'; // оба значения положительные, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) << '\n'; // оба значения положительные, переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) << '\n'; // оба значения отрицательные, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) << '\n'; // оба значения отрицательные, переполнение
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) << '\n'; // второе значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) << '\n'; // второе значение отрицательное, возможно переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) << '\n'; // первое значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) << '\n'; // первое значение отрицательное, возможно переполнение
}
 
int main()
{
	SomeTest();
 
	FixedPoint a(-0.48); 
	std::cout << a << '\n';
 
	std::cout << -a << '\n';
 
	std::cout << "Enter a number: "; // введите 5.678
	std::cin >> a;
	
	std::cout << "You entered: " << a << '\n';
 
	return 0;
}