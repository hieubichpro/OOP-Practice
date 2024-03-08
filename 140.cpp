#include <iostream>
using namespace std;

class Dollars
{
private:
    int m_dollars;
public:
    Dollars(int dollars = 0) : m_dollars(dollars) {}
    operator int() {return m_dollars;}
};

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents = 0) : m_cents(cents) {}
    operator Dollars() {return Dollars(m_cents / 100);}
};

int main()
{
// конвертация
    Dollars a(9);
// явно конвертация
    int d = static_cast<int>(a);
// неявно конвертация
    cout << a;

    Cents c(700);
    cout << Dollars(c);
    return 0;
}