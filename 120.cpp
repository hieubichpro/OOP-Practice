// #include <iostream>
// #include <cassert>
// using namespace std;
// class Massiv
// {
// private:
//     int *m_arr;
//     int m_len;
// public:
//     Massiv(int len)
//     {
//         assert(len > 0);
//         m_arr = new int[len];
//         m_len = len;
//     }
//     ~Massiv()
//     {
//         delete[] m_arr;
//         cout << "Delete all allocated memory" << endl;
//     }
//     void setValue(int index, int value) {m_arr[index] = value;}
//     int getValue(int index) {return m_arr[index];}
// };

// int main(void)
// {
//     Massiv m(10);
//     for(int i = 0; i < 10; i++)
//         m.setValue(i, i + 1);
//     for (int i = 0; i < 10; i++)
//         cout << m.getValue(i) << " ";
//     cout << endl;
//     return 0;
// }
