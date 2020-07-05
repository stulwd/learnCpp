#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "point.h"


int point::getX()
{
	return this->x;
}

int point::getY()
{
	return this->y;
}

void point::setX(int value)
{
	this->x = value;
}

void point::setY(int value)
{
	this->y = value;
}

point::point()
{
}

point::point(int x, int y):x(x), y(y)
{
}
