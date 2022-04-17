#include "Tile.h"


//Constructors & Destructors
Tile::Tile() {
	
}
Tile::Tile(sf::Vector2f pos_) {
	pos = pos_;
	backgroundSprite = Sprites::bgSprite;
	backgroundSprite.setPosition(pos);
	hoverSprite = Sprites::hoverSprite;
	hoverSprite.setPosition(pos);
}
Tile::~Tile() {

}

//Functions
sf::Sprite Tile::getBg() {
	return backgroundSprite;
}
void Tile::setFence(sf::Sprite spr, int rotation = 0) {
	hasFence = true;
	fenceSprite = spr;
	fenceSprite.setRotation(rotation);
	switch (rotation){
	case 0:
		fenceSprite.setPosition(pos.x, pos.y);
		break;
	case 90:
		fenceSprite.setPosition(pos.x + 100, pos.y);
		break;
	case 180:
		fenceSprite.setPosition(pos.x + 100, pos.y + 100);
		break;
	case -90:
		fenceSprite.setPosition(pos.x, pos.y + 100);
		break;
	}
}
void Tile::renderTile(sf::RenderWindow& window) {
	window.draw(backgroundSprite);
	if (hasFence) {
		window.draw(fenceSprite);
	}
	if (isHovered && !hasFence) {
		window.draw(hoverSprite);
	}
}
