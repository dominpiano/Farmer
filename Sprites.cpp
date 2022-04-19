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

//Inventory
sf::Sprite Sprites::inventorySprite;
sf::Sprite Sprites::invActiveTabSprite;
sf::Sprite Sprites::invDeactiveTabSprite;
sf::Sprite Sprites::shopActiveTabSprite;
sf::Sprite Sprites::shopDeactiveTabSprite;

//Hover things
sf::Sprite Sprites::hoverSprite;

//Fences
sf::Sprite Sprites::fenceSprite;
sf::Sprite Sprites::fenceAngleSprite;