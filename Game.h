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
	sf::Vector2i relMousePos; //VERY IMPORTANT!!!! MOUSE POSITION RELATIVE TO VIEWPORT - REGARDLESS OF VIEW, COORDINATES THE SAME AS NORMAL
	sf::Vector2f oldPos, newPos, deltaPos;
	sf::Vector2f viewCenter;
	bool moving = false;
	float zoom = 1;
	int whichTileHovered = 0; //Stores a number of tile which is actually hovered on

	//Farm variables
	int farmSize;

	//Tool things
		//Tool utils
	int toolChosen = 0; // 0-hand, 1-shovel
	sf::Sprite toolChooseSprite;
		//Types of tool
	sf::Sprite shovelToolSprite;
	sf::Sprite handToolSprite;

	//Background things
	sf::Color bgColor = sf::Color(127, 152, 59);

	//Vectors
	std::vector<Tile> tiles;
	std::vector<sf::Sprite> backGround;

	//Time
	sf::Clock clock;

	//Helper functions
	sf::Vector2f getRightDownCorner();

	//Functions
	void initVars();
	void initSpritesUI();
	void initWindow();
	void updateFarmSize();
	void updateMousePosition();
	void updateTools();

	//For rendering
	void renderTiles();
	void renderTools();

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
