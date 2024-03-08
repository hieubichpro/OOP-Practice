#include <iostream>
#include <cassert>
using namespace std;

class Average
{
private:
    int32_t m_sum;
    int8_t m_cnt;
public:
    Average(int sum = 0, int cnt = 0) : m_sum(sum), m_cnt(cnt) {}
    Average& operator+=(const int& num)
    {
        m_sum += num;
        m_cnt++;
        return (*this);
    }
    friend ostream& operator<<(ostream &out, const Average &avg);
};

ostream& operator<<(ostream& out, const Average &avg)
{
    assert(avg.m_cnt != 0);
    out << avg.m_sum / avg.m_cnt << endl;
    return out;
}

int main()
{
	Average avg;
	
	avg += 5;
	std::cout << avg << '\n'; // 5 / 1 = 5
	
	avg += 9;
	std::cout << avg << '\n'; // (5 + 9) / 2 = 7
 
	avg += 19;
	std::cout << avg << '\n'; // (5 + 9 + 19) / 3 = 11
 
	avg += -9;
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9) / 4 = 6
 
	(avg += 7) += 11; // выполнение цепочки операций
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9 + 7 + 11) / 6 = 7
 
	Average copy = avg;
	std::cout << copy << '\n';
 
	return 0;
}