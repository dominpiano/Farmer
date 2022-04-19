#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Sprites.h"

class Inventory{
private:
	//Variables
	int whichTabActive = 0;
	sf::Sprite inventorySprite;
	sf::Sprite invActiveTabSprite;
	sf::Sprite invDeactiveTabSprite;
	sf::Sprite shopActiveTabSprite;
	sf::Sprite shopDeactiveTabSprite;
	
public:
	//Constructors & functions
	Inventory();
	void updatePosition(sf::Vector2f center);
	void checkTabChanged(sf::Vector2i mousePos);
	void renderInventory(sf::RenderWindow &window);
};

