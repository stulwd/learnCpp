#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "hero.h"
#include "Archmage.h"

class Warrior : public hero			//公有继承
{
private:
	int m_physicalAttack;


public:
	Warrior();
	Warrior(const string&, int phyAttack);

	//在c++11版本后，为了体现子类重写父类方法，在子类方法后加override关键字
	void Move() override; 		
	void HiSunZi();

	//如果攻击方式只支持战士，就意味着随着英雄类型的升级增加，战士的攻击方法也变得复杂
	// void XiaoQuanQuan(Warrior& );
	// void XiaoQuanQuan(Archmage& );

	void XiaoQuanQuan(hero& );
};
#endif
