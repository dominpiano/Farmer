#include "ShopCard.h"

std::ostream& operator<<(std::ostream& out, const sf::Vector2f v);

sf::Vector2f ShopCard::getMainPosition() {
	return cardBackgroundSprite.getPosition();
}

//Constructors
ShopCard::ShopCard() {

}
ShopCard::ShopCard(sf::Sprite item, sf::String title) {
	cardBackgroundSprite = Sprites::cardBackgroundSprite;
	itemSprite = item;

	itemTitleText.setFont(Resources::titleFont);
	itemTitleText.setCharacterSize(24);
	itemTitleText.setFillColor(sf::Color::Black);
	itemTitleText.setString(title);
}

//Functions
void ShopCard::setDescr(sf::String descr) {
	sf::String descrText = descr;
	sf::String append;
	int counter = 0;
	//This was only to do the fucking carriage return
	for (auto& i : descrText) {
		append += i;
		counter++;
		if (i == 10) {
			counter = 0;
		}
		if (counter > 14 && i == 32) {
			append += "\n";
			counter = 0;
		}
	}
	itemDescriptionText.setFont(Resources::titleFont);
	itemDescriptionText.setCharacterSize(19);
	itemDescriptionText.setFillColor(sf::Color::Black);
	itemDescriptionText.setString(append);
}
void ShopCard::setPosition(sf::Vector2f pos) {
	cardPos = pos;
	cardBackgroundSprite.setPosition(cardPos);
	itemSprite.setPosition(getMainPosition().x + 60, getMainPosition().y + 20);
	itemTitleText.setPosition(getMainPosition().x + 15, getMainPosition().y + 120);
	itemDescriptionText.setPosition(getMainPosition().x + 15, getMainPosition().y + 170);
}
void ShopCard::renderCard(sf::RenderWindow& window) {
	window.draw(cardBackgroundSprite);
	window.draw(itemSprite);
	window.draw(itemTitleText);
	window.draw(itemDescriptionText);
}
