#include "Resources.h"

Resources::Resources() {
	titleFont.loadFromFile("assets/fonts/crayon_kids.ttf");
	descriptionFont.loadFromFile("assets/fonts/simply_olive.ttf");
}

//Fonts
sf::Font Resources::titleFont;
sf::Font Resources::descriptionFont;