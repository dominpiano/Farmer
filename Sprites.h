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
	sf::Texture potatoSeedsTexture;
	sf::Texture wheatSeedsTexture;

	//Plants
	sf::Texture plantsTexture;

	//Inventory
	sf::Texture inventoryBackgroundTexture;
	sf::Texture shopBackgroundTexture;
	sf::Texture invActiveTabTexture;
	sf::Texture invDeactiveTabTexture;
	sf::Texture shopActiveTabTexture;
	sf::Texture shopDeactiveTabTexture;
	sf::Texture buyButtonGrayTexture;
	sf::Texture buyButtonColorTexture;
	sf::Texture sellButtonGrayTexture;
	sf::Texture sellButtonColorTexture;
	sf::Texture itemChangeAmountTexture;

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
	static sf::Sprite potatoSeedsSprite;
	static sf::Sprite wheatSeedsSprite;

	//Plants
	static sf::Sprite plantSprite;
	static std::vector<sf::Sprite> carrotSprites;
	static std::vector<sf::Sprite> cucumberSprites;
	static std::vector<sf::Sprite> potatoSprites;
	static std::vector<sf::Sprite> wheatSprites;

	//Inventory
	static sf::Sprite inventoryBackgroundSprite;
	static sf::Sprite shopBackgroundSprite;
	static sf::Sprite invActiveTabSprite;
	static sf::Sprite invDeactiveTabSprite;
	static sf::Sprite shopActiveTabSprite;
	static sf::Sprite shopDeactiveTabSprite;
	static sf::Sprite buyButtonGraySprite;
	static sf::Sprite buyButtonColorSprite;
	static sf::Sprite sellButtonGraySprite;
	static sf::Sprite sellButtonColorSprite;
	static sf::Sprite itemChangeAmountSprite;

	//Shop cards
	static sf::Sprite cardBackgroundSprite;

	//Hover things
	static sf::Sprite hoverSprite;

	//Fences
	static sf::Sprite fenceSprite;
	static sf::Sprite fenceAngleSprite;
	Sprites();
};