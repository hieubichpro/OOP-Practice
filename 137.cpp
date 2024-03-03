#include <iostream>
using namespace std;

class Number
{
private:
    int m_number;
public:
    Number(int number) : m_number(number) {}
    // префикс
    Number& operator++();
    Number& operator--();
    // суффикс --- мы отделили версию постфикс от версии префикс использованием целочисленного фиктивного параметра в версии постфикс (фиктивный параметр не используется в реализации самой перегрузки, то мы даже не предоставляем ему имя).
    Number operator++(int);
    Number operator--(int);
    friend ostream& operator<<(ostream &out, const Number &num);
};

// префикс
Number& Number::operator++()
{
    if (m_number == 8)
        m_number = 0;
    else
        m_number += 1;
    return *this;
}
Number& Number::operator--()
{
    if (m_number == 0)
        m_number = 8;
    else
        m_number -= 1;
    return *this;
}
// суффикс
Number Number::operator++(int)
{
    Number tmp(m_number);
    ++(*this);
    return tmp;
}
Number Number::operator--(int)
{
    Number tmp(m_number);
    --(*this);
    return tmp;
}
ostream& operator<<(ostream &out, const Number &num)
{
    out << num.m_number << endl;
    return out;
}

int main(void)
{
    Number number(6);
 
    std::cout << number;
    std::cout << ++number;
    std::cout << ++number;
    std::cout << --number;
    std::cout << --number;
 
    return 0;
}