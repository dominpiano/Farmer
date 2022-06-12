#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Resources.h"
#include "OptionType.h"

class Option{
protected:
	sf::Text optionText;
public:
	Option();
	Option(std::string text, sf::Vector2f pos);
	~Option();
	sf::RectangleShape optionBox;
	void setPosition(sf::Vector2f pos);
	bool checkHovered(sf::Vector2f mousePos);
	void renderOption(sf::RenderWindow& window);
};

