#include "Sprites.h"

Sprites::Sprites() {
	//Backgrounds
	grassTexture.loadFromFile("assets/grass_stare.png");
	grassSprite.setTexture(grassTexture);
	soil0Texture.loadFromFile("assets/soil0.png");
	soil0Sprite.setTexture(soil0Texture);

	//Tools
	shovelTexture.loadFromFile("assets/shovel.png");
	shovelSprite.setTexture(shovelTexture);

	//Hover things
	hoverTexture.loadFromFile("assets/hoverIndicate.png");
	hoverSprite.setTexture(hoverTexture);

	//Fences
	fenceTexture.loadFromFile("assets/fence.png");
	fenceSprite.setTexture(fenceTexture);
	fenceAngleTexture.loadFromFile("assets/fenceAngle.png");
	fenceAngleSprite.setTexture(fenceAngleTexture);

	//Plants
}

//Backgrounds
sf::Sprite Sprites::grassSprite;
sf::Sprite Sprites::soil0Sprite;

//Tools
sf::Sprite Sprites::shovelSprite;

//Hover things
sf::Sprite Sprites::hoverSprite;

//Fences
sf::Sprite Sprites::fenceSprite;
sf::Sprite Sprites::fenceAngleSprite;