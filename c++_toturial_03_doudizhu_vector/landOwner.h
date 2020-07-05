#ifndef LANDOWNER_H
#define LANDOWNER_H

#include <iostream>
#include <vector>
#include <iterator> 
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class landOwner
{
private:
    /* data */
    string  m_NickName;
    string  m_Sex;
    int     m_Gold;
    long    m_Exp;
    vector<int> packCards;       //默认的一副牌，从１－５４
    vector<int> surplusCards;    //摸牌后剩余的牌
    vector<int> currCards;       //当前玩家的手牌数组
    bool isContained(int);       //判断剩余牌中是否包含cardNum这个牌面
    void deleteCard(vector<int>&, int);  //从牌集合中删除某张牌
    string getColor(int);       //获得花色
    string getValue(int);       //获得牌面
public:
    landOwner(/* args */);
    landOwner(string);
    landOwner(string, string, int, long);

    ~landOwner();
    void setNickName(string name){ m_NickName = name; };
    string getNickName(){ return m_NickName; };
    void setSex(string sex){ m_Sex = sex; };
    string getSex(){ return m_Sex; };
    void setGold(int gold){ m_Gold = gold; };
    int getGold(){ return m_Gold; };
    void setExp(long Exp){ m_Exp = Exp; };
    long getExp(){ return m_Exp; };
    
    void showIofo();
    void touchCard(int cardCount);
    void initCards();       //初始化packCards,surplusCards,currCards
    void showCards(const vector<int>&);       //显示集合中的牌面

    int test(int );
};

#endif