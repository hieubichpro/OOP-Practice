#include <iostream>
using namespace std;

class Animal
{
protected:
    string m_name;
public:
    Animal(string name) : m_name(name) {}
    virtual const char* speak() = 0;
};

class Cat : public Animal
{
public:
    Cat(string name) : Animal(name) {}
    virtual const char* speak() {return "Meoww";}
};

int main()
{
    
}