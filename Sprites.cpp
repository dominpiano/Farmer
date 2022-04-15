#include "Sprites.h"

Sprites::Sprites() {
	bgTexture.loadFromFile("assets/grass.png");
	bgSprite.setTexture(bgTexture);
	hoverTexture.loadFromFile("assets/hoverIndicate.png");
	hoverSprite.setTexture(hoverTexture);
	fenceTexture.loadFromFile("assets/fence.png");
	fenceSprite.setTexture(fenceTexture);
	fenceAngleTexture.loadFromFile("assets/fenceAngle.png");
	fenceAngleSprite.setTexture(fenceAngleTexture);
}
