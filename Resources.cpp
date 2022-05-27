#include "Resources.h"

Resources::Resources() {
	cardDescriptionFont.loadFromFile("assets/fonts/crayon_kids.ttf");
	quantityDisplayFont.loadFromFile("assets/fonts/coffee_extra.ttf");
	//TODO: Add sounds!!
}

//Fonts
sf::Font Resources::cardDescriptionFont;
sf::Font Resources::quantityDisplayFont;