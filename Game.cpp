#include "Game.h"

Game::Game()
{

	this->initWindow();

	this->Engine();
}

Game::~Game()
{
	delete this->window;
}

void Game::Engine()
{
	while (this->running())
	{
		this->UpdateDt();

		this->Update();

		this->Render();

	}

}

void Game::Render()
{
	this->window->clear();


	this->window->draw(circle);
	this->window->draw(square);

	this->window->display();
}

void Game::Update()
{
	this->poolEvents();

}

void Game::UpdateDt()
{

	if (circle.getGlobalBounds().intersects(square.getGlobalBounds()))
		square.setFillColor(sf::Color(100, 20, 100, 250));
	else
		square.setFillColor(sf::Color(0, 0, 100, 250));


}

void Game::poolEvents()
{

	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		default:

			break;

		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			if (this->event.key.code == sf::Keyboard::D)
			{
				square.rotate(3);
			}
			if (this->event.key.code == sf::Keyboard::A)
			{
				square.rotate(-3);
			}
			break;
		}
	}
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::initWindow()
{
	this->window = nullptr;
	MAXSIZEWINDOW = sf::Vector2i(600, 400);

	std::srand(time(0));

	videoMode = sf::VideoMode(MAXSIZEWINDOW.x, MAXSIZEWINDOW.y);
	window = new sf::RenderWindow(videoMode, "Game", sf::Style::Default);
	window->setFramerateLimit(60);

	square.setSize(sf::Vector2f(140, 30));
	square.setPosition(sf::Vector2f(MAXSIZEWINDOW.x / 2, MAXSIZEWINDOW.y / 2));
	square.setOrigin(sf::Vector2f(70, 15));
	square.setFillColor(sf::Color(0, 0, 100, 250));

	circle.setRadius(70.f);
	circle.setPosition(sf::Vector2f(MAXSIZEWINDOW.x / 2 - 120, MAXSIZEWINDOW.y / 2));
	circle.setOrigin(sf::Vector2f(70.f, 70.f));

}
