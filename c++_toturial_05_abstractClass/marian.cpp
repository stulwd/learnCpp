#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "marian.h"


marian::marian()
{
}

marian::marian(const string& name):battleUnit(name)
{

}


void marian::fight(battleUnit& other){
    cout << "陆战队员" << this->getName() << "正在攻击敌人" << other.getName() << endl;

    //在子类中调用父类的同名方法：(这里同样会传入this指针)
    battleUnit::fight(other);
}