#include "landOwner.h"
#include <unistd.h>

landOwner::landOwner(/* args */)
{
    setNickName("默认地主");
    setSex("保密");
    setGold(1000);
    setExp(0);
    cout << "landOwner()" << endl;
    initCards();
}

landOwner::landOwner(string nickname) : m_NickName(nickname)
{
    setSex("保密");
    setGold(1000);
    setExp(0);
    cout << "landOwner(string nickname)" << endl;
    initCards();
}

landOwner::landOwner(string nickname, string sex, int gold, long exp) : 
m_NickName(nickname),
m_Sex(sex),
m_Gold(gold),
m_Exp(exp)
{

    cout << "landOwner(string nickname, string sex, int gold, long exp)" << endl;
    initCards();
}

void landOwner::showIofo()
{
    cout << "昵称：" << getNickName() << endl;
    cout << "性别：" << getSex() << endl;
    cout << "金币：" << getGold() << endl;
    cout << "经验：" << getExp() << endl;
}

//初始化packCards,surplusCards,currCards
void landOwner::initCards()//初始化packCards,surplusCards,currCards
{
    //生成默认的一副扑克牌
    packCards.clear();
    surplusCards.clear();
    currCards.clear();
    for(int i = 0; i < 54; i++){
        packCards.push_back(i + 1);
        surplusCards.push_back(packCards.at(i));
    }
    showCards(surplusCards);
}

void landOwner::showCards(const vector<int>& cards){
    /*c语言写法
    for(int i = 0; i < cards.size(); i++){
            cout << cards[i] << ", ";
    }
    cout << endl;
    */

   /*使用迭代器
    for(vector<int>::const_iterator iter = cards.begin(); iter != cards.end(); iter++ ){
        cout << *iter << ", ";
    }
    cout << endl;*/
    /*使用ｃ++11的类型判断
    for(vector<int>::const_iterator iter = cards.begin(); iter != cards.end(); iter++ ){
        cout << *iter << ", ";
    }
    cout << endl;*/

    //for 区间遍历　－　cards
    for(auto card : cards){
        cout << card << ":" << getColor(card) << "-" << getValue(card) << ", ";
    }
    cout << endl;
    //使用算法方式，将容器的内容复制到cout绑定的迭代器中
    //#include <iterator> #include <algorithm>
    // copy(cards.cbegin(), cards.cend(), ostream_iterator<int>(cout, ", "));
    // cout << endl;
}

void landOwner::touchCard(int cardCount){
    //随机生成一张剩余牌集合中有的牌，添加到currCards集合中，从surplus中删除掉这张牌
    // srand(time(NULL));
    for(int i = 0; i < cardCount; i++){
        int randIndex = rand() % 54;    //0-53之间
        if(isContained(packCards[randIndex])){      //1-54
            currCards.push_back(packCards[randIndex]);      //
            //再剩余牌集合中删除这张牌
            deleteCard(surplusCards, packCards[randIndex]);
        }else{
            i--;        //重新摸牌
        }
    }
    cout << "<地主摸牌>－当前手牌如下" << endl;
    showCards(currCards);
    // for(int i = 0; i < currCards.size(); i++){
    //     if( currCards[i] == 1 )
    //         cout << "摸到了第2张牌" << endl;
    // }
     for(auto card : currCards){
          if( card == 10 )
            cout << "摸到了第2张牌" << endl;     
     }
    cout << "<地主摸牌后>－剩余牌面如下" << endl;
    showCards(surplusCards);

}

int landOwner::test(int cardNum){

    for(int i = 0; i < currCards.size(); i++){
        if( currCards[i] == cardNum )
            return 1;
    }
    //  for(auto card : currCards){
    //       if( card == cardNum )
    //         return 1;
    //  }
     return 0;
}

bool landOwner::isContained(int cardNum){
    /*普通做法
    for(int i = 0; i < surplusCards.size; i++){
        if()
    }*/
    //查找
    vector<int>::iterator iter = find(surplusCards.begin(), surplusCards.end(), cardNum);
    return iter != surplusCards.end();      //要是迭代到最后，则没有找到这张牌，表示已经发出去，返回０
}

void landOwner::deleteCard(vector<int>& cardVec, int card){
    /*普通做法
    for(auto iter = cardVec.begin() ; iter != cardVec.end(); ){
        if(*iter == card){      //如果找到，就删除元素
            iter = cardVec.erase(iter);
        }else{
            ++iter;         //继续判断下一个元素是否相同
        }
    }*/
    //使用算法删除
    auto iter = find(cardVec.begin(), cardVec.end(), card);
    if(iter != cardVec.end()){
        cardVec.erase(iter);
    }
}


string landOwner::getColor(int card){
    if(card == 53)  return "小王";
    if(card == 54)  return "大王";
    string color[4] = {
        "红桃",
        "黑桃",
        "方块",
        "梅花"
    };
    return color[(card - 1) / 13];

}

string landOwner::getValue(int card){
    if(card == 53)  return "Black Joker";
    if(card == 54)  return "Red Joker";
    string value[] = {
        "A",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "10",
        "J",
        "Q",
        "K"
    };
    return value[(card - 1) % 13];
}
/*
1 2 3 4 5 6 .... 13
14 ..............26
27 ..............39
40 ..............52
*/
landOwner::~landOwner()
{
    cout << getNickName() << "被释放" << endl;
}
