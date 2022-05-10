#include "Game.h"

using namespace std;

//HELPING FUNCTIONS

//Overloading operators
std::ostream& operator<<(std::ostream& out, const sf::Vector2f v) {
	out << "[" << v.x << ", " << v.y << "]";
	return out;
}
sf::Vector2i operator+(sf::Vector2i v1, sf::Vector2i v2) {
	return sf::Vector2i(v1.x + v2.x, v1.y + v2.y);
}
sf::Vector2f Game::getRightDownCorner() {
	return sf::Vector2f(view.getCenter().x + WIDTH / 2, view.getCenter().y + HEIGHT / 2);
}
sf::Vector2f Game::getLeftUpCorner() {
	return sf::Vector2f(view.getCenter().x - WIDTH / 2, view.getCenter().y - HEIGHT / 2);
}

//Constructors & Destructors
Game::Game() {

}
void Game::initAll() {
	initVars();
	initSpritesUI();
	updateFarmSize();
	setupInventory();
	initWindow();
}
Game::~Game() {
	delete this->window;
}

void Game::initSpritesUI() {
	//Tools
	toolPointerSprite = Sprites::hoverSprite;
	toolPointerSprite.setScale(0.8f, 0.8f);
	handToolSprite = Sprites::handToolSprite;
	handToolSprite.setPosition(WIDTH - 80, HEIGHT - 80);
	shovelToolSprite = Sprites::shovelToolSprite;
	shovelToolSprite.setPosition(WIDTH - 160, HEIGHT - 80);
}
void Game::initVars() {
	window = nullptr;
	WIDTH = 1920;
	HEIGHT = 1080;
	farmSize = 12;
	//Setting background
	sf::Sprite tmp;
	for (int i = -2; i < 16; i++) {
		for (int j = -8; j < 20; j++) {
			tmp = Sprites::grassSprite;
			tmp.setPosition(j * 100, i * 100);
			backGround.emplace_back(tmp);
		}
	}
	lastTime = clock.getElapsedTime();
}
void Game::initWindow() {
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Farmer", sf::Style::Titlebar | sf::Style::Fullscreen, sf::ContextSettings::ContextSettings(0, 0, 10, 2, 0));
	//window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window->setFramerateLimit(60);
	view.setCenter(WIDTH / 2, HEIGHT / 2);
	view.setSize(window->getDefaultView().getSize());
	window->setView(view);
}

//Getters Accessors
const bool Game::isWindowOpen() {
	return this->window->isOpen();
}

int counter = 1;
int counterSize = 0;
void Game::updateFarmSize() {
	for (int i = 0; i < farmSize; i++) {
		for (int j = 0; j < farmSize; j++) {
			//For enlarging farmSize
			if (counter > tiles.size()) {

				//Create Tile
				tiles.emplace_back(Tile(sf::Vector2f(j * 100, i * 100)));

				//Fence placing
				if (i == 0 || i == farmSize - 1 || j == 0 || j == farmSize - 1) {
					if (i == 0 && j == 0 || i == 0 && j == farmSize - 1 || i == farmSize - 1 && j == 0 || i == farmSize - 1 && j == farmSize - 1) {
						if (i == 0 && j == 0) {
							tiles[counterSize].setFence(Sprites::fenceAngleSprite, 0);
						}
						if (i == 0 && j == farmSize - 1) {
							tiles[counterSize].setFence(Sprites::fenceAngleSprite, 90);
						}
						if (i == farmSize - 1 && j == farmSize - 1) {
							tiles[counterSize].setFence(Sprites::fenceAngleSprite, 180);
						}
						if (i == farmSize - 1 && j == 0) {
							tiles[counterSize].setFence(Sprites::fenceAngleSprite, -90);
						}
					}
					else {
						if (i > 0 && j == 0) {
							tiles[counterSize].setFence(Sprites::fenceSprite, 0);
						}
						if (i == 0 && j > 0) {
							tiles[counterSize].setFence(Sprites::fenceSprite, 90);
						}
						if (i > 0 && j == farmSize - 1) {
							tiles[counterSize].setFence(Sprites::fenceSprite, 180);
						}
						if (i == farmSize - 1 && j < farmSize - 1) {
							tiles[counterSize].setFence(Sprites::fenceSprite, -90);
						}
					}
				}
			}
			counter++;
			counterSize++;
		}
	}
}
void Game::updateMousePosition() {
	mousePos = sf::Mouse::getPosition(*window);
	relMousePos.x = mousePos.x * zoom + view.getCenter().x - WIDTH / 2 * zoom;
	relMousePos.y = mousePos.y* zoom + view.getCenter().y - HEIGHT / 2 * zoom;
}
void Game::updateTools() {
	switch (toolChosen) {
	case 0:
		toolPointerSprite.setPosition(getRightDownCorner().x - 80, getRightDownCorner().y - 80);
		break;
	case 1:
		toolPointerSprite.setPosition(getRightDownCorner().x - 160, getRightDownCorner().y - 80);
		break;
	case 2:
		toolPointerSprite.setPosition(getRightDownCorner().x - 80, getRightDownCorner().y - 160);
		break;
	}
}
void Game::setupInventory() {
	shopCards.emplace_back(ShopCard(Sprites::carrotSeedsSprite, "Carrot Seeds"));
	shopCards[0].setDescr(L"Well, seeds of a carrot, what to say more?");
	shopCards.emplace_back(ShopCard(Sprites::cucumberSeedsSprite, "Cucumber Seeds"));
	shopCards[1].setDescr(L"Interesting seeds of a cucumber, remember to water it often!");
}

