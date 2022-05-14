#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Sprites {
private:
	//Backgrounds
	sf::Texture grassTexture;
	sf::Texture soil0Texture;

	//Tools
	sf::Texture shovelToolTexture;
	sf::Texture handToolTexture;
	sf::Texture sickleToolTexture;

	//Seeds
	sf::Texture carrotSeedsTexture;
	sf::Texture cucumberSeedsTexture;

	//Plants
	sf::Texture plantsTexture;
	//sf::Texture cucumbersTexture;

	//Inventory
	sf::Texture inventoryBackgroundTexture;
	sf::Texture shopBackgroundTexture;
	sf::Texture invActiveTabTexture;
	sf::Texture invDeactiveTabTexture;
	sf::Texture shopActiveTabTexture;
	sf::Texture shopDeactiveTabTexture;
	sf::Texture buyButtonGrayTexture;
	sf::Texture buyButtonColorTexture;

	//Shop cards
	sf::Texture cardBackgroundTexture;

	//Hover things
	sf::Texture hoverTexture;

	//Fences
	sf::Texture fenceTexture;
	sf::Texture fenceAngleTexture;
public:
	//Backgrounds
	static sf::Sprite grassSprite;
	static sf::Sprite soil0Sprite;

	//Tools
	static sf::Sprite shovelToolSprite;
	static sf::Sprite handToolSprite;
	static sf::Sprite sickleToolSprite;

	//Seeds
	static sf::Sprite carrotSeedsSprite;
	static sf::Sprite cucumberSeedsSprite;

	//Plants
	static std::vector<sf::Sprite> carrotSprites;
	static std::vector<sf::Sprite> cucumberSprites;

	//Inventory
	static sf::Sprite inventoryBackgroundSprite;
	static sf::Sprite shopBackgroundSprite;
	static sf::Sprite invActiveTabSprite;
	static sf::Sprite invDeactiveTabSprite;
	static sf::Sprite shopActiveTabSprite;
	static sf::Sprite shopDeactiveTabSprite;
	static sf::Sprite buyButtonGraySprite;
	static sf::Sprite buyButtonColorSprite;

	//Shop cards
	static sf::Sprite cardBackgroundSprite;

	//Hover things
	static sf::Sprite hoverSprite;

	//Fences
	static sf::Sprite fenceSprite;
	static sf::Sprite fenceAngleSprite;
	Sprites();
};