#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>


class Game
{
public:
	Game();
	virtual ~Game();
	void Engine();
	void Render();
	void Update();
	void UpdateDt();
	void poolEvents();
	const bool running() const;




private:
	//varibles
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	sf::RectangleShape square;
	sf::CircleShape circle;

	sf::Vector2i MAXSIZEWINDOW;
	void initWindow();

};