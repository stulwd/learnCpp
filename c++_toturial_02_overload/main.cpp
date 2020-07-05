#include <iostream>
#include "integer.h"
#include "constDemo.h"
#include "complex.h"
using namespace std;

void testInteger();
void testComplex();
const int* constTest(int& num)
{
    return &num;
}
void A();
void B();
void A(){
    B();
}
void B(){
    A();
}

int main(void){
    
    cout << "hello world!" << endl;
    testInteger();
    testComplex();
    constDemo1();
    int num2 = 22;
    constTest(num2);
    const int* num1 = constTest(num2);
    cout << "num1为：" << num1 << endl;

    computer* com1 = new computer(9750);
    computer* com2 = new computer(9770);
    const computer& com3 = com1->getMax(*com1, *com2);
    /**
     * 创建新的对象去接受const (type)&类型都是副本操作，只要不影响到传出的对象本身，都是合法的
     * 如下两行操作、
     * 但是第三行是非法的
     * */
    const computer com4 = com1->getMax(*com1, *com2); 
    computer com5 = com1->getMax(*com1, *com2); 
    //computer& com6 = com1->getMax(*com1, *com2);

    com3.getCore();         //如果com3是const类型，可以调用被const修饰的成员函数
    //com3.setCore(10750);    //如果com3是const类型，不可以调用没有被const修饰的成员函数
}

void testComplex(){
 //复数测试
    complex * comp1 = new complex();
    complex * comp2 = new complex(1, 2);
    cout << "com1：" << *comp1 << endl;
    cout << "com2：" <<  *comp2 << endl; 
    complex comp3 = complex(2,3);
    cout << "comp3:" << comp3 << endl;
    complex comp4 = *comp2 + comp3;
    cout << "comp4 = *comp2 + comp3 = " << comp4 << endl;
    comp4 = *comp2 - comp3;
    cout << "comp4 = *comp2 - comp3 = " << comp4 << endl;
    comp4 = (*comp2)*comp3;
    cout << "*comp2 乘 comp3 = " << comp4 << endl;
    complex comp5 = comp4;
    cout << "comp5 = comp4 = " << comp5 << endl;
    complex comp6 = comp5 = *comp1;
    cout << "comp6 = comp5 = *comp1 = " << comp5 << endl;
    cout << "请输入comp6的值：";
    cin >> comp6;
    cout << "comp6:" << comp6;
}

void testInteger(){
    integer int1(1024), int2(2048), int3;
    //int3 = int1.operator+(int2);  //编译器实际调用
    int3 = int1 + int2;             //重载后写法
    cout << "int1 + int2的结果" << int3.intValue() << endl;
    int3 = int1 - int2;             //重载后写法
    cout << "int1 - int2的结果" << int3.intValue() << endl;
    int3 = int1 * int2;             //重载后写法
    cout << "int1 * int2的结果" << int3.intValue() << endl;
    int3 = int1 / int2;             //重载后写法
    cout << "int1 / int2的结果" << int3.intValue() << endl;
    int3 = int1 % int2;             //重载后写法
    cout << "int1 % int2的结果" << int3.intValue() << endl;
    int3 = int1;
    int3 = 20;
    cout << int3 << endl;
    integer int4(100);
    int4 = int1 + 200;
    int4 = 200 + int1;
    cout << "int4:" << int4.intValue() << endl;
    cout << "int4:" << int4 << endl;        //重载了流运算符后可以直接打印int4
    cout << "123" << "123" << endl;
    cout << int4 << endl;           // <<重载定义：　std::ostream &operator<<(std::ostream &out, const integer &num)
                            // 其中，std::ostream &out为<<左值，　const integer &num为<<右值。返回值为ostream

    integer int5;
    cin >> int5;
    cout << "int5的值为：" << int5 << endl;
}