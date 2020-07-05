#ifndef ARCHMAGE_H
#define ARCHMAGE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "hero.h"

class Archmage : public hero
{
private:
	int m_MagicalAttack;


public:
	Archmage();
	Archmage(const string& name);


	void Move() override;
	void BiuBiuBiu();

	void Teleportation();

};
#endif
