#include "ArrayInt.h"

ArrayInt::ArrayInt(int len) : m_len(len)
{
    assert(len > 0 && "Длина должна быть больше нуля");
    m_array = new int[len];
}

ArrayInt::~ArrayInt()
{
    delete [] m_array;
}

void ArrayInt::erase()
{
    delete [] m_array;
    m_array = nullptr;
    m_len = 0;
}

int& ArrayInt::operator[](const int& idx)
{
    assert(idx >= 0 && idx < m_len);
    return m_array[idx];
}
void ArrayInt::reallocate(const int& new_size)
{
    assert(new_size >= 0);
    if (m_len == new_size)
        return;
    delete [] m_array;
    int *new_arr = new int[new_size];
    m_array = new_arr;
    m_len = new_size;
}
void ArrayInt::resize(const int& new_size)
{
    assert(new_size >= 0);
    if (m_len == new_size)
        return;
    int needToCopy = (new_size > m_len) ? m_len : new_size;
    int *new_arr = new int[new_size];
    for (int i = 0; i < needToCopy; i++)
        new_arr[i] = m_array[i];
    delete [] m_array;
    m_array = new_arr;
    m_len = new_size;
}

void ArrayInt::insertBefore(const int& idx, const int& value)
{
    assert(idx >= 0 && idx < m_len + 1);
    int *new_arr = new int[m_len + 1];
    for (int before = 0; before < idx; before++)
        new_arr[before] = m_array[before];

    new_arr[idx] = value;

    for (int after = idx + 1; after < m_len + 1; after++)
        new_arr[after] = m_array[after - 1];

    delete [] m_array;
    m_array = new_arr;
    m_len++;
}
void ArrayInt::insertAtBeginning(const int &value)
{
    insertBefore(0, value);
}
void ArrayInt::insertAtEnd(const int& value)
{
    int *new_arr = new int[m_len + 1];
    for (int i = 0; i < m_len; i++)
        new_arr[i] = m_array[i];
    new_arr[m_len++] = value;
    delete [] m_array;
    m_array = new_arr;
}
void ArrayInt::remove(const int& idx)
{
    assert(idx >= 0 && idx < m_len);
    int *new_arr = new int[m_len - 1];

    for (int before = 0; before < idx; before++)
        new_arr[before] = m_array[before];

    for (int after = idx; after < m_len - 1; after++)
        new_arr[after] = m_array[after + 1];
    
    delete [] m_array;
    m_array = new_arr;
    m_len--;
}

int ArrayInt::getLength() const
{
    return m_len;
}