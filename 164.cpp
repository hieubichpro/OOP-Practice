#include <iostream>
//override
class A
{
public:
	virtual const char* getName1(int x) { return "A"; }
	virtual const char* getName2(int x) { return "A"; }
	virtual const char* getName3(int x) { return "A"; }
};
 
class B : public A
{
public:
	virtual const char* getName1(short int x) override { return "B"; }  // ошибка компиляции, метод не является переопределением
	virtual const char* getName2(int x) const override { return "B"; }  // ошибка компиляции, метод не является переопределением
	virtual const char* getName3(int x) override { return "B"; }  // всё хорошо, метод является переопределением A::getName3(int)
 
};
 
int main()
{
	return 0;
}

//final
class A
{
public:
	virtual const char* getName() { return "A"; }
};
 
class B : public A
{
public:
	// Заметили final в конце? Это означает, что метод переопределить уже нельзя
	virtual const char* getName() override final { return "B"; } // всё хорошо, переопределение A::getName()
};
 
class C : public B
{
public:
	virtual const char* getName() override { return "C"; } // ошибка компиляции: переопределение метода B::getName(), который является final
};

//запретить наследование определенного класса
class A
{
public:
	virtual const char* getName() { return "A"; }
};
 
class B final : public A // обратите внимание на модификатор final здесь
{
public:
	virtual const char* getName() override { return "B"; }
};
 
class C : public B // ошибка компиляции: нельзя наследовать final-класс
{
public:
	virtual const char* getName() override { return "C"; }
};