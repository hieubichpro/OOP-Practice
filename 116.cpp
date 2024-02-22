// #include <iostream>
// using namespace std;
// class Fraction
// {
// private:
//     double a;
//     double b;
// public:
//     //constructor by default;
//     // Fraction()
//     // {
//     //     a = 0;
//     //     b = 1;
//     // }
//     // // constuctor with parameters
//     // Fraction(double a, double b)
//     // {
//     //     this->a = a;
//     //     this->b = b;
//     // }
//     //constructor by default 
//     Fraction(double a, double b)
//     {
//         this->a = a;
//         this->b = b;
//     }
//     double getA() {return a;}
//     double getB() {return b;}
//     double getValue() {return static_cast<double>(a) / b;}
// };

// double main()
// {
//     Fraction drob;
//     cout << drob.getA() << "/" << drob.getB() << endl;
//     return 0;
// }

// class A
// {
// public:
//     A() { std::cout << "A\n"; }
// };
 
// class B
// {
// private:
//     A m_a; // B содержит A, как переменную-член
 
// public:
//     B() { std::cout << "B\n"; }
// };
 
// double main()
// {
//     B b;
//     return 0;
// }
// // =>> A
// // =>> B

#include <iostream>
#include <string>
using namespace std;

class Ball
{
private:
    double radius;
    string color;
public:
    Ball(double radius)
    {
        color = "red";
        this->radius = radius;
    }
    Ball(const string& color ="red", double radius =20.0)
    {
        this->radius = radius;
        this->color = color;
    }
    void print()
    {
        cout << "color: " << color << ", radius: " << radius << endl;
    }
};

int main()
{
    Ball def;
    def.print();
 
	Ball black("black");
	black.print();
	
	Ball thirty(30.0);
	thirty.print();
	
	Ball blackThirty("black", 30.0);
	blackThirty.print();
 
    return 0;
}