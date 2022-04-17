#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Sprites {
private:
	sf::Texture bgTexture, hoverTexture, fenceTexture, fenceAngleTexture;
public:
	static sf::Sprite bgSprite, hoverSprite, fenceSprite, fenceAngleSprite;
	Sprites();
};