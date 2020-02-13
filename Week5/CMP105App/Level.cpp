#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombTexture.loadFromFile("gfx/animZombie.png"); 
	zombie.setSize(sf::Vector2f(55, 108)); 
	zombie.setPosition(100, 100); 
	zombie.setTexture(&zombTexture);
	zombie.setInput(input);

	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setSize(sf::Vector2f(55, 108));
	mario.setPosition(100, 100);
	mario.setTexture(&marioTexture);
	mario.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	mario.update(dt);
	mario.move(mario.getSpeedX() * dt, 0);
	//zombie.update(dt);
	//zombie.move(zombie.getSpeedX() * dt, 0);

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(mario);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}