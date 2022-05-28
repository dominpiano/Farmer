#include "ShopCard.h"

std::ostream& operator<<(std::ostream& out, const sf::Vector2f v);

sf::Vector2f ShopCard::getMainPosition() {
	return cardBackgroundSprite.getPosition();
}

//Constructors
ShopCard::ShopCard() {

}
ShopCard::ShopCard(sf::Sprite item, sf::String title, int price) {
	cardBackgroundSprite = Sprites::cardBackgroundSprite;
	itemSprite = item;
	itemPrice = price;
	itemTitleText.setFont(Resources::cardDescriptionFont);
	itemTitleText.setCharacterSize(24);
	itemTitleText.setFillColor(sf::Color::Black);
	itemTitleText.setString(title);
	itemPriceText.setFont(Resources::quantityDisplayFont);
	itemPriceText.setCharacterSize(24);
	itemPriceText.setFillColor(sf::Color::Black);
	itemPriceText.setString(std::to_string(itemPrice) + "$");
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
	itemDescriptionText.setFont(Resources::cardDescriptionFont);
	itemDescriptionText.setCharacterSize(16);
	itemDescriptionText.setFillColor(sf::Color::Black);
	itemDescriptionText.setString(append);
}
void ShopCard::setSelected(bool toggle) {
	if (toggle) {
		cardBackgroundSprite.setScale(1.05f, 1.05f);
		cardBackgroundSprite.setPosition(cardPos.x - 5, cardPos.y - 7.5);
		isSelected = true;
	}
	else {
		cardBackgroundSprite.setScale(1, 1);
		cardBackgroundSprite.setPosition(cardPos);
		isSelected = false;
	}	
}
bool ShopCard::getSelected() {
	return isSelected;
}
sf::Sprite ShopCard::getItem() {
	return itemSprite;
}
void ShopCard::setPosition(sf::Vector2f pos) {
	cardPos = pos;
	cardBackgroundSprite.setPosition(cardPos);
	itemSprite.setPosition(getMainPosition().x + 60, getMainPosition().y + 20);
	itemTitleText.setPosition(getMainPosition().x + 15, getMainPosition().y + 120);
	itemDescriptionText.setPosition(getMainPosition().x + 15, getMainPosition().y + 155);
	itemPriceText.setPosition(getMainPosition().x + 100 - itemPriceText.getGlobalBounds().width/2, getMainPosition().y + 265);
}
void ShopCard::renderCard(sf::RenderWindow& window) {
	window.draw(cardBackgroundSprite);
	window.draw(itemSprite);
	window.draw(itemTitleText);
	window.draw(itemDescriptionText);
	window.draw(itemPriceText);
}
