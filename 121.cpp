#include <iostream>
using namespace std;

class Math
{
private:
    int value;
public:
    Math(int value = 0) : value(value) {}
    Math& plus(int value)
    {
        this->value += value;
        return *this;
    }
    Math &minus(int value)
    {
        this->value -= value;
        return *this;
    }
    Math &multiply(int value)
    {
        this->value *= value;
        return *this;
    }
    int getValue()
    {
        return this->value;
    }
};

int main(void)
{
    Math m;
    m.plus(7).minus(5).multiply(3);
    cout << m.getValue() << endl;
}