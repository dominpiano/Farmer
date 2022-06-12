#include "Option.h"

std::ostream& operator<<(std::ostream& out, const sf::Vector2f v);


Option::Option() {

}

Option::Option(std::string text, sf::Vector2f pos) {
	optionBox = sf::RectangleShape(sf::Vector2f(160,40));
	
	optionBox.setOutlineColor(sf::Color::Black);
	optionBox.setOutlineThickness(1.f);
	optionBox.setPosition(pos);

	optionBox.setFillColor(sf::Color(255, 170, 79));

	optionText.setFont(Resources::cardDescriptionFont);
	optionText.setCharacterSize(25);
	optionText.setFillColor(sf::Color::Black);
	optionText.setString(text);
	optionText.setPosition(optionBox.getGlobalBounds().left + optionBox.getGlobalBounds().width/2 - optionText.getGlobalBounds().width / 2, optionBox.getGlobalBounds().top + optionBox.getGlobalBounds().height/2 - optionText.getGlobalBounds().height / 2 - 8);
}

Option::~Option() {

}

void Option::setPosition(sf::Vector2f pos) {
	optionBox.setPosition(pos);
	optionText.setPosition(optionBox.getGlobalBounds().left + optionBox.getGlobalBounds().width/2 - optionText.getGlobalBounds().width/2, optionBox.getGlobalBounds().top + optionBox.getGlobalBounds().height/2 - optionText.getGlobalBounds().height/2);
}

bool Option::checkHovered(sf::Vector2f mousePos) {
	//std::cout << optionBox.getGlobalBounds().left << ", " << optionBox.getGlobalBounds().width << std::endl;

	if (optionBox.getGlobalBounds().contains(mousePos)) {
		optionBox.setFillColor(sf::Color(240, 165, 91));
		return true;
	}
	else {
		optionBox.setFillColor(sf::Color(255, 185, 115));
		return false;
	}
}

void Option::renderOption(sf::RenderWindow& window){
	window.draw(optionBox);
	window.draw(optionText);
}
