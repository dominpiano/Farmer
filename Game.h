#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Tile.h"
#include "Sprites.h"

class Game {
private:

	//Variables
	int WIDTH; //1280
	int HEIGHT; //720
	sf::Event event;
	sf::View view;
	sf::Vector2i mousePos;

	//Farm variables
	int farmSize;

	//Background things
	sf::Color bgColor = sf::Color(127, 152, 59);

	//Vectors
	std::vector<Tile> tiles;

	//Time
	sf::Clock clock;

	//Functions
	void initVars();
	void initWindow();
	void updateFarmSize();
	void updateMousePosition();

public:

	//Variables
	sf::RenderWindow* window;

	//Constructors
	Game();
	virtual ~Game();

	//Getters Accessors
	const bool isWindowOpen();

	//Functions
	void initAll();
	void pollEvents();
	void frameUpdate();
	void render();
};
