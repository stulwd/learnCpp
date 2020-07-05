#ifndef HERO_H
#define HERO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

using namespace std;

class hero
{
private:
	
	string m_NickName;	
	
	int m_Level;

	int m_MaxLife;

	int m_CurrLife;

	int x;

	int y;


public:
	hero();
	hero(const string& name);
	hero(const string& name, int level);
	hero(const string& name, int level, int maxLife, int curLife);
	
	//在基类方法前加virtual关键字，则告诉编译器，这个方法需要子类重写
	virtual void Move();	//基类中的移动方法  

	friend ostream& operator<<(ostream& out, const hero&);

	/*GET*/
	const string& getNickName() const{
		return this->m_NickName;
	}
	int getLavel() const{return m_Level;};
	int getMaxLife() const{return m_MaxLife;};
	int getCurrLife() const{return m_CurrLife;};
	/*SET*/
	void setNickName(const string name){
		this->m_NickName = name;
	};
	void sestLavel(const int level){this->m_Level = level;};
	void setMaxLife(const int life){this->m_MaxLife = life;};
	void setCurrLife(const int life){this->m_CurrLife = life;};
};
#endif
