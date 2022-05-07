#include "Sprites.h"

Sprites::Sprites() {
	//Backgrounds
	grassTexture.loadFromFile("assets/textures/background/grass_stare.png");
	grassSprite.setTexture(grassTexture);
	soil0Texture.loadFromFile("assets/textures/background/soil0.png");
	soil0Sprite.setTexture(soil0Texture);

	//Tools
	shovelToolTexture.loadFromFile("assets/textures/tools/shovel.png");
	shovelToolSprite.setTexture(shovelToolTexture);
	handToolTexture.loadFromFile("assets/textures/tools/hand.png");
	handToolSprite.setTexture(handToolTexture);

	//Crops and seeds
	carrotSeedsTexture.loadFromFile("assets/textures/shopCards/carrotSeeds.png");
	carrotSeedsSprite.setTexture(carrotSeedsTexture);
	cucumberSeedsTexture.loadFromFile("assets/textures/shopCards/cucumberSeeds.png");
	cucumberSeedsSprite.setTexture(cucumberSeedsTexture);

	//Inventory
	inventoryTexture.loadFromFile("assets/textures/inventory/inventoryBackground.png");
	inventorySprite.setTexture(inventoryTexture);
	invActiveTabTexture.loadFromFile("assets/textures/inventory/invActiveTab.png");
	invActiveTabSprite.setTexture(invActiveTabTexture);
	invDeactiveTabTexture.loadFromFile("assets/textures/inventory/invDeactiveTab.png");
	invDeactiveTabSprite.setTexture(invDeactiveTabTexture);
	shopActiveTabTexture.loadFromFile("assets/textures/inventory/shopActiveTab.png");
	shopActiveTabSprite.setTexture(shopActiveTabTexture);
	shopDeactiveTabTexture.loadFromFile("assets/textures/inventory/shopDeactiveTab.png");
	shopDeactiveTabSprite.setTexture(shopDeactiveTabTexture);
	buyButtonGrayTexture.loadFromFile("assets/textures/inventory/buyButtonGray.png");
	buyButtonGraySprite.setTexture(buyButtonGrayTexture);
	buyButtonColorTexture.loadFromFile("assets/textures/inventory/buyButtonColor.png");
	buyButtonColorSprite.setTexture(buyButtonColorTexture);

	//Shop cards
	cardBackgroundTexture.loadFromFile("assets/textures/shopCards/cardBackground.png");
	//cardBackgroundTexture.setSmooth(true);
	cardBackgroundSprite.setTexture(cardBackgroundTexture);

	//Hover things
	hoverTexture.loadFromFile("assets/textures/background/hoverIndicate.png");
	hoverSprite.setTexture(hoverTexture);

	//Fences
	fenceTexture.loadFromFile("assets/textures/background/fence.png");
	fenceSprite.setTexture(fenceTexture);
	fenceAngleTexture.loadFromFile("assets/textures/background/fenceAngle.png");
	fenceAngleSprite.setTexture(fenceAngleTexture);

	//Plants
}

//Backgrounds
sf::Sprite Sprites::grassSprite;
sf::Sprite Sprites::soil0Sprite;

//Tools
sf::Sprite Sprites::shovelToolSprite;
sf::Sprite Sprites::handToolSprite;

//Crops and seeds
sf::Sprite Sprites::carrotSeedsSprite;
sf::Sprite Sprites::cucumberSeedsSprite;

//Inventory
sf::Sprite Sprites::inventorySprite;
sf::Sprite Sprites::invActiveTabSprite;
sf::Sprite Sprites::invDeactiveTabSprite;
sf::Sprite Sprites::shopActiveTabSprite;
sf::Sprite Sprites::shopDeactiveTabSprite;
sf::Sprite Sprites::buyButtonGraySprite;
sf::Sprite Sprites::buyButtonColorSprite;

//Shop cards
sf::Sprite Sprites::cardBackgroundSprite;

//Hover things
sf::Sprite Sprites::hoverSprite;

//Fences
sf::Sprite Sprites::fenceSprite;
sf::Sprite Sprites::fenceAngleSprite;