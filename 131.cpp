#include <iostream>
using namespace std;

// class Dollars
// {
// private:
//     int m_value;
// public:
//     Dollars(int value = 0): m_value{value} {}
//     void setValue(const int& value) {m_value = value;}
//     int getValue() {return m_value;}
//     friend Dollars operator+(const Dollars& d1, const Dollars& d2);
//     friend Dollars operator-(const Dollars& d1, const Dollars& d2);
//     friend Dollars operator+(const Dollars& d1, int value);
//     friend Dollars operator+(int value, const Dollars& d1);
// };

// Dollars operator+(const Dollars &d1, const Dollars &d2)
// {
//     return Dollars(d1.m_value + d2.m_value);
// }

// Dollars operator-(const Dollars &d1, const Dollars &d2)
// {
//     return Dollars(d1.m_value - d2.m_value);
// }

// Dollars operator+(const Dollars&d1, int value)
// {
//     return Dollars(d1.m_value + value);
// }

// Dollars operator+(int value, const Dollars &d1)
// {
//     return Dollars(value + d1.m_value);
// }

// int main()
// {
// 	// Dollars dollars1(7);
// 	// Dollars dollars2(9);
// 	// Dollars dollarsSum = dollars1 - dollars2;
// 	// std::cout << "I have " << dollarsSum.getValue() << " dollars." << std::endl;
 
// 	// return 0;
// 	Dollars d1 = Dollars(5) + 5;
// 	Dollars d2 = 5 + Dollars(5);
 
// 	std::cout << "I have " << d1.getValue() << " dollars." << std::endl;
// 	std::cout << "I have " << d2.getValue() << " dollars." << std::endl;
 
// 	return 0;
// }

// class Values
// {
// private:
//     int m_min;
//     int m_max;
// public:
//     Values(int min = 0, int max = 0) : m_min(min), m_max(max) {}
//     int getMin() {return m_min;}
//     int getMax() {return m_max;}
// 	friend Values operator+(const Values &v1, const Values &v2);
// 	friend Values operator+(const Values &v, int value);
// 	friend Values operator+(int value, const Values &v);
// };

// Values operator+(const Values& v1, const Values& v2)
// {
//     int min = v1.m_min < v2.m_min ? v1.m_min : v2.m_min;
//     int max = v1.m_max > v2.m_max ? v1.m_max : v2.m_max;
//     return Values(min, max);
// }

// Values operator+(const Values& v1, int value)
// {
//     int min = v1.m_min < value ? v1.m_min : value;
//     int max = v1.m_max > value ? v1.m_max : value;
//     return Values(min, max);
// }

// Values operator+(int value, const Values& v)
// {
//     return v + value;
// }
