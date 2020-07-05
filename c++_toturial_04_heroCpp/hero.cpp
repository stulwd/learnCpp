#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "hero.h"

hero::hero():hero("默认英雄", 1, 100, 100)
{
    cout << "默认英雄已经构造！" << endl;
}
hero::hero(const string& name):hero(name, 1, 100, 100)
{
    cout << "一个参数英雄已经构造！" << endl;
}
hero::hero(const string& name, int level):hero(name, level, 100, 100)
{
  cout << "两个参数英雄已经构造！" << endl;
}
hero::hero(const string& name, int level, int maxLife, int curLife):
m_NickName(name),
m_Level(level),
m_MaxLife(maxLife),
m_CurrLife(curLife)
{
  cout << "四个参数英雄已经构造！" << endl;
}

void hero::Move(){
    cout << this->m_NickName << "奔跑在艾泽拉斯大路上..." << endl;
}

ostream& operator<<(ostream& out, const hero& hero){
    out << "昵称：" << hero.getNickName() << endl;
    out << "等级：" << hero.getLavel() << endl;
    out << "最大生命：" << hero.getMaxLife() << endl;
    out << "当前生命：" << hero.getCurrLife() << endl;
    return out;
}