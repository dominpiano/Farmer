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

class Tile {
private:
	sf::Sprite backgroundSprite;
	sf::Sprite hoverSprite;
	sf::Sprite fenceSprite;
	sf::Vector2f pos;
public:
	//Constructors & Destructors
	Tile();
	Tile(sf::Vector2f pos_);
	~Tile();
	//Variables
	bool isHovered;
	bool hasFence = false;

	//Functions
	sf::Sprite getBg();
	void setBg(sf::Sprite bgSpr);
	void setFence(sf::Sprite spr, int rotation);
	void renderTile(sf::RenderWindow& window);
};



