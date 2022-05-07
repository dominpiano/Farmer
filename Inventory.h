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
#include "Sprites.h"

class Inventory{
private:
	//Variables
	sf::Sprite invActiveTabSprite;
	sf::Sprite invDeactiveTabSprite;
	sf::Sprite shopActiveTabSprite;
	sf::Sprite shopDeactiveTabSprite;

public:
	//Constructors & functions
	sf::Sprite inventorySprite;
	sf::Sprite buyButtonSprite;
	int whichTabActive = 0;
	Inventory();
	void activateBuyButton(bool toggle);
	void updatePosition(sf::Vector2f center);
	void checkTabChanged(sf::Vector2i mousePos);
	sf::Vector2f getMainPosition();
	void renderInventory(sf::RenderWindow& window);
};

