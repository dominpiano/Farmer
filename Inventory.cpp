#include "Inventory.h"
std::ostream& operator<<(std::ostream& out, const sf::Vector2f v);

Inventory::Inventory() {
	inventorySprite = Sprites::inventorySprite;
	invActiveTabSprite = Sprites::invActiveTabSprite;
	invDeactiveTabSprite = Sprites::invDeactiveTabSprite;
	shopActiveTabSprite = Sprites::shopActiveTabSprite;
	shopDeactiveTabSprite = Sprites::shopDeactiveTabSprite;
}

void Inventory::updatePosition(sf::Vector2f center) {
	inventorySprite.setPosition(center.x - 1500 / 2, center.y - 900 / 2);
	invActiveTabSprite.setPosition(inventorySprite.getPosition().x + 60, inventorySprite.getPosition().y);
	invDeactiveTabSprite.setPosition(inventorySprite.getPosition().x + 60, inventorySprite.getPosition().y - 1);
	shopActiveTabSprite.setPosition(inventorySprite.getPosition().x + 60 + invActiveTabSprite.getTexture()->getSize().x - 5, inventorySprite.getPosition().y);
	shopDeactiveTabSprite.setPosition(inventorySprite.getPosition().x + 60 + invActiveTabSprite.getTexture()->getSize().x - 5, inventorySprite.getPosition().y - 1);
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
		break;
	}
}