#include "Zombie.h"

Zombie::Zombie()
{
	// Moving the object
	speedx = 0.f;

	// Setup walk animation
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());
}

void Zombie::update(float dt)
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

Zombie::~Zombie()
{

}

float Zombie::getSpeedX()
{
	return speedx;
}

