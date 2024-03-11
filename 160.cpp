#include <iostream>
using namespace std;

class Parent
{
private:
    int m_value;
protected:
    int getValue() const {return m_value;}
public:
    Parent(int value = 0) : m_value(value) {}
};

class Child : public Parent
{
public:
    Child(int value) : Parent(value) {}
    using Parent::getValue; // открыть доступ
    int getValue() = delete; // закрыть доступ
};

int main()
{
    Child c(9);
    cout << c.getValue() << endl;
}