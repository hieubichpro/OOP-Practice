#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert>

class ArrayInt
{
private:
    int *m_array;
    int m_len;
public:
    ArrayInt() : m_len(0), m_array(nullptr) {}
    ArrayInt(int len);
    ~ArrayInt();
    int getLength() const;
    void erase();
    int& operator[](const int& idx);
    void reallocate(const int& new_size);
    void resize(const int& new_size);

    void insertBefore(const int& idx,const int& value);
    void insertAtBeginning(const int &value);
    void insertAtEnd(const int& value);
    void remove(const int& idx);
};

#endif