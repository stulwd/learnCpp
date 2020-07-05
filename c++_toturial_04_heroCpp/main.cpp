#include <iostream>
#include <vector>
#include "Warrior.h"
#include "teacher.h"
#include "GameCore.h"
#include "assassin.h"
#include "virtualPointDemo.h"
#include "employeeDemo.h"
using namespace std;

void heroTest();
void warriorTest();

void testconst(int& n){
    n = 12;
}
/**
 * 多态用一句话解释：父类指针指向子类对象
 * */
class A{
    private:
    //这种写法占２４字节
        int i;
        int j;
        // int j;
    public:
    virtual int f(){
        return 0;
    }
    virtual int f1(){
        return 0;
    }
};

class B: public A{

};

void virtualPointTest(){

    base base;
    
    long* baseAddress = (long*) &base;          //转换成长整形指针，方便待会的指针移动和转换
    cout << "基类对象地址：" << baseAddress << endl;

    long* virTablePtr = (long*)*(baseAddress + 0);
    cout << "虚函数表的地址(对象第一个成员值)：" << virTablePtr << endl;
    long i = *(baseAddress + 1);
    cout << "对象第二个成员值：" << i << endl;

    long* virFunctionPtr1 = (long*) *(virTablePtr + 0);
    cout << "虚函数表中第一个虚函数的地址：" << virFunctionPtr1 << endl;
    long* virFunctionPtr2 = (long*) *(virTablePtr + 1);
    cout << "虚函数表中第二个虚函数的地址：" << virFunctionPtr2 << endl;
    long* virFunctionPtr3 = (long*) *(virTablePtr + 2);
    cout << "虚函数表中第三个虚函数的地址：" << virFunctionPtr3 << endl;

    void(*baseVirtual1)() = (void(*)())virFunctionPtr1;
    baseVirtual1();
    void(*baseVirtual2)() = (void(*)())virFunctionPtr2;
    baseVirtual2();
    void(*baseVirtual3)() = (void(*)())virFunctionPtr3;
    baseVirtual3();

    cout << "--------- 派生类的内存信息如下 -------------" << endl;
    son son;
    long* sonAddress = (long*)&son;
    cout << "派生类对象地址：" << sonAddress << endl;
    virTablePtr = (long*)*(sonAddress + 0);
    cout << "派生类对象虚拟表地址：" << virTablePtr << endl;
    long sonEle1 = *(sonAddress+1);
    cout << "son对象第二个成员：" << sonEle1 << endl;
    long sonEle2 = *(sonAddress+2);
    cout << "son对象第三个成员：" << sonEle2 << endl; 


    virFunctionPtr1 = (long*) *(virTablePtr + 0);
    cout << "派生类虚函数表中第一个虚函数的地址：" << virFunctionPtr1 << endl;
    virFunctionPtr2 = (long*) *(virTablePtr + 1);
    cout << "派生类虚函数表中第二个虚函数的地址：" << virFunctionPtr2 << endl;
    virFunctionPtr3 = (long*) *(virTablePtr + 2);
    cout << "派生类虚函数表中第三个虚函数的地址：" << virFunctionPtr3 << endl;

    void(*sonVirtual1)() = (void(*)())virFunctionPtr1;
    sonVirtual1();
    void(*sonVirtual2)() = (void(*)())virFunctionPtr2;
    sonVirtual2();
    void(*sonVirtual3)() = (void(*)())virFunctionPtr3;
    sonVirtual3();
}

void employeeTest(){
    // employee* emp = new employee();
    // delete emp;
    admin* adm = new admin();
    delete adm;

    // 多态：基类指针指向派生类
    employee* emp = new admin;      //模拟了传参时自动类型转换，向上转换
    // 如果父类析构函数是非虚的析构，那么释放子类对象只会调用父类对象析构，不会调用子类析构  
    // 解决方案：将基类析构定义为虚析构
    delete emp;                     
}

int main(){

    virtualPointTest();
    employeeTest();
    cout << sizeof(base) << endl;
    A a; B b;
    cout << "sizeof(a)=" << sizeof(a) << endl;
    cout << "sizeof(b)=" << sizeof(b) << endl;
    string lwd = "1234ffdasfdasfdafdasfdsafdfdsafda4ffdasfdasfdafdasfdsafdfdsafdasfasdasdfsafdasfdassfd5";
    cout << &lwd << endl;
    string * ptr = &lwd;        //ｃ＋＋中string类型占用３２个字节
    cout << ptr << endl;
    cout << ptr+1 << endl;
    cout << ptr+2 << endl;
    cout << sizeof(lwd) << endl;

    // testconst(12);   //当函数接受参数为引用时，不能传入常量
    //heroTest();
    warriorTest();
    teacher t1("dfs");
    cout << t1.getName() << endl;
    cout << t1.getLength() << endl;

    //multimorphism
    hero hero("布衣");
    Warrior warrior1("吕布1", 50);
    Warrior warrior2("吕布2", 50);
    Warrior warrior3("吕布3", 50);
    Archmage archmage("甘道夫");

    GameCore gameCore;
    // // gameCore.moveRole(warrior1);
    // gameCore.moveRole(archmage);
    // vector<Warrior*> vecWarrior;
    // vecWarrior.push_back(&warrior1);
    // vecWarrior.push_back(&warrior2);
    // vecWarrior.push_back(&warrior3);
    // gameCore.moveRole(vecWarrior);
    gameCore.moveRole(hero);
    gameCore.moveRole(warrior1);            //如果基类中不调价virtual关键字
    gameCore.moveRole(archmage);            //编译器就会根据当前对象的类型调用类型定义的方法

    //不修改核心逻辑，直接传入新类型对象
    assassin assa("荆轲", 50);
    gameCore.moveRole(assa);
    return 0;
}

void heroTest(){
    hero hero1;
    cout << hero1;
    hero* hero2 = new hero("测试英雄2", 999, 5000, 5000);
    cout << *hero2;
    hero1.Move();
    hero2->Move();
}

void warriorTest(){
    Warrior warrior1;       //子类对象
    //情况1：派生类中如果不实现move方法，默认会调用基类实现
    //情况2：派生类实现了move方法（相当于覆盖了基类实现），那么就会调用子类实现
    warrior1.Move();
    cout << warrior1;

    hero * hero1 = new Warrior();    //基类指针指向派生类-标准多态
    //Warrior *warr = new hero();      //不能用子类指针指向基类
    hero1->Move();                   //思考：调用的基类实现
    delete hero1;
    Warrior Warrior3("诸葛达摩", 10);
    hero &refhero = Warrior3;                   //如果基类引用指向派生类对象，那么基类引用就不能调用派生类中定义的方法
    hero* ptrhero = &Warrior3;                  //如果基类指针指向派生类对象，那么基类引用就不能调用派生类中定义的方法
    Warrior& Warrior4 = (Warrior&)refhero;      //父类引用、指针需要强转成子类引用、指针
    //以上行为不能够逆操作

    cout << "\n\n\n";
    Warrior warrior2("吕布", 50);
    Warrior warrior3("张飞", 45);
    Archmage* archmage1 = new Archmage("貂蝉");
    warrior2.XiaoQuanQuan(warrior3);
    cout << warrior3;
    warrior2.XiaoQuanQuan(*archmage1);
    cout << *archmage1;
}