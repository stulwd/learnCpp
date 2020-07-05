#include <iostream>

#include "battleUnit.h"
#include "marian.h"
#include "siegeTank.h"
#include "command.h"
using namespace std;

int main(){

    point position(1,2);
    //不能初始化一个抽象类
    //battleUnit btl;      
    marian marian1("巫妖王");
    marian marian2("死亡骑士");
    marian1.fight(marian2);
    marian1.move(99,88);
    cout << "巫妖王当前坐标：" << marian1.position.getX() << marian1.position.getY() << endl;
    siegeTank tank1("坦克一");
    tank1.move(90,20);

    vector<battleUnit*> units;
    units.push_back(&marian1);
    units.push_back(&marian2);
    units.push_back(&tank1);

    commander cmd;
    cout << "让指挥官移动多个单位" << endl;
    cmd.move(units, 90, 90);
    return 0;
}