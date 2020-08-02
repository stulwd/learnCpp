#ifndef CONSTDEMO_H
#define CONSTDEMO_H

#include <iostream>

using namespace std;

//1.const修饰成员变量

void constDemo1(){
    //const修饰普通变量时
    int num1 = 1024;
    const int num2 = num1;
    //assignment of read-only variable ‘num2’
    // num2 = 2048;
    
    //const修饰指针变量时：
    //1.如果只有一个const时，如果const位于*左侧：表示指针所指的数据是常量
    //，不能通过指针修改实际数据，指针本身是变量，可以指向其他内存单元
    const int* ptr1_num1 = &num1;
    ptr1_num1 = &num2;  //合法
    //*ptr1_num1 = 1234;  //不合法

    int * const ptr2_num1 = &num1;
    // ptr2_num1 = &num2;  //不合法
    *ptr2_num1 = 2345; //合法
    
    int * ptr3_num1 = &num1;
    // ptr3_num1 = &num2;  //不合法
    
    //2.如果只有一个const时，如果const位于*右侧：表示指针所指的数据是变量
    //，能通过指针修改实际数据，指针本身是常量，不能指向其他内存单元
    int * const ptr3_num1 = &num1;
    //ptr3_num1 = ptr2_num1;  //不合法
    *ptr3_num1 = 1234;
    //如果有两个const在*左右两侧，则指针和变量都不能修改

}

//2.const修饰函数参数
void constDemo2(const int& num){
    //num = 123;  //非法修改
}

class computer{
public:
    computer(int core){this->m_core = core;};
    ~computer(){ cout << this->m_core << "被释放" << endl;};
    void buy() const{};
    void buy(int core){

    };
    /*修改电脑的核心频率*/
    void setCore(int core){this->m_core = core;};
    int getCore() const{ return m_core;};
    const computer& getMax(const computer &com1, const computer &com2);
private:
    int m_core; //cpu主频

};

void constDemo3(const computer& computer){
    //const修饰引用时，不能修改引用对象的任何成员 - 好处是可以保护传递的参数：不需要一个新的参数副本（copy）
    // computer.buy(123);      //非法操作
    //传入的const对象不能调用非const成员函数（传入对象是静态的，意味着不能对对象的内容做修改操作，而没有被const修饰的成员函数中包含了修改操作），但是可以调用const修饰的成员函数
    computer.buy();         //合法操作  
    //使用const传递对象的引用时，可以起到不copy对象的目的（节省空间）
}

//3.const修饰返回值
//强调：使用const修饰引用类型的一个常见的原因是：提高效率
const computer& computer::getMax(const computer & com1, const computer &com2){
    if( com1.getCore() > com2.getCore()){
        return com1;
    }
    return com2;
}
//如果函数要返回局部对象，就直接返回这个对象（即副本），而不是返回对象的引用，因为局部变量在之后会被回收 
//在可以返回对象，也可以返回引用时，首选返回引用，因为效率高

//4.const修饰函数-说明函数不会修改成员变量的值
class testClass{
public:
    int value;
    void modifyValue() const{
        // value = 1111;       //非法操作
    };
};
#endif
