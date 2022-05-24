#include "Item.h"

std::ostream& operator<<(std::ostream& out, const sf::Vector2f v);

Item::Item(sf::Sprite item, int qty){
	itemSprite = item;
	quantity = qty;
	qtyDisp.setFont(Resources::titleFont);
	qtyDisp.setCharacterSize(16);
	qtyDisp.setFillColor(sf::Color::Black);
	qtyDisp.setString(std::to_string(quantity));
}
Item::Item() {
	qtyDisp.setFont(Resources::titleFont);
	qtyDisp.setCharacterSize(16);
	qtyDisp.setFillColor(sf::Color::Black);
}

void Item::setItem(sf::Sprite item) {
	itemSprite = item;
	//Set item position to be in the center
	//std::cout << sf::Vector2f((100 - item.getTextureRect().width) / 2, (100 - item.getTextureRect().height) / 2) << std::endl;
	itemSprite.setPosition(slotPos + sf::Vector2f((100 - itemSprite.getTextureRect().width) / 2, (100 - itemSprite.getTextureRect().height) / 2));
}
sf::Sprite Item::getItem() {
	return itemSprite;
}
void Item::setQuantity(int qty_) {
	quantity = qty_;
	if (quantity == 0) {
		slotHasItem = false;
		qtyDisp.setString("");
	}
	else {
		qtyDisp.setString(std::to_string(quantity));
	}
}
int Item::getQuantity() {
	return quantity;
}
sf::Text Item::getQuantityDisplay() {
	return qtyDisp;
}
void Item::setItemPos(float x, float y) {
	slotPos = sf::Vector2f(x, y);
	qtyDisp.setPosition(slotPos.x + 80, slotPos.y + 80);
	itemSprite.setPosition(slotPos + sf::Vector2f((100 - itemSprite.getTextureRect().width) / 2, (100 - itemSprite.getTextureRect().height) / 2));
}
void Item::renderItem(sf::RenderWindow& window) {
	if (slotHasItem) {
		window.draw(itemSprite);
	}
	window.draw(qtyDisp);
}