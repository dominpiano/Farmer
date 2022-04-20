#include "ShopCard.h"

//Constructors
ShopCard::ShopCard() {

}
ShopCard::ShopCard(sf::Vector2f pos, sf::Sprite item, sf::Text title, sf::Text descr) {
	cardBackgroundSprite = Sprites::cardBackgroundSprite;
	cardPos = pos;
	cardBackgroundSprite.setPosition(pos);
	itemSprite = item;
	itemTitleText = title;
	descriptionText = descr;
}

//Functions
void ShopCard::setDescr(sf::Text descr) {
	descriptionText = descr;
}
void ShopCard::renderCard(sf::RenderWindow& window) {
	window.draw(cardBackgroundSprite);
}