//Public

void Game::pollEvents() {

	while (this->window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			//Keys pressed
			if (event.key.code == sf::Keyboard::Escape) {
				if (isInventoryOpen) {
					isInventoryOpen = false;
				}
				else {
					window->close();
				}
			}
			else if (event.key.code == sf::Keyboard::E) {
				if (!isInventoryOpen) {
					inventory.updatePosition(view.getCenter());
					//Only if inventory is in INVENTORY mode
					if (inventory.whichTabActive == 0) {
						//Setting item and frames position
						for (int i = 0; i < 8; i++) {
							for (int j = 0; j < 3; j++) {
								inventory.itemSlots[j * 8 + i].setItemPos(inventory.getMainPosition().x + i * 120 + 100, inventory.getMainPosition().y + j * 120 + 250);
								if (inventory.itemSlots[j * 8 + i].getQuantity() != itemChosenQuantityNumber) {
									if (inventory.itemSlots[j * 8 + i].getItem().getTexture() == itemChosenSprite.getTexture()) {
										inventory.itemSlots[j * 8 + i].setQuantity(itemChosenQuantityNumber);
									}
								}
							}
						}
					}

					//Setting up position of shop cards
					shopCards[0].setPosition(inventory.getMainPosition() + sf::Vector2f(40, 240));
					shopCards[1].setPosition(inventory.getMainPosition() + sf::Vector2f(260, 240));


					isInventoryOpen = !isInventoryOpen;
				}
				else {
					isInventoryOpen = !isInventoryOpen;
				}
			}
			break;

		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == 0) {

				//Inventory mouse events
				if (isInventoryOpen) {
					inventory.checkTabChanged(relMousePos);

					//Inventory
					if (inventory.whichTabActive == 0) {
						for (auto& i : inventory.itemSlots) {
							if (i.getItem().getGlobalBounds().contains(relMousePos.x, relMousePos.y)) {
								//Set position of chosen item
								itemChosenSprite = i.getItem();
								itemChosenSprite.setPosition(getRightDownCorner().x - 80, getRightDownCorner().y - 160);
								//Get quantity and set its position for rendering
								itemChosenQuantityNumber = i.getQuantity();
								itemChosenQuantity = i.getQuantityDisplay();
								itemChosenQuantity.setPosition(getRightDownCorner().x - 80 + 60, getRightDownCorner().y - 160 + 60);
								toolChosen = 2;
								isItemChosen = true;
								isInventoryOpen = false;
							}
						}
					}

					//Shop
					if (inventory.whichTabActive == 1) {
						inventory.activateBuyButton(false);
						for (auto& i : shopCards) {
							//Buy item if clicked
							if (inventory.buyButtonSprite.getGlobalBounds().contains(relMousePos.x, relMousePos.y) && i.getSelected()) {
								for (int j = 0; j < 24; j++) {
									if (!inventory.itemSlots[j].slotHasItem) {
										inventory.itemSlots[j].setItem(i.getItem());
										inventory.itemSlots[j].setQuantity(10);
										inventory.itemSlots[j].slotHasItem = true;
										break;
									}
									else if (inventory.itemSlots[j].getItem().getTexture() == i.getItem().getTexture()) {
										inventory.itemSlots[j].setQuantity(inventory.itemSlots[j].getQuantity() + 10);
										itemChosenQuantity = inventory.itemSlots[j].getQuantityDisplay();
										itemChosenQuantityNumber = inventory.itemSlots[j].getQuantity();
										break;
									}
								}
								inventory.whichTabActive = 0;
							}
							i.setSelected(false);
							if (i.cardBackgroundSprite.getGlobalBounds().contains(relMousePos.x, relMousePos.y)) {
								i.setSelected(true);
								inventory.activateBuyButton(true);
							}
						}
					}
				}
				//We don't want to move if inventory is opened
				else {
					//Tool check
					if (handToolSprite.getGlobalBounds().contains(relMousePos.x, relMousePos.y)) {
						toolChosen = 0;
						isItemChosen = false;
					}
					if (shovelToolSprite.getGlobalBounds().contains(relMousePos.x, relMousePos.y)) {
						toolChosen = 1;
						isItemChosen = false;
					}
					moving = true;
					oldPos = sf::Vector2f(mousePos);
				}
			}

			// Unclick all items/tools
			else if (event.mouseButton.button == 1) { 
				toolChosen = 0;
				isItemChosen = false;
			}
			break;

		case  sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == 0) {
				switch (toolChosen) {
				case 1: //Shovel in hand
					//Check if mouse is still over this particular Tile, then change the background
					if (tiles[whichTileHovered].getBg().getGlobalBounds().contains(relMousePos.x, relMousePos.y) && newPos != oldPos) {
						tiles[whichTileHovered].setBg(Sprites::soil0Sprite);
					}
					break;
				case 2: //Seed in hand
					if (tiles[whichTileHovered].getBg().getTexture() == Sprites::soil0Sprite.getTexture()) {
						if (itemChosenSprite.getTexture() == Sprites::carrotSeedsSprite.getTexture()) {
							tiles[whichTileHovered].setPlant(PlantType::CARROT, 5, clock.getElapsedTime(), 50);
						}
						itemChosenQuantityNumber--;
						itemChosenQuantity.setString(std::to_string(itemChosenQuantityNumber));
						tiles[whichTileHovered].updatePlant(clock.getElapsedTime());
					}
					break;
				}
				moving = false;
			}
			break;

		case sf::Event::MouseMoved:

			//Do nothing until mouse button is pressed
			if (!moving) {
				break;
			}

			//Calculating delta to know how much to move
			newPos = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
			deltaPos = oldPos - newPos;

			viewCenter = view.getCenter() + deltaPos * zoom;
			if (viewCenter.y > 400 && viewCenter.y < 800 && viewCenter.x > 200 && viewCenter.x < 1000) {
				view.move(deltaPos * zoom);
			}

			//Setting Tools Sprites Positions
			handToolSprite.setPosition(getRightDownCorner().x - 80, getRightDownCorner().y - 80);
			shovelToolSprite.setPosition(getRightDownCorner().x - 160, getRightDownCorner().y - 80);
			itemChosenSprite.setPosition(getRightDownCorner().x - 80, getRightDownCorner().y - 160);
			itemChosenQuantity.setPosition(getRightDownCorner().x - 80 + 60, getRightDownCorner().y - 160 + 60);
			
			//Setting view
			window->setView(view);
			//Recalculating position
			oldPos = newPos;
			break;

			//Uncomment it when you are ready for this!!!
			 
			//case sf::Event::MouseWheelScrolled:
			//	if (moving) {
			//		break;
			//	}

			//	if (event.mouseWheelScroll.delta <= -1)
			//		zoom = std::min(2.f, zoom + .2f);
			//	else if (event.mouseWheelScroll.delta >= 1)
			//		zoom = std::max(1.f, zoom - .2f);

			//	//Update 
			//	view.setSize(window->getDefaultView().getSize());
			//	view.zoom(zoom);
			//	window->setView(view);
			//	break;
		}
	}
}

