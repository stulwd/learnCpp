#ifndef VIRTUALPOINTDEMO_H
#define VIRTUALPOINTDEMO_H

#include <iostream>
#include <string>

using namespace std;

/**
 * 演示虚函数的实现原理 - 体会虚函数表中的地址变化
 * */

/**
 * 对象内存结构：
 *                            base object                    base virFunction table
 *                  |===============================|   |=============================|
 *                  |   virFunction table address   |-> |  virFunction1 address:0x001 | -> virtual base::function1();   
 *  base elements:  |-------------------------------|   |  virFunction2 address:0x002 | -> virtual base::function2();
 *                  |        public members         |   |  virFunction3 address:0x003 | -> virtual base::function3();
 *                  |        private members        |   |=============================|
 *                  |-------------------------------|
 *  functions:(not  |    virtual function1(){...};  |
 *   contained in   |    virtual function2(){...};  |
 *   object memory) |    virtual function3(){...};  |
 *                  |===============================|       
 *      
 *                            son object                      son virFunction table
 *                  |===============================|   |=============================|
 *                  |   virFunction table address   |-> |  virFunction1 address:0x001 | -> virtual base::function1();
 *  base elements:  |-------------------------------|   |  virFunction2 address:0x004 | -> virtual son::function2();
 *                  |        public members         |   |  virFunction3 address:0x003 | -> virtual base::function3();
 *                  |        private members        |   |=============================|
 *  son elements:   |-------------------------------|
 *                  |        public members         |   
 *                  |        private members        |       
 *                  |-------------------------------|
 *  functions:(not  |    virtual function2(){...};  |
 *   contained in   |===============================|
 *   object memory)            
 * */
class base
{
private:
    /* data */
    long basemember;         //基类中的私有整形成员
public:
    long baseMemberPub;
    base(){basemember = 4321;baseMemberPub = 8765;}
    ~base();

    virtual void baseVirtual1(){
        cout << "基类中的虚函数版本１" << endl;
    }
    virtual void baseVirtual2(){
        cout << "基类中的虚函数版本2" << endl;
    }
    virtual void baseVirtual3(){
        cout << "基类中的虚函数版本3" << endl;
    }
    
};

class son : public base
{
private:
    /* data */
    long sonMember;
public:
    long sonMemberPub;
    son(/* args */){ sonMember = 1234;sonMemberPub = 5678;};
    ~son();
    virtual void baseVirtual2(){
        cout << "派生类中的虚函数版本2" << endl;
    }
};


son::~son()
{
}


base::~base()
{
}



#endif