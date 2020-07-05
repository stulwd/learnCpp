#ifndef POINT_H
#define POINT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

using namespace std;

class point
{
private:
	int x;

	int y;


public:
	int getX();

	int getY();

	void setX(int value);

	void setY(int value);

	friend ostream& operator<<(ostream& out, const point& p){
		out << "(" << p.x << "," << p.y << ")" << endl;	
		//out << "(" << p.getX() << "," << p.getY() << ")" << endl; //因为ｐ是const类型，所以不允许调用方法，除非给方法加上const关键字
	};

	point();

	point(int x, int y);
	

};
#endif
