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

	//Hover things
	static sf::Sprite hoverSprite;

	//Fences
	static sf::Sprite fenceSprite;
	static sf::Sprite fenceAngleSprite;
	Sprites();
};