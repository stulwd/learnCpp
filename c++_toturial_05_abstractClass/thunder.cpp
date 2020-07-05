#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "thunder.h"


thunder::thunder():battleUnit("默认雷神"){

}

thunder::thunder(const string& name):battleUnit(name){

}

thunder::~thunder(){

}

void thunder::move(int x, int y){
    this->position.setX(x);
    this->position.setY(y);

    // battleUnit::move(x, y);
    
}

void thunder::fight(battleUnit& target){
    
}