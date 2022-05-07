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
#include "Resources.h"

class ShopCard{
private:
	sf::Vector2f cardPos;
	sf::Sprite cardBackgroundSprite;
	sf::Sprite itemSprite;

	sf::Text itemTitleText;
	sf::Text itemDescriptionText;

	sf::Sprite buttonBuySprite;
public:
	//Constructos
	ShopCard();
	ShopCard(sf::Sprite item, sf::String title);
	
	//Functions
	void setDescr(sf::String descr);
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getMainPosition();
	void renderCard(sf::RenderWindow& window);
};

