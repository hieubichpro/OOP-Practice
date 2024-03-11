#include <iostream>
#include <string>
using namespace std;

class Fruit
{
private:
    string m_name;
    string m_color;
public:
    Fruit(string color = "", string name = "") : m_name(name), m_color(color) {}
    string getName() const {return m_name;}
    string getColor() const {return m_color;}
};

class Apple : public Fruit
{
public:
    Apple(string color = "", string name = "apple") : Fruit(color, name) {}
};

class Banana : public Fruit
{
public:
    Banana(string color = "yellow", string name = "banana") : Fruit(color, name) {}
};

class GrannySmith : public Apple
{
public:
    GrannySmith(string color = "green", string name = "Granny Smith apple") : Apple(color, name) {}
};


int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;
 
	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	
	return 0;
}