#include "Item.h"

Item::Item(sf::Sprite item, int qty){
	itemSprite = item;
	quantity = qty;
	slotFrame.setOutlineColor(sf::Color::Black);
	slotFrame.setFillColor(sf::Color(0, 0, 0, 0));
	slotFrame.setOutlineThickness(0.8f);
	qtyDisp.setFont(Resources::titleFont);
	qtyDisp.setCharacterSize(16);
	qtyDisp.setFillColor(sf::Color::Black);
	qtyDisp.setString(std::to_string(quantity));
}
Item::Item() {
	slotFrame.setOutlineColor(sf::Color::Black);
	slotFrame.setFillColor(sf::Color(0, 0, 0, 0));
	slotFrame.setOutlineThickness(0.8f);
	qtyDisp.setFont(Resources::titleFont);
	qtyDisp.setCharacterSize(16);
	qtyDisp.setFillColor(sf::Color::Black);
}

void Item::setItem(sf::Sprite item) {
	itemSprite = item;
}
sf::Sprite Item::getItem() {
	return itemSprite;
}
void Item::setQuantity(int qty_) {
	quantity = qty_;
	qtyDisp.setString(std::to_string(quantity));
}
void Item::addOne() {
	quantity++;
	qtyDisp.setString(std::to_string(quantity));
}
void Item::removeOne() {
	if (quantity > 0) {
		quantity--;
	}
	qtyDisp.setString(std::to_string(quantity));
}
int Item::getQuantity() {
	return quantity;
}
void Item::setItemPos(sf::Vector2f pos) {
	itemPos = pos;
	itemSprite.setPosition(itemPos);
	//qtyDisp.setPosition(itemPos.x + 70, itemPos.y + 70);
}
void Item::setItemPos(float x, float y) {
	itemPos = sf::Vector2f(x, y);
	itemSprite.setPosition(itemPos);
}
void Item::renderItem(sf::RenderWindow& window) {
	window.draw(slotFrame);
	window.draw(itemSprite);
	window.draw(qtyDisp);
}