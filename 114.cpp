#include <iostream>
using namespace std;
// class Numbers
// {
//     int m_a, m_b, m_c;
// public:
//     void setValues(int a, int b, int c)
//     {
//         this->m_a = a;
//         this->m_b = b;
//         this->m_c = c;
//     }

//     void print()
//     {
//         cout << "<" << m_a << ", " << m_b << ", " << m_c << ">" << endl;
//     }

//     bool isEqual( const Numbers &b)
//     {
//         return (m_a == b.m_a) && (m_b == b.m_b) && (m_c = b.m_c);
//     }
// };
#define N 10
class Stack
{
    int arr[N];
    int len = 0;
public:
    void reset()
    {
        len = 0;
    }
    bool push(const int& num)
    {
        if (len == N)
            return false;
        arr[len++] = num;
        return true;
    }
    int pop()
    {
        if (len == 0)
            return -1;
        return arr[--len];
    }
    void print()
    {
        cout << "( ";
        for (int i = 0; i < len; i++)
            cout << arr[i] << " ";
        cout << " )" << endl;
    }
};
int main()
{
    // Numbers point1;
    // point1.setValues(3.0, 4.0, 5.0);
 
    // Numbers point2;
    // point2.setValues(3.0, 4.0, 5.0);
 
    // if (point1.isEqual(point2))
    //     std::cout << "point1 and point2 are equal\n";
    // else
    //     std::cout << "point1 and point2 are not equal\n";
 
    // Numbers point3;
    // point3.setValues(7.0, 8.0, 9.0);
 
    // if (point1.isEqual(point3))
    //     std::cout << "point1 and point3 are equal\n";
    // else
    //     std::cout << "point1 and point3 are not equal\n";
	Stack stack;
	stack.reset();
 
	stack.print();
 
	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();
 
	stack.pop();
	stack.print();
 
	stack.pop();
	stack.pop();
 
	stack.print();
    return 0;
}