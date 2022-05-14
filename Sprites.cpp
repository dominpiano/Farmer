#include "Sprites.h"

Sprites::Sprites() {
	//Backgrounds
	grassTexture.loadFromFile("assets/textures/background/grass.png");
	grassSprite.setTexture(grassTexture);
	soil0Texture.loadFromFile("assets/textures/background/soil0.png");
	soil0Sprite.setTexture(soil0Texture);

	//Tools
	shovelToolTexture.loadFromFile("assets/textures/tools/shovel.png");
	shovelToolSprite.setTexture(shovelToolTexture);
	handToolTexture.loadFromFile("assets/textures/tools/hand.png");
	handToolSprite.setTexture(handToolTexture);
	sickleToolTexture.loadFromFile("assets/textures/tools/sickle.png");
	sickleToolSprite.setTexture(sickleToolTexture);

	//Seeds
	carrotSeedsTexture.loadFromFile("assets/textures/shopCards/carrotSeeds.png");
	carrotSeedsSprite.setTexture(carrotSeedsTexture);
	cucumberSeedsTexture.loadFromFile("assets/textures/shopCards/cucumberSeeds.png");
	cucumberSeedsSprite.setTexture(cucumberSeedsTexture);

	//Plants
	sf::Sprite temp;
	plantsTexture.loadFromFile("assets/textures/plants/plants.png");
	//cucumbersTexture.loadFromFile("assets/textures/plants/cucumbers.png");
	for (int i = 0; i < 4; i++) {
		temp.setTexture(plantsTexture);
		temp.setTextureRect(sf::IntRect(i * 100, 0, 100, 100));
		carrotSprites.emplace_back(temp);
	}
	for (int i = 0; i < 5; i++) {
		temp.setTexture(plantsTexture);
		temp.setTextureRect(sf::IntRect(i * 100, 100, 100, 100));
		cucumberSprites.emplace_back(temp);
	}


	//Inventory
	inventoryBackgroundTexture.loadFromFile("assets/textures/inventory/inventoryBackground.png");
	inventoryBackgroundSprite.setTexture(inventoryBackgroundTexture);
	shopBackgroundTexture.loadFromFile("assets/textures/inventory/shopBackground.png");
	shopBackgroundSprite.setTexture(shopBackgroundTexture);
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
sf::Sprite Sprites::sickleToolSprite;

//Seeds
sf::Sprite Sprites::carrotSeedsSprite;
sf::Sprite Sprites::cucumberSeedsSprite;

//Plants
std::vector<sf::Sprite> Sprites::carrotSprites;
std::vector<sf::Sprite> Sprites::cucumberSprites;

//Inventory
sf::Sprite Sprites::inventoryBackgroundSprite;
sf::Sprite Sprites::shopBackgroundSprite;
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