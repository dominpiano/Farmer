#include "Sprites.h"

Sprites::Sprites() {
	std::cout << "konstr" << std::endl;
	bgTexture.loadFromFile("assets/grass.png");
	Sprites::bgSprite.setTexture(bgTexture);

	hoverTexture.loadFromFile("assets/hoverIndicate.png");
	Sprites::hoverSprite.setTexture(hoverTexture);

	fenceTexture.loadFromFile("assets/fence.png");
	Sprites::fenceSprite.setTexture(fenceTexture);

	fenceAngleTexture.loadFromFile("assets/fenceAngle.png");
	Sprites::fenceAngleSprite.setTexture(fenceAngleTexture);
}

sf::Sprite Sprites::bgSprite;
sf::Sprite Sprites::hoverSprite;
sf::Sprite Sprites::fenceSprite;
sf::Sprite Sprites::fenceAngleSprite;