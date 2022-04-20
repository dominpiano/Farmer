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

class ShopCard{
private:
	sf::Vector2f cardPos;
	sf::Sprite cardBackgroundSprite;
	sf::Sprite itemSprite;
	sf::Text itemTitleText;
	sf::Text descriptionText;
	sf::Sprite buttonBuySprite;
public:
	//Constructos
	ShopCard();
	ShopCard(sf::Vector2f pos, sf::Sprite item, sf::Text title, sf::Text descr);
	
	//Functions
	void setDescr(sf::Text descr);
	void renderCard(sf::RenderWindow& window);
};

