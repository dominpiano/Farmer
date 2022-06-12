#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Option.h"

class Menu : public Option{
private:
	int optionSelected;
public:
	std::vector<Option> options;
	sf::FloatRect bounds;
	Menu();
	Menu(sf::Vector2f mousePos);
	~Menu();
	void renderMenu(sf::RenderWindow& window);
};

