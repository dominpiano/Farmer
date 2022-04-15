#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Sprites {
private:
	sf::Texture bgTexture, hoverTexture, fenceTexture, fenceAngleTexture;
public:
	Sprites();
	sf::Sprite bgSprite, hoverSprite, fenceSprite, fenceAngleSprite;
};



