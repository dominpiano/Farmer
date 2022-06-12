#include "Tile.h"


//Constructors & Destructors
Tile::Tile() {
	
}
Tile::Tile(sf::Vector2f pos_) {
	pos = pos_;
	//Positioning sprites
	backgroundSprite = Sprites::grassSprite;
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
void Tile::setBg(sf::Sprite bgSpr) {
	backgroundSprite = bgSpr;
	backgroundSprite.setPosition(pos);
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
void Tile::setPlant(PlantType type, int stages, sf::Time plantTime, float timeReq) {
	plantType = type;
	stagesRequired = stages;
	plantPlacedTime = plantTime;
	deviation = ((rand() % 100) < 50 ) ? (float(rand() % 3) + (rand() % 10 + 1)/10.f) : -(float(rand() % 3) + (rand() % 10 + 1) / 10.f);
	//std::cout << deviation << std::endl;
	timeRequired = timeReq + deviation;
	hasPlant = true;
}
PlantType Tile::getPlant() {
	return plantType;
}
bool Tile::isRipe() {
	return plantStage == stagesRequired;
}
void Tile::reset() {
	hasPlant = false;
	plantStage = 0;
	stagesRequired = 0;
	timeRequired = 0;
}
void Tile::updatePlant(sf::Time actTime) {
	if (hasPlant) {
		if (plantStage == 0) {
			switch (plantType) {
			case PlantType::CARROT:
				plantSprite = Sprites::carrotSprites[0];
				plantSprite.setPosition(pos);
				plantStage++;
				break;
			case PlantType::CUCUMBER:
				plantSprite = Sprites::cucumberSprites[0];
				plantSprite.setPosition(pos);
				plantStage++;
				break;
			case PlantType::POTATO:
				plantSprite = Sprites::potatoSprites[0];
				plantSprite.setPosition(pos);
				plantStage++;
				break;
			case PlantType::WHEAT:
				plantSprite = Sprites::wheatSprites[0];
				plantSprite.setPosition(pos);
				plantStage++;
				break;
			}
		}
		if (actTime.asSeconds() - plantPlacedTime.asSeconds() >= timeRequired / stagesRequired && plantStage < stagesRequired) {
			plantPlacedTime = actTime;
			//TODO: randomize time a little bit to not grow equally
			switch (plantType) {
			case PlantType::CARROT:
				plantSprite = Sprites::carrotSprites[plantStage];
				plantSprite.setPosition(pos);
				break;
			case PlantType::CUCUMBER:
				plantSprite = Sprites::cucumberSprites[plantStage];
				plantSprite.setPosition(pos);
				break;
			case PlantType::POTATO:
				plantSprite = Sprites::potatoSprites[plantStage];
				plantSprite.setPosition(pos);
				break;
			case PlantType::WHEAT:
				plantSprite = Sprites::wheatSprites[plantStage];
				plantSprite.setPosition(pos);
				break;
			}
			plantStage++;
		}
	}
}
void Tile::renderTile(sf::RenderWindow& window) {
	window.draw(backgroundSprite);
	if (hasFence) {
		window.draw(fenceSprite);
	}
	if (hasPlant) {
		window.draw(plantSprite);
	}
	//Hover always on top
	if (isHovered) {
		window.draw(hoverSprite);
	}
}
