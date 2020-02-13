#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Soldier :
	public GameObject
{
public:
	Soldier();
	~Soldier();

	void update(float dt) override;
	float getSpeedX();

protected:
	Animation walk;
	Animation idle;
	Animation duck;
	Animation jump;
	Animation damage;
	Animation* currentAnimation;

private:
	float speedx;
};

