#include <iostream>
using namespace std;

class Car
{
private:
    string m_name;
    string m_company;
public:
    Car(string name = "", string company = "") : m_name(name), m_company(company) {}
    friend bool operator==(const Car &c1, const Car &c2);
    friend bool operator!=(const Car &c1, const Car &c2);
};

    bool operator==(const Car &c1, const Car &c2)
    {
        return (c1.m_name == c2.m_name && c1.m_company == c2.m_company);
    }
    bool operator!=(const Car &c1, const Car &c2)
    {
        return !(c1 == c2);
    }
// все операторы как > < >= <= могут перегрузить
int main(void)
{
    Car c1("aa", "bb");
    Car c2("aa", "bb");
    if (c1 == c2)
        cout << "1" << endl;
    else
        cout << "2" << endl;
    return 0;
}