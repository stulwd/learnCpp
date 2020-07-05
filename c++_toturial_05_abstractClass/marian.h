#ifndef MARIAN_H
#define MARIAN_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "battleUnit.h"

class marian : public battleUnit
{
public:
	marian();

	marian(const string& name);

	//此处必须重写基类中所有的虚函数方法，子类才能不是抽象类
	void fight(battleUnit& other) override;
	void move(int x, int y){
		battleUnit::move(x,y);
		cout << "陆战队员接到命令，前往目标点：" << position;
	};
	void move(point& position){};

};
#endif
