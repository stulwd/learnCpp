#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>

using namespace std;

class integer
{
private:
    /* data */
    int m_value;
public:
    integer(/* args */);
    integer(int value) : m_value(value){};

    int intValue(){return m_value; };
    //重载+运算符
    //使用友元函数,
    friend const integer operator+(int intValue, const integer& other);
    //流运算符一般只能使用友元函数的方式重载
    //今后又可以直接重载流运算，以便封装某个对象的打印格式
    friend ostream & operator<<(ostream & out, const integer & num);
    friend istream & operator>>(istream & in, integer & num);
    const integer operator+(const integer other) const
    {
        integer result(this->m_value + other.m_value);
        return result;
    };
    const integer operator-(const integer other) const
    {
        integer result(this->m_value - other.m_value);
        return result;
    };
    const integer operator*(const integer other) const
    {
        integer result(this->m_value * other.m_value);
        return result;
    };
    const integer operator/(const integer other) const
    {
        integer result(this->m_value / other.m_value);
        return result;
    };
    const integer operator%(const integer other) const
    {
        integer result(this->m_value % other.m_value);
        return result;
    };
    // const integer& operator=(const integer other)
    // {
    //     this->m_value = other.m_value;
    //     return *this;
    // };


    //重载赋值符号
    ~integer();
};


#endif