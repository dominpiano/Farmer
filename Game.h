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
#include "Resources.h"
#include "Inventory.h"
#include "ShopCard.h"
#include "PlantType.h"

class Game {
private:

	//Variables
	int WIDTH; //1280
	int HEIGHT; //720
	sf::Event event;
	sf::View view;

	//Positioning
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
	int toolChosen = 0; // 0-hand, 1-shovel, 2-seed
	sf::Sprite toolPointerSprite;
		//Types of tool
	sf::Sprite shovelToolSprite;
	sf::Sprite handToolSprite;
	sf::Sprite itemChosenSprite;
	sf::Text itemChosenQuantity;
	int itemChosenQuantityNumber;
	bool isItemChosen;

	//Inventory
	bool isInventoryOpen = false;
	Inventory inventory;

	//Background things
	sf::Color bgColor = sf::Color(127, 152, 59);
	
	//Vectors
	std::vector<Tile> tiles;
	std::vector<sf::Sprite> backGround;
	std::vector<ShopCard> shopCards;

	//Time
	sf::Clock clock;
	sf::Time lastTime, nextTime;

	//Helper functions
	sf::Vector2f getRightDownCorner();
	sf::Vector2f getLeftUpCorner();

	//Functions
	void initVars();
	void initSpritesUI();
	void initWindow();
	void updateFarmSize();
	void updateMousePosition();
	void updateTools();
	void setupInventory();

	//For rendering
	void renderTiles();
	void renderTools();
	void renderInventory();

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
