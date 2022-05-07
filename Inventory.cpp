#include "Inventory.h"
std::ostream& operator<<(std::ostream& out, const sf::Vector2f v);
sf::Vector2f Inventory::getMainPosition() {
	return inventorySprite.getPosition();
}

Inventory::Inventory() {
	inventorySprite = Sprites::inventorySprite;
	invActiveTabSprite = Sprites::invActiveTabSprite;
	invDeactiveTabSprite = Sprites::invDeactiveTabSprite;
	shopActiveTabSprite = Sprites::shopActiveTabSprite;
	shopDeactiveTabSprite = Sprites::shopDeactiveTabSprite;
	buyButtonSprite = Sprites::buyButtonGraySprite;
}

void Inventory::activateBuyButton(bool toggle) {
	if (toggle) {
		buyButtonSprite = Sprites::buyButtonColorSprite;
		buyButtonSprite.setPosition(getMainPosition().x + 1500 - 150 - 30, getMainPosition().y + 900 - 50 - 30);
	}
	else {
		buyButtonSprite = Sprites::buyButtonGraySprite;
		buyButtonSprite.setPosition(getMainPosition().x + 1500 - 150 - 30, getMainPosition().y + 900 - 50 - 30);
	}
	
}

void Inventory::updatePosition(sf::Vector2f center) {
	inventorySprite.setPosition(center.x - 1500 / 2, center.y - 900 / 2);
	invActiveTabSprite.setPosition(getMainPosition().x + 60, getMainPosition().y);
	invDeactiveTabSprite.setPosition(getMainPosition().x + 60, getMainPosition().y - 1);
	shopActiveTabSprite.setPosition(getMainPosition().x + 60 + invActiveTabSprite.getTexture()->getSize().x - 5, getMainPosition().y);
	shopDeactiveTabSprite.setPosition(getMainPosition().x + 60 + invActiveTabSprite.getTexture()->getSize().x - 5, getMainPosition().y - 1);
	buyButtonSprite.setPosition(getMainPosition().x + 1500 - 150 - 30, getMainPosition().y + 900 - 50 - 30);
}

void Inventory::checkTabChanged(sf::Vector2i mousePos) {
	if (invDeactiveTabSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
		whichTabActive = 0;
	}
	else if (shopDeactiveTabSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
		whichTabActive = 1;
	}
}

void Inventory::renderInventory(sf::RenderWindow& window) {
	window.draw(inventorySprite);
	switch (whichTabActive) {
	case 0:
		window.draw(invActiveTabSprite);
		window.draw(shopDeactiveTabSprite);
		break;
	case 1:
		window.draw(invDeactiveTabSprite);
		window.draw(shopActiveTabSprite);
		window.draw(buyButtonSprite);
		break;
	}
}