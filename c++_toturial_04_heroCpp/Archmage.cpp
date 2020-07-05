#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Archmage.h"

Archmage::Archmage(): hero("默认法师")
{

}

Archmage::Archmage(const string& name): hero(name)
{

}

void Archmage::Move(){
    cout << getNickName() << "法师正在靠近" << endl;
}

void Archmage::BiuBiuBiu()
{
}

void Archmage::Teleportation()
{
}
