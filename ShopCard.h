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
	sf::Sprite itemSprite;

	sf::Text itemTitleText;
	sf::Text itemDescriptionText;
	sf::Text itemPriceText;

	bool isSelected = false;
public:
	//Constructos
	ShopCard();
	ShopCard(sf::Sprite item, sf::String title, int price);
	
	int itemPrice;
	sf::Sprite cardBackgroundSprite;

	//Functions
	void setDescr(sf::String descr);
	void setPosition(sf::Vector2f pos);
	void setSelected(bool toggle);
	bool getSelected();
	sf::Sprite getItem();
	sf::Vector2f getMainPosition();
	void renderCard(sf::RenderWindow& window);
};

