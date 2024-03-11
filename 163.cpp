// #include <iostream>
// using namespace std;

// class Parent
// {
// public:
//     virtual string getName() {return "Parent";}
// };

// class Child : public Parent
// {
// public:
//     virtual string getName() {return "Child";}
// };

// int main()
// {
//     Child child;
//     Parent &p = child;
//     cout << p.getName() << endl;
// }

#include <iostream>
 
class A
{
public:
    virtual const char* getName() { return "A"; }
};
 
class B: public A
{
public:
    virtual const char* getName() { return "B"; }
};
 
class C: public B
{
public:
    virtual const char* getName() { return "C"; }
};
 
class D: public C
{
public:
    virtual const char* getName() { return "D"; }
};
 
int main()
{
    C c;
    A &rParent = c;
    std::cout << "rParent is a " << rParent.getName() << '\n';
 
    return 0;
}

// Вызов rParent.GetName() приводит к вызову A::getName(). Однако, поскольку A::getName() является виртуальной функцией, то компилятор ищет «наиболее» дочерний метод между A и C. В этом случае — это C::getName().

// Обратите внимание, компилятор не будет вызывать D::getName(), поскольку наш исходный объект был класса C, а не класса D, поэтому рассматриваются методы только между классами A и C.
// =>> Результат  ----- rParent is a C