#include "landOwnerV2.h"

landOwnerV2::landOwnerV2(){

}

landOwnerV2::~landOwnerV2(){

}

landOwnerV3::landOwnerV3(){

}

landOwnerV3::~landOwnerV3(){

}

landOwnerV4::landOwnerV4(/* args */)
{
    _name = "默认地主";
    _score = 0;
    //将用户的手牌数组初始化为０
    memset(cards, 0, sizeof(cards));
    cout << "landOwner4的无参（默认）构造被调用" << endl;

    cout << "初始化的结果如下：" << endl;
    cout << "_name: " << _name << endl;
    cout << "_score：" << _score << endl;
    cout << "手牌数组:";
    for( int i = 0; i < sizeof(cards) / sizeof(cards[0]); i++){
        cout << cards[i] << ",";
    }
    cout << endl;

}

landOwnerV4::~landOwnerV4()
{
}
//实现摸牌方法
void landOwnerV2::TouchCard(int cardCount){
    //一般使用默认构造初始化成员变量
    cout << name <<  "摸了" <<  cardCount << "张牌" << endl;    
    
}


void landOwnerV3::ShowScore(){
    cout << name <<  "得了" <<  score << "分" << endl;        
}