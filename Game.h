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
#include "PlantType.h"
#include "Animation.h"
#include "Menu.h"

class Game {
private:

	//Variables
	int WIDTH; //1920
	int HEIGHT; //1080
	sf::Event event;
	sf::View view;
	sf::Image icon;

	//Positioning
	sf::Vector2i mousePos;
	sf::Vector2f relMousePos; //VERY IMPORTANT!!!! MOUSE POSITION RELATIVE TO VIEWPORT - REGARDLESS OF VIEW, COORDINATES THE SAME AS NORMAL
	sf::Vector2f oldPos, newPos, deltaPos;
	sf::Vector2f viewCenter;
	bool moving = false;
	float zoom = 1;
	int whichTileHovered = 0; //Stores a number of tile which is actually hovered on

	//Farm variables
	int farmSize;

	//Tool things
		//Tool utils
	int toolChosen = 0; // 0-hand, 1-shovel, 2-seed, 3-sickle
	sf::Sprite toolPointerSprite;
		//Types of tool
	sf::Sprite shovelToolSprite;
	sf::Sprite handToolSprite;
	sf::Sprite sickleToolSprite;
	sf::Sprite itemChosenSprite; //An item which is chosen right now
	sf::Text itemChosenQuantity; //Quantity text to display
	int itemChosenQuantityNumber; //An integer to tell a quantity
	bool isItemChosen; //Bool to check if item (seed) is chosen

	//Inventory
	bool isInventoryOpen = false;
	Inventory inventory;
	//Menu in inventory
	Menu* menu = nullptr;
	bool isMenuOpen = false;
	Item menuItem;

	//Background things
	sf::Color bgColor = sf::Color(127, 152, 59);
	sf::RectangleShape darken = sf::RectangleShape({ 1920, 1080 });
	
	//Vectors
	std::vector<Tile> tiles;
	std::vector<sf::Sprite> backGround;

	//Time
	sf::Clock clock;
	sf::Clock clockDelta; //For deltaTime
	sf::Time lastTime, nextTime;
	float deltaTime;

	//Money thingies
	Animation coinAnim;
	sf::Texture coinTexture;
	sf::Sprite coinSprite;
	int balance;
	sf::Text balanceDisp;

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
	void updateQuantitiesOfItems();
	void updateBalance(int amount);

	//For rendering
	void renderTiles();
	void renderTools();
	void renderInventory();
	void renderMoney();

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
