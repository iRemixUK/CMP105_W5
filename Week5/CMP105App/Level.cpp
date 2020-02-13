#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	soldierTexture.loadFromFile("gfx/soldier.png");
	soldier.setSize(sf::Vector2f(55, 108));
	soldier.setPosition(100, 100);
	soldier.setTexture(&soldierTexture);
	soldier.setInput(input);
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
	soldier.update(dt);
	soldier.move(mario.getSpeedX() * dt, 0);
	//zombie.update(dt);
	//zombie.move(zombie.getSpeedX() * dt, 0);

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(soldier);
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