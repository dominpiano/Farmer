#include "Menu.h"

Menu::Menu() {
	
}

Menu::Menu(sf::Vector2f mousePos) {
	bounds = sf::FloatRect(mousePos.x, mousePos.y, 160, 80);
	options.emplace_back(Option("Sell", mousePos));
	mousePos.y = mousePos.y + 40;
	options.emplace_back(Option("Sew", mousePos));
}

Menu::~Menu() {

}

void Menu::renderMenu(sf::RenderWindow& window) {
	for (auto& i : options) {
		i.renderOption(window);
	}
}
