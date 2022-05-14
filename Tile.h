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
#include "PlantType.h"

class Tile {
private:
	sf::Sprite backgroundSprite;
	sf::Sprite hoverSprite;
	sf::Sprite fenceSprite;
	sf::Vector2f pos;
	PlantType plantType;
	sf::Sprite plantSprite;
	sf::Time plantPlacedTime; //Working also as a "lap" time
	float timeRequired; //Required time to fully grow a plant
	int plantStage = 0;
	int stagesRequired;
public:
	//Constructors & Destructors
	Tile();
	Tile(sf::Vector2f pos_);
	~Tile();
	//Variables
	bool isHovered;
	bool hasFence = false;
	bool hasPlant = false;

	//Functions
	sf::Sprite getBg();
	void setBg(sf::Sprite bgSpr);
	void setFence(sf::Sprite spr, int rotation);

	//For plants
	void setPlant(PlantType type, int stages, sf::Time plantTime, float timeReq);
	PlantType getPlant();
	bool isRipe();
	void reset();
	void updatePlant(sf::Time actTime);
	void renderTile(sf::RenderWindow& window);
};



