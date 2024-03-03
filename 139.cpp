#include <iostream>
using namespace std;

class Mystring
{
private:
    string my_str;
public:
    Mystring(string str = "") : my_str(str) {}
    string operator()(const int &idx, const int& len)
    {
        string res;
        for (int i = 0; i < len; i++)
            res += my_str[idx + i];
        return res;
    }
};

int main()
{
	Mystring string("Hello, world!");
	std::cout << string(7, 6); // начинаем с 7-го символа (индекса) и возвращаем следующие 6 символов
 
	return 0;
}