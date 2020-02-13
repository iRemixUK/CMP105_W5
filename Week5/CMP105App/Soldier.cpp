#include "Soldier.h"
Soldier::Soldier()
{
	speedx = 0.f;
	// Setup walk animation
	walk.addFrame(sf::IntRect(8, 67, 50, 50));
	walk.addFrame(sf::IntRect(66, 67, 50, 50));
	walk.addFrame(sf::IntRect(124, 67, 50, 50));
	walk.addFrame(sf::IntRect(182, 67, 50, 50));
	walk.addFrame(sf::IntRect(240, 67, 50, 50));
	walk.addFrame(sf::IntRect(298, 67, 50, 50));
	walk.addFrame(sf::IntRect(356, 67, 50, 50));
	walk.addFrame(sf::IntRect(414, 67, 50, 50));
	walk.setFrameSpeed(1.f / 10.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());

}

void Soldier::update(float dt)
{
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::D))
	{
		walk.setFlipped(false);
		speedx = 200.f;
		currentAnimation = &walk;
		setTextureRect(currentAnimation->getCurrentFrame());
	}

	if (input->isKeyDown(sf::Keyboard::A))
	{
		walk.setFlipped(true);
		speedx = -200.f;
		currentAnimation = &walk;
		setTextureRect(currentAnimation->getCurrentFrame());
	}
}

Soldier::~Soldier()
{

}

float Soldier::getSpeedX()
{
	return speedx;
}