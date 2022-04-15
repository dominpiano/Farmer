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
	sf::Sprite tmpSprite;
	sf::Sprite fenceSprite;
	bool hasFence;
	sf::Vector2f pos;
	Sprites SPRITES;
public:
	//Constructors & Destructors
	Tile(sf::Vector2f pos_);
	~Tile();
	//Variables
	bool isHovered;

	//Functions
	bool isHovering(sf::Vector2i mousePos, int WIDTH, int HEIGHT, int zoom, sf::View view);
	void setPos(sf::Vector2f position);
	void setFence(sf::Sprite spr, int rotation);
	void renderTile(sf::RenderWindow& window);
};



