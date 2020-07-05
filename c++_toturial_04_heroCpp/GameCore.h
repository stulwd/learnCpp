#ifndef GAMECORE_H
#define GAMECORE_H

#include <iostream>
#include <string>
#include <vector>
#include "hero.h"
#include "Warrior.h"
#include "Archmage.h"

using namespace std;

/**
 * 游戏引擎/游戏业务/游戏核心类
 * */
class GameCore
{
private:
    /* data */
public:
    GameCore(/* args */);
    ~GameCore();

    // //重载多态：函数名相同，参数列表不同
    // //静态多态或编译时多态
    // //定义一个函数，用来移动游戏角色
    // void moveRole(Warrior& warrior){
    //     warrior.Move();         //实际上调用传入战士的移动方法
    // }
    // void moveRole(Archmage& archmage){
    //     archmage.Move();         //实际上调用传入战士的移动方法
    // }

    // void test(int[]){}
    // void moveRole(/*Warrior warriors[]*/vector<Warrior*> vecWarrior){
    //     for(Warrior* warrior : vecWarrior){
    //         warrior->Move();
    //     }
    // }

    /**
     * 为了能够让同一个函数操作不同类型的子类对象，所以我们把参数类型定义为基类对象
     * */
    void moveRole(hero& hero){
        hero.Move();            //统一调用英雄的方法；
    }

};

GameCore::GameCore(/* args */)
{
}

GameCore::~GameCore()
{
}

#endif