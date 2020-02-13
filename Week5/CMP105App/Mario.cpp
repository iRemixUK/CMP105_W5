#include "Mario.h"
Mario::Mario()
{
	// Moving the object
	speedx = 0.f;

	// Setup walk animation
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21)); 
	walk.addFrame(sf::IntRect(30, 0, 15, 21)); 
	walk.addFrame(sf::IntRect(45, 0, 15, 21)); 
	walk.setFrameSpeed(1.f / 3.f); 

	// Setup swim animation
	swim.addFrame(sf::IntRect(0, 21, 16, 20)); 
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20)); 
	swim.setFrameSpeed(1.f / 4.f); 

	// Setup duck animation
	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	duck.setFrameSpeed(1.f / 4.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());
}

void Mario::update(float dt)
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

	if (input->isKeyDown(sf::Keyboard::W))
	{
		swim.setFlipped(false);
		speedx = 200.f;
		currentAnimation = &swim;
		setTextureRect(currentAnimation->getCurrentFrame());
	}

	if (input->isKeyDown(sf::Keyboard::S))
	{
		swim.setFlipped(false);
		speedx = -200.f;
		currentAnimation = &swim;
		setTextureRect(currentAnimation->getCurrentFrame());
	}

	if (input->isKeyDown(sf::Keyboard::C))
	{
		speedx = 0.f;
		currentAnimation = &duck;
		setTextureRect(currentAnimation->getCurrentFrame());
	}
}

float Mario::getSpeedX()
{
	return speedx;
}

Mario::~Mario()
{

}