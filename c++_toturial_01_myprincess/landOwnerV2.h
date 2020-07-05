#ifndef LANDOWNERV2_H
#define LANDOWNERV2_H

#include <iostream>
#include <memory.h>

using namespace std;

class landOwnerV2
{
public:
    /* data */
    string name;
    long score;
    int cards[20];

public:
    landOwnerV2(/* args */);    //构造函数
    ~landOwnerV2();             //析构函数

    void TouchCard(int cardCount); //声明摸排方法
    void ShowScore();               //声明显示积分方法
};

class landOwnerV3
{
    //省略了private
    /* data */
    long score;
    int cards[20];
public:
    string name;
    landOwnerV3(/* args */);
    ~landOwnerV3();

    void TouchCard(int cardCount); //声明摸排方法
    void ShowScore();               //声明显示积分方法

    //使用方法实现对对成员变量的封装
    void setScore(long lscore){
        if(lscore < 0){
        //如果参数是非法
            score = 0;
        }
        else
        {
            score = lscore;
        }
    }
};

class landOwnerV4
{
private:
    /* data */
    string _name;
    long _score;
    int cards[20];
    string array[20];
public:
    landOwnerV4(/* args */);
    ~landOwnerV4();

    long getScore(){ return _score; }
    void setScore( long lScore){
        if(lScore < 0)  _score = 0;
        else            _score = lScore;
    }
    string getName(){return _name; }
    void setName(string lName){
        _name = lName;
    }

};






#endif