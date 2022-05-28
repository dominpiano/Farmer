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
	itemChangeAmountSprite = Sprites::itemChangeAmountSprite;

	//Texts
	itemAmountDisplay.setFont(Resources::quantityDisplayFont);
	itemAmountDisplay.setCharacterSize(32);
	itemAmountDisplay.setFillColor(sf::Color::Black);
	itemAmountDisplay.setString(std::to_string(currentItemAmount));

	totalPriceDisplay.setFont(Resources::quantityDisplayFont);
	totalPriceDisplay.setCharacterSize(32);
	totalPriceDisplay.setFillColor(sf::Color::Black);
	totalPriceDisplay.setString(std::to_string(totalPrice) + "$");

	shopCards.emplace_back(ShopCard(Sprites::carrotSeedsSprite, "Carrot Seeds", 5));
	shopCards[0].setDescr(L"Well, seeds of a carrot, what to say more?");
	shopCards.emplace_back(ShopCard(Sprites::cucumberSeedsSprite, "Cucumber Seeds", 4));
	shopCards[1].setDescr(L"Interesting seeds of a cucumber, remember to water it often!");
	shopCards.emplace_back(ShopCard(Sprites::potatoSeedsSprite, "Potato", 3));
	shopCards[2].setDescr(L"Yes, that's a potato, it can be just shoved into soil.");
	shopCards.emplace_back(ShopCard(Sprites::wheatSeedsSprite, "Wheat", 2));
	shopCards[3].setDescr(L"Yayy! Wheee(a)t!");

	for (int i = 0; i < 24; i++) {
		itemSlots.emplace_back(Item());
	}
}

bool isAdded = false; //Helper variable to first check a whole inventory and then decide to add new/ add to existing

void Inventory::addItem(Item it) {
	if (it.getQuantity() != 0) {
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
	itemAmountDisplay.setString(std::to_string(currentItemAmount));
}

void Inventory::setCurrentItemPrice(int price) {
	currentItemPrice = price;
	totalPrice = currentItemAmount * currentItemPrice;
	totalPriceDisplay.setString(std::to_string(currentItemAmount * currentItemPrice) + "$");
	itemAmountDisplay.setString(std::to_string(currentItemAmount));
}

void Inventory::updatePosition(sf::Vector2f center) {
	inventorySprite.setPosition(center.x - 1500 / 2, center.y - 900 / 2);
	shopSprite.setPosition(center.x - 1500 / 2, center.y - 900 / 2);
	invActiveTabSprite.setPosition(getMainPosition().x + 99, getMainPosition().y);
	invDeactiveTabSprite.setPosition(getMainPosition().x + 99, getMainPosition().y);
	shopActiveTabSprite.setPosition(getMainPosition().x + 99 + invActiveTabSprite.getTexture()->getSize().x, getMainPosition().y);
	shopDeactiveTabSprite.setPosition(getMainPosition().x + 99 + invActiveTabSprite.getTexture()->getSize().x, getMainPosition().y);
	buyButtonSprite.setPosition(getMainPosition().x + 1330 - 150, getMainPosition().y + 750 - 50);
	itemChangeAmountSprite.setPosition(getMainPosition().x + 1330 - 500, getMainPosition().y + 750 - 50);
	itemAmountDisplay.setPosition(getMainPosition().x + 970, getMainPosition().y + 650);
	totalPriceDisplay.setPosition(getMainPosition().x + 1330 - 75 - totalPriceDisplay.getGlobalBounds().width/2, getMainPosition().y + 650);
	//1185 740
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

void Inventory::changeItemAmount(sf::Vector2i pos) {
	if (pos.x < itemChangeAmountSprite.getGlobalBounds().left + 70) {
		if (currentItemAmount - 10 >= 0){
			currentItemAmount -= 10;
		}
		else {
			currentItemAmount = 0;
		}
	}
	else if (pos.x > itemChangeAmountSprite.getGlobalBounds().left + 74 && pos.x < itemChangeAmountSprite.getGlobalBounds().left + 144) {
		if (currentItemAmount - 1 >= 0) {
			currentItemAmount -= 1;
		}
		else {
			currentItemAmount = 0;
		}
	}
	else if (pos.x > itemChangeAmountSprite.getGlobalBounds().left + 148 && pos.x < itemChangeAmountSprite.getGlobalBounds().left + 218) {
		currentItemAmount += 1;
	}
	else if (pos.x > itemChangeAmountSprite.getGlobalBounds().left + 222 && pos.x < itemChangeAmountSprite.getGlobalBounds().left + 292) {
		currentItemAmount += 10;
	}
	itemAmountDisplay.setString(std::to_string(currentItemAmount));
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
		window.draw(itemChangeAmountSprite);
		for (auto& i : shopCards) {
			if (i.getSelected()) {
				window.draw(itemAmountDisplay);
				window.draw(totalPriceDisplay);
			}
		}
		break;
	}
}