// // Вспомним все типы инициализации, которые поддерживает язык C++: прямая инициализация, uniform-инициализация и копирующая инициализация.

// #include <iostream>
// #include <cassert>
// using namespace std;

// class Drob
// {
// private:
//     int m_a, m_b;
// public:
//     Drob(int a = 0, int b = 1) : m_a(a), m_b(b)
//     {
//         assert(b !=0);
//     }
//     friend ostream& operator<<(ostream &out, const Drob& d);
// };

// ostream& operator<<(ostream &out, const Drob& d)
// {
//     out << d.m_a << "/" << d.m_b << endl;
// }

// int main()
// {
//     int a(7); // прямая инициализация целочисленной переменной
//     Drob sixSeven(6, 7); // прямая инициализация объекта класса Drob, вызывается конструктор Drob(int, int)

//     int a { 7 }; // uniform-инициализация целочисленной переменной 
//     Drob sixSeven {6, 7}; // uniform-инициализация объекта класса Drob, вызывается конструктор Drob(int, int)


//     int a = 7; // копирующая инициализация целочисленной переменной
//     Drob eight = Drob(8); // копирующая инициализация объекта класса Drob, вызывается Drob(8, 1)
//     Drob nine = 9; // копирующая инициализация объекта класса Drob. Компилятор будет искать способ конвертации 9 в объект класса Drob, что приведет к вызову конструктора Drob(9, 1)
// }

// #include <cassert>
// #include <iostream>
 
// class Drob
// {
// private:
//     int m_numerator;
//     int m_denominator;
 
//     // Конструктор копирования
//     Drob(const Drob &drob) :
//         m_numerator(drob.m_numerator), m_denominator(drob.m_denominator)
//         // Примечание: Мы имеем прямой доступ к членам объекта drob, поскольку мы сейчас находимся внутри класса Drob
//     {
//         // Нет необходимости выполнять проверку denominator здесь, так как эта проверка уже осуществляется в конструкторе класса Drob
//         std::cout << "Copy constructor worked here!\n"; // просто, чтобы показать, что это работает
//     } 
// public:
//     // Конструктор по умолчанию
//     Drob(int numerator=0, int denominator=1) :
//         m_numerator(numerator), m_denominator(denominator)
//     {
//         assert(denominator != 0);
//     }
 

//     friend std::ostream& operator<<(std::ostream& out, const Drob &d1);
// };
 
// std::ostream& operator<<(std::ostream& out, const Drob &d1)
// {
// 	out << d1.m_numerator << "/" << d1.m_denominator;
// 	return out;
// }
 
// int main()
// {
// 	Drob sixSeven(6, 7); // прямая инициализация объекта класса Drob, вызывается конструктор Drob(int, int)
// 	// Drob dCopy(sixSeven); // прямая инициализация - какой конструктор вызывается здесь?
// 	// std::cout << dCopy << '\n';

//     // создание анониммого обьекта, потом вызвать коструктор копирования
// 	Drob sixSeven(Drob(6, 7));
//     // но компилятор может изменить на вызов
//     // Drob sixSeven(6, 7);
//     // // Этот процесс называется элизией.
// }

#include <iostream>
using namespace std;
int main()
{
    int a = 2, b = 3, c = 4;
    a = b = c;
    cout << a << " " << b << " " << c << endl;
    return 0;

}
