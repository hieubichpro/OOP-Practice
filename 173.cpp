#include <iostream>
using namespace std;

template <typename T>
const T& my_max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

template <class T>
T average(T* arr, int length)
{
    T sum = 0;
    for (int i = 0; i < length; i++)
        sum += arr[i];
    sum /= length;
    return sum;
}

class Dollars
{
private:
    int m_dollars;
public:
    Dollars(int dollars = 0) : m_dollars(dollars) {}
    friend bool operator>(const Dollars &d1, const Dollars& d2);
    friend ostream& operator<<(ostream& out, const Dollars& d);
    Dollars& operator+=(const Dollars& another)
    {
        m_dollars += another.m_dollars;
        return *this;
    }

    Dollars& operator/=(int value)
    {
        m_dollars /= value;
        return *this;
    }
};

bool operator>(const Dollars &d1, const Dollars& d2)
{
    return (d1.m_dollars > d2.m_dollars);
}
ostream& operator<<(ostream& out, const Dollars& d)
{
    out << d.m_dollars << endl;
    return out;
}

int main()
{
    // int a = my_max(3, 4);
    // double b = my_max(1.23, 2.22);
    // char c = my_max('a', 'b');
    // cout << a << " " << b << " " << c << endl;
    Dollars d1(7);
    Dollars d2(10);
    Dollars bigger = my_max(d1, d2);
    cout << bigger << endl;
    Dollars array3[] = { Dollars(7), Dollars(12), Dollars(18), Dollars(15) };
    std::cout << average(array3, 4) << '\n';
    return 0;
}