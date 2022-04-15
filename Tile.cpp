#include "Tile.h"


//Constructors & Destructors
Tile::Tile(sf::Vector2f pos_) {
	pos = pos_;
	tmpSprite = SPRITES.bgSprite;
	tmpSprite.setPosition(pos);
}
Tile::~Tile() {

}

//Functions
bool Tile::isHovering(sf::Vector2i mousePos, int WIDTH, int HEIGHT, int zoom, sf::View view) {
	if (tmpSprite.getGlobalBounds().contains(mousePos.x * zoom + view.getCenter().x - WIDTH / 2 * zoom, mousePos.y * zoom + view.getCenter().y - HEIGHT / 2 * zoom)) {
		isHovered = true;
	}
	else {
		isHovered = false;
	}
	return isHovered;
}
void Tile::setPos(sf::Vector2f position) {
	pos = position;
}
void Tile::setFence(sf::Sprite spr, int rotation) {
	hasFence = true;
	fenceSprite = spr;
	fenceSprite.setRotation(rotation);
	switch (rotation){
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
	window.draw(tmpSprite);
	if (hasFence) {
		window.draw(fenceSprite);
	}
	if (isHovered && !hasFence) {
		window.draw(SPRITES.hoverSprite);
	}
}
