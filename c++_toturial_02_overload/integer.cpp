#include "integer.h"

integer::integer(/* args */) : m_value(0)
{
}

//友元函数不需要域运算符
const integer operator+(int intValue, const integer& other)
{
        //使用友元方式重载＋运算符，实现ｉｎｔ和ｉｎｔｅｇｅｒ类型相加
        return integer(intValue + other.m_value);
}

ostream& operator<<(ostream& out, const integer& num)
{
        out << num.m_value;
        return out;
}
istream& operator>>(istream& in,  integer& num)
{
        cout << "请输入一个帧数：";
        in >> num.m_value;
        return in;
}
integer::~integer()
{
}
