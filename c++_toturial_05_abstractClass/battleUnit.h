#ifndef BATTLE_UNIT_H
#define BATTLE_UNIT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "point.h"

using namespace std;

class battleUnit
{
private:
	string name;

	int maxHp = 1;

	int currHp;


	int attDistance;
	
public:
	// 在一个类中，初始化另一个类的对象作为该类成员，构造方法如下，不能用()的形式，因为会与方法混淆
	point position = {1,2};			//不能写成　point position(1,2)的形式
	battleUnit();

	battleUnit(const string& name);

	virtual void fight(battleUnit& other) = 0;

	virtual void move(int x, int y) = 0;
	virtual void move(point& position) = 0;
	const string& getName(){return name;};

};

// 当有同名.cpp文件时，类的方法定义不能出现在.h中

#endif
