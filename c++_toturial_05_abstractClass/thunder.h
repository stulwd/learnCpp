#ifndef 雷神_H
#define 雷神_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "battleUnit.h"

class thunder : public battleUnit
{
    private:
    public:
        thunder();
        thunder(const string& );
        ~thunder();
        void move(int, int );
        void fight(battleUnit& target);
};
#endif
