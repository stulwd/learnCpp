#ifndef SIEGE_TANK_H
#define SIEGE_TANK_H

#include "battleUnit.h"

class siegeTank : public battleUnit
{
private:
    /* data */
public:
    siegeTank(/* args */){};
    siegeTank(const string& name) : battleUnit(name) {} ;
    void fight(battleUnit& other) override {};
    void move(int x, int y) override{
        battleUnit::move(x, y);             //这里同样会传入子类this指针
        cout << "工程坦克" << getName() << "收到移动命令：" << position << endl; //此处position重载了运算符<<,所以可以直接打印
    }
    void move(point& position){};
    ~siegeTank(){};
};


#endif