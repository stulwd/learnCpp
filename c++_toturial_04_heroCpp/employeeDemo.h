#ifndef EMPLOYEEDEMO_H
#define EMPLOYEEDEMO_H

#include <iostream>

using namespace std;

/**
 * 虚析构函数
 * */
class employee
{
private:
    /* data */
    char *name;
public:
    employee(/* args */);
     ~employee();
};

employee::employee(/* args */)
{
    // name = (char*)malloc(sizeof(char) * 20);   //　用free()释放
    name = new char[20];    //释放需要delete
    cout << "已分配２０字节空间" << endl;
}

employee::~employee()
{
    cout << "释放已分配的内存空间" << endl;
    delete name;
}

class admin : public employee
{
private:
    /* data */
public:
    admin(/* args */);
    ~admin();
};

/** 隐式调用父类默认构造 */
admin::admin(/* args */)
{
    cout << "调用派生类admin的构造" << endl;
}


/** 隐式调用父类默认析构 */
admin::~admin()
{
    cout << "派生对象admin析构函数" << endl;
}


#endif