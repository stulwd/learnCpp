#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>

#include "battleUnit.h"
using namespace std;

class commander                 //指挥官类
{
private:
    /* data */
public:
    commander(/* args */);

    void move(vector<battleUnit*> units, int x, int y){
        for(auto unit : units){
            unit->move(x,y);
        }
    }
    ~commander();
};

commander::commander(/* args */)
{
}

commander::~commander()
{
}


#endif 