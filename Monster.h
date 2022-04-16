#ifndef ALIEN_MONSTER_H
#define ALIEN_MONSTER_H

#include "Creature.h"
using std::vector;

struct tiles 
{
	int x;
	int y;
	int Width;
	int Height;
};

class Monster : public Creature {
protected:

	vector<tiles> moveVec;
	vector<tiles> attackVec;
	vector<tiles> fallVec;
	int attackTact;
	//int attackTact2;
	bool key;

	float boost;
	float timeBoost1;
	float boostHeight;
	int distanceToHero;
	bool onGround;

public:
	
	void DistanceToHero(int X);

	void Move();
	void Attack() override;
	Monster(String file, float speedX, int windowWidth, int windowHeight);
	Monster();
	void IncrementTime();
	~Monster();
};



#endif //ALIEN_MONSTER_H