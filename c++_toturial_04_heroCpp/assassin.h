#ifndef ASSASSIN_H
#define ASSASSIN_H

#include <iostream>
#include <string>
#include "hero.h"
/**
 * 体会程序是如何升级的
 * 假设游戏需要增加一个新的职业：刺客，但是核心业务类不能随便修改
 * */

class assassin : public hero
{
private:
    /* data */
    int m_power;
public:
    assassin(/* args */);
    assassin(const string& nickName, int power):hero(nickName), m_power(power){}
    ~assassin();

    //子类虽然不能访问父类private属性，但是不意味着子类没有这个属性
    void Move() override{
        cout << "隐藏在黑暗中的刺客" << this->getNickName() << "正偷偷潜入一座宫殿" << endl;
    }
};

assassin::assassin(/* args */)
{
}

assassin::~assassin()
{
}


#endif