#include <iostream>
#include <cassert>
using namespace std;

class IntArray
{
private:
    int *m_array;
    int m_len;
public:
    IntArray(int len) : m_len(len)
    {
        assert(len > 0 && "len shoud be positive number");
        m_array = new int[8] {0};
    }
    IntArray(const IntArray& a)
    {
        m_len = a.m_len;
        m_array = new int[m_len];
        for (int i = 0; i < m_len; i++)
            m_array[i] = a.m_array[i];
    }
    ~IntArray()
    {
        delete [] m_array;
    }
    IntArray& operator=(const IntArray& a)
    {
        if (this == &a)
            return *this;
        delete[] m_array;
        m_len = a.m_len;
        m_array = new int[m_len];
        for (int i = 0; i < m_len; i++)
            m_array[i] = a.m_array[i];
        return (*this);
    }
    int& operator[](const int &idx)
    {
        return this->m_array[idx];
    }
    friend ostream& operator<<(ostream &out, const IntArray& a);
};

ostream& operator<<(ostream& out, const IntArray& a)
{
    for (int i = 0; i < a.m_len; i++)
        out << a.m_array[i] << " ";
    return out;
}

IntArray fillArray()
{
	IntArray a(6);
	a[0] = 6;
	a[1] = 7;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
    a[5] = 8;
 
	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';
 
	IntArray b(1);
	a = a;
	b = a;
 
	std::cout << b << '\n';
 
	return 0;
}