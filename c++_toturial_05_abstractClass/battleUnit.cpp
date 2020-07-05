#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "battleUnit.h"


battleUnit::battleUnit()
{
}

battleUnit::battleUnit(const string& name) : name(name)
{
    maxHp = 100;
    currHp = 100;
    attDistance = 100;
    position.setX(0);
    position.setY(0);
    cout << "调用了父类构造" << endl;
}

// 我们可以提供基类的纯虚方法的默认实现
void battleUnit::fight(battleUnit& other){
	cout << this->name << "正在攻击另一个作战单位" << other.name << endl;       //此处other可以直接访问私有成员
}


void battleUnit::move(int x, int y){
	position.setX(x);
	position.setY(y);
}