void Game::frameUpdate() {
	pollEvents();
	updateMousePosition();
	updateTools();
	nextTime = clock.getElapsedTime();
	if (nextTime.asMilliseconds() - lastTime.asMilliseconds() >= 1000) {
		for (auto& i : tiles) {
			i.updatePlant(clock.getElapsedTime());
		}
		lastTime = clock.getElapsedTime();
	}
	
}

void Game::render() {

	window->clear(bgColor);

	renderTiles();
	renderTools();
	if (isInventoryOpen) {
		renderInventory();
	}

	window->display();
}

void Game::renderTiles() {
	//Render background
	for (auto &s : backGround) {
		window->draw(s);
	}

	//Drawing tiles
	for (int i = 0; i < tiles.size(); i++) {
		//Drawing
		if (tiles[i].getBg().getGlobalBounds().contains(relMousePos.x, relMousePos.y) && !moving && !tiles[i].hasFence && !isInventoryOpen) {
			tiles[i].isHovered = true;
			whichTileHovered = i;
		}
		else {
			tiles[i].isHovered = false;
		}
		tiles[i].renderTile(*window);

	}
}
void Game::renderTools() {
	window->draw(handToolSprite);
	window->draw(shovelToolSprite);
	window->draw(toolPointerSprite);
	if (isItemChosen) {
		window->draw(itemChosenSprite);
		window->draw(itemChosenQuantity);
	}
}

void Game::renderInventory() {
	inventory.renderInventory(*window);

	//Inventory
	if (inventory.whichTabActive == 0) {
		for (auto& i : inventory.itemSlots) {
			i.renderItem(*window);
		}
	}

	//Shop
	if (inventory.whichTabActive == 1) {
		shopCards[0].renderCard(*window);
		shopCards[1].renderCard(*window);
	}
}