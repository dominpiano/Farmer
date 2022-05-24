#include "Inventory.h"
std::ostream& operator<<(std::ostream& out, const sf::Vector2f v);
sf::Vector2f Inventory::getMainPosition() {
	return inventorySprite.getPosition();
}

Inventory::Inventory() {
	inventorySprite = Sprites::inventoryBackgroundSprite;
	shopSprite = Sprites::shopBackgroundSprite;
	invActiveTabSprite = Sprites::invActiveTabSprite;
	invDeactiveTabSprite = Sprites::invDeactiveTabSprite;
	shopActiveTabSprite = Sprites::shopActiveTabSprite;
	shopDeactiveTabSprite = Sprites::shopDeactiveTabSprite;
	buyButtonSprite = Sprites::buyButtonGraySprite;
	for (int i = 0; i < 24; i++) {
		itemSlots.emplace_back(Item());
	}
}

bool isAdded = false; //Helper variable to first check a whole inventory and then decide to add new/ add to existing

void Inventory::addItem(Item it) {
	for (auto& i : itemSlots) {
		if (i.getItem().getTexture() == it.getItem().getTexture() && i.getItem().getTextureRect().top == it.getItem().getTextureRect().top) {
			i.setQuantity(i.getQuantity() + it.getQuantity());
			isAdded = true;
			break;
		}
	}
	if (!isAdded) {
		for (auto& i : itemSlots) {
			if (!i.slotHasItem) {
				i.setItem(it.getItem());
				i.setQuantity(it.getQuantity());
				i.slotHasItem = true;
				break;
			}
		}
	}
	isAdded = false;
}

void Inventory::activateBuyButton(bool toggle) {
	if (toggle) {
		buyButtonSprite = Sprites::buyButtonColorSprite;
		buyButtonSprite.setPosition(getMainPosition().x + 1330 - 150, getMainPosition().y + 750 - 50);
	}
	else {
		buyButtonSprite = Sprites::buyButtonGraySprite;
		buyButtonSprite.setPosition(getMainPosition().x + 1330 - 150, getMainPosition().y + 750 - 50);
	}
	
}

void Inventory::updatePosition(sf::Vector2f center) {
	inventorySprite.setPosition(center.x - 1500 / 2, center.y - 900 / 2);
	shopSprite.setPosition(center.x - 1500 / 2, center.y - 900 / 2);
	invActiveTabSprite.setPosition(getMainPosition().x + 99, getMainPosition().y);
	invDeactiveTabSprite.setPosition(getMainPosition().x + 99, getMainPosition().y);
	shopActiveTabSprite.setPosition(getMainPosition().x + 99 + invActiveTabSprite.getTexture()->getSize().x, getMainPosition().y);
	shopDeactiveTabSprite.setPosition(getMainPosition().x + 99 + invActiveTabSprite.getTexture()->getSize().x, getMainPosition().y);
	buyButtonSprite.setPosition(getMainPosition().x + 1330 - 150, getMainPosition().y + 750 - 50);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			//Only for locating a set of slots
			itemSlots[j * 8 + i].setItemPos(getMainPosition().x + i * 113 + 305, getMainPosition().y + j * 113 + 379);
		}
	}
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
	if (whichTabActive == 0) {
		window.draw(inventorySprite);
	}
	else if (whichTabActive == 1) {
		window.draw(shopSprite);
	}
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