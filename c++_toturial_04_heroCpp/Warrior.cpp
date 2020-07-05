#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Warrior.h"


Warrior::Warrior() : hero("默认战士", 1, 100, 100)
{

}
Warrior::Warrior(const string& nickname, int phyAttack) : hero(nickname, 1, 100, 100), m_physicalAttack(phyAttack)
{

}


void Warrior::HiSunZi()
{
}

void Warrior::Move(){
    //派生类中不能直接访问或调用基类的private成员，但可访问protected成员
    cout << "战士" << this->getNickName() << "背着一大堆近战武器正在赶路中" << endl;
}


// void Warrior::XiaoQuanQuan(Warrior& other) 
// {
//     cout << this->getNickName() << "发出了一记：流星锤" << endl;
//     cout << other.getNickName() << "受伤倒地" << endl;
//     //对方掉血
//     other.setCurrLife(other.getCurrLife()-10);
// }

// void Warrior::XiaoQuanQuan(Archmage& other) 
// {
//     cout << this->getNickName() << "为了攻击法师，使了一招：野蛮冲撞" << endl;
//     cout << "法师" << other.getNickName() << "受到重创" << endl;
//     //对方掉血
//     other.setCurrLife(other.getCurrLife()-20);
// }

void Warrior::XiaoQuanQuan(hero& other){
    cout << this->getNickName() << "发出了一记：流星锤" << endl;
    cout << other.getNickName() << "受伤倒地" << endl;
    //对方掉血
    other.setCurrLife(other.getCurrLife()-10);
}
