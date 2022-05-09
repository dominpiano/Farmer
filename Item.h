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


class Item{
private:
	sf::Sprite itemSprite;
	sf::RectangleShape slotFrame = sf::RectangleShape(sf::Vector2f(95, 95));
	int quantity = 0;
	sf::Vector2f itemPos;
	sf::Text qtyDisp;
public:
	Item(sf::Sprite item, int qty);
	Item();
	void setItem(sf::Sprite item);
	sf::Sprite getItem();
	void setQuantity(int qty_);
	void addOne();
	void removeOne();
	int getQuantity();
	void setItemPos(sf::Vector2f pos);
	void setItemPos(float x, float y);
	void renderItem(sf::RenderWindow& window);
};

