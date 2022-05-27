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

void Game::updateQuantitiesOfItems() {
	//Updating quantities of items
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			if (isItemChosen && inventory.itemSlots[j * 8 + i].getItem().getTexture() == itemChosenSprite.getTexture()) {
				if (inventory.itemSlots[j * 8 + i].getQuantity() != itemChosenQuantityNumber) {
					if (itemChosenQuantityNumber == 0) {
						inventory.itemSlots[j * 8 + i].removeItem();
					}
					else {
						inventory.itemSlots[j * 8 + i].setQuantity(itemChosenQuantityNumber);
					}
				}
				break;
			}
		}
	}
}
void Game::updateBalance(int amount) {
	balance += amount;
	balanceDisp.setString(std::to_string(balance) + "$");
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
	sickleToolSprite = Sprites::sickleToolSprite;
	sickleToolSprite.setPosition(WIDTH - 240, HEIGHT - 80);
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

	//Init icon
	icon.loadFromFile("assets/textures/icon.png");

	//Setting coin animation and money stuff
	balance = 0;
	coinTexture.loadFromFile("assets/textures/coins.png");
	coinSprite.setTexture(coinTexture);
	coinSprite.setPosition(20.f, 20.f);
	coinAnim = Animation(coinTexture, sf::Vector2u(8, 1), 0.1f);
	balanceDisp.setFont(Resources::quantityDisplayFont);
	balanceDisp.setCharacterSize(36);
	balanceDisp.setFillColor(sf::Color::White);
	updateBalance(100);
}
void Game::initWindow() {
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Farmer", sf::Style::Titlebar | sf::Style::Fullscreen, sf::ContextSettings::ContextSettings(0, 0, 10, 2, 0));
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window->setFramerateLimit(60);
	view.setCenter(WIDTH / 2, HEIGHT / 2);
	view.setSize(window->getDefaultView().getSize());
	
	//Set the farm view to center of screen and relative other things
	view.move(-300, 0);
	handToolSprite.setPosition(getRightDownCorner().x - 80, getRightDownCorner().y - 80);
	shovelToolSprite.setPosition(getRightDownCorner().x - 160, getRightDownCorner().y - 80);
	sickleToolSprite.setPosition(getRightDownCorner().x - 240, getRightDownCorner().y - 80);
	itemChosenSprite.setPosition(getRightDownCorner().x - 80, getRightDownCorner().y - 160);
	itemChosenQuantity.setPosition(getRightDownCorner().x - 80 + 60, getRightDownCorner().y - 160 + 60);
	coinSprite.setPosition(getLeftUpCorner().x + 20, getLeftUpCorner().y + 20);
	balanceDisp.setPosition(getLeftUpCorner().x + 60, getLeftUpCorner().y + 10);
	
	//Set the view to window
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
	case 3:
		toolPointerSprite.setPosition(getRightDownCorner().x - 240, getRightDownCorner().y - 80);
		break;
	}
}
void Game::setupInventory() {
	shopCards.emplace_back(ShopCard(Sprites::carrotSeedsSprite, "Carrot Seeds"));
	shopCards[0].setDescr(L"Well, seeds of a carrot, what to say more?");
	shopCards.emplace_back(ShopCard(Sprites::cucumberSeedsSprite, "Cucumber Seeds"));
	shopCards[1].setDescr(L"Interesting seeds of a cucumber, remember to water it often!");
	shopCards.emplace_back(ShopCard(Sprites::potatoSeedsSprite, "Potato"));
	shopCards[2].setDescr(L"Yes, that's a potato, it can be just shoved into soil.");
	shopCards.emplace_back(ShopCard(Sprites::wheatSeedsSprite, "Wheat"));
	shopCards[3].setDescr(L"Yayy! Wheee(a)t!");
}

//Public
bool clickedElse = true;


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
						updateQuantitiesOfItems();
					}

					//Setting up position of shop cards
					shopCards[0].setPosition(inventory.getMainPosition() + sf::Vector2f(150, 250));
					shopCards[1].setPosition(inventory.getMainPosition() + sf::Vector2f(370, 250));
					shopCards[2].setPosition(inventory.getMainPosition() + sf::Vector2f(590, 250));
					shopCards[3].setPosition(inventory.getMainPosition() + sf::Vector2f(810, 250));


					isInventoryOpen = !isInventoryOpen;
				}
				else {
					isInventoryOpen = !isInventoryOpen;
				}
			}
			break;

		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == 0) {
				//Garden stuff, farming ect
				switch (toolChosen) {
				case 1: 
					//Shovel in hand
					//Check if mouse is still over this particular Tile, then change the background
					if (tiles[whichTileHovered].getBg().getGlobalBounds().contains(relMousePos.x, relMousePos.y)) {
						tiles[whichTileHovered].setBg(Sprites::soil0Sprite);
					}
					break;
				case 2: 
					//Seed in hand
					if (tiles[whichTileHovered].getBg().getGlobalBounds().contains(relMousePos.x, relMousePos.y) && 
						tiles[whichTileHovered].getBg().getTexture() == Sprites::soil0Sprite.getTexture() && !tiles[whichTileHovered].hasPlant) {
						if (itemChosenSprite.getTexture() == Sprites::carrotSeedsSprite.getTexture()) {
							tiles[whichTileHovered].setPlant(PlantType::CARROT, 4, clock.getElapsedTime(), 4);
						}
						else if (itemChosenSprite.getTexture() == Sprites::cucumberSeedsSprite.getTexture()) {
							tiles[whichTileHovered].setPlant(PlantType::CUCUMBER, 4, clock.getElapsedTime(), 4);
						}
						else if (itemChosenSprite.getTexture() == Sprites::potatoSeedsSprite.getTexture()) {
							tiles[whichTileHovered].setPlant(PlantType::POTATO, 4, clock.getElapsedTime(), 4);
						}
						else if (itemChosenSprite.getTexture() == Sprites::wheatSeedsSprite.getTexture()) {
							tiles[whichTileHovered].setPlant(PlantType::WHEAT, 4, clock.getElapsedTime(), 4);
						}
						itemChosenQuantityNumber--;
						itemChosenQuantity.setString(std::to_string(itemChosenQuantityNumber));
						tiles[whichTileHovered].updatePlant(clock.getElapsedTime());
						updateQuantitiesOfItems();
					}
					if (itemChosenQuantityNumber == 0) {
						toolChosen = 0;
						isItemChosen = false;
						itemChosenQuantity.setString("");
					}
					break;
				case 3: 
					//Collecting plants
					if (tiles[whichTileHovered].getBg().getGlobalBounds().contains(relMousePos.x, relMousePos.y) && tiles[whichTileHovered].hasPlant && tiles[whichTileHovered].isRipe()) {

						// TODO: ANIMATION OF SICKLE CUTTING 
						switch (tiles[whichTileHovered].getPlant()) {
						case PlantType::CARROT:
							inventory.addItem(Item(Sprites::carrotSprites[4], 1));
							break;
						case PlantType::CUCUMBER:
							inventory.addItem(Item(Sprites::cucumberSprites[4], 1));
							break;
						case PlantType::POTATO:
							inventory.addItem(Item(Sprites::potatoSeedsSprite, ((rand() % 100) < 75) ? 1 : 2));
							break;
						case PlantType::WHEAT:
							inventory.addItem(Item(Sprites::wheatSprites[4], 1));
							inventory.addItem(Item(Sprites::wheatSeedsSprite, ((rand() % 100) < 60) ? 0 : 1));
							break;
						}
						tiles[whichTileHovered].reset();
					}
				}

				//Inventory mouse events
				if (isInventoryOpen) {
					inventory.checkTabChanged(relMousePos);

					//Inventory
					if (inventory.whichTabActive == 0) {
						for (auto& i : inventory.itemSlots) {
							if (i.getItem().getGlobalBounds().contains(relMousePos.x, relMousePos.y) && i.getItem().getTexture() != Sprites::plantSprite.getTexture()) {
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
						

						for (auto& i : shopCards) {

							if (i.getSelected()) {
								//Change item amount
								if (inventory.itemChangeAmountSprite.getGlobalBounds().contains(relMousePos.x, relMousePos.y)) {
									//std::cout << "change" << std::endl;
									inventory.changeItemAmount(relMousePos);
									continue;
								}
								else {
									clickedElse = true;
								}

								if (inventory.buyButtonSprite.getGlobalBounds().contains(relMousePos.x, relMousePos.y)) {
									inventory.addItem(Item(i.getItem(), inventory.currentItemAmount));
									updateBalance(-inventory.currentItemAmount);
									inventory.whichTabActive = 0;
								}
								else {
									clickedElse = true;
								}
							}

							//Select one of the cards
							if (i.cardBackgroundSprite.getGlobalBounds().contains(relMousePos.x, relMousePos.y)) {
								inventory.currentItemAmount = 10;
								i.setSelected(true);
								inventory.activateBuyButton(true);
								clickedElse = false;
							}

							
							

							if (clickedElse) {
								i.setSelected(false);
								inventory.activateBuyButton(false);
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
					if (sickleToolSprite.getGlobalBounds().contains(relMousePos.x, relMousePos.y)) {
						toolChosen = 3;
						isItemChosen = false;
					}
				}
				
			}

			// Move for right button
			else if (event.mouseButton.button == 1 && !isInventoryOpen) { 
				moving = true;
				oldPos = sf::Vector2f(mousePos);
			}
			break;

		case  sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == 1) {
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
			sickleToolSprite.setPosition(getRightDownCorner().x - 240, getRightDownCorner().y - 80);
			itemChosenSprite.setPosition(getRightDownCorner().x - 80, getRightDownCorner().y - 160);
			itemChosenQuantity.setPosition(getRightDownCorner().x - 80 + 60, getRightDownCorner().y - 160 + 60);
			coinSprite.setPosition(getLeftUpCorner().x + 20, getLeftUpCorner().y + 20);
			balanceDisp.setPosition(getLeftUpCorner().x + 60, getLeftUpCorner().y + 10);
			
			//Setting view
			window->setView(view);

			//Recalculating position
			oldPos = newPos;
			break;
		}
	}
}

void Game::frameUpdate() {
	pollEvents();
	updateMousePosition();
	updateTools();
	deltaTime = clockDelta.restart().asSeconds();
	nextTime = clock.getElapsedTime();
	if (nextTime.asMilliseconds() - lastTime.asMilliseconds() >= 1000) {
		for (auto& i : tiles) {
			i.updatePlant(clock.getElapsedTime());
		}
		lastTime = clock.getElapsedTime();
	}

	//Update coin animation
	coinAnim.update(0, deltaTime);
	coinSprite.setTextureRect(coinAnim.uvRect);
	
}

void Game::render() {

	window->clear(bgColor);

	renderTiles();
	renderTools();
	renderMoney();
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
	window->draw(sickleToolSprite);
	window->draw(toolPointerSprite);
	if (isItemChosen) {
		window->draw(itemChosenSprite);
		window->draw(itemChosenQuantity);
	}
}

void Game::renderInventory() {

	//If inventory is active, darken the background behind.
	darken.setFillColor(sf::Color(0, 0, 0, 120));
	darken.setPosition(getLeftUpCorner());
	window->draw(darken);

	//Render inventory
	inventory.renderInventory(*window);

	//Inventory
	if (inventory.whichTabActive == 0) {
		for (auto& i : inventory.itemSlots) {
			i.renderItem(*window);
		}
	}

	//Shop
	if (inventory.whichTabActive == 1) {
		for (auto& i : shopCards) {
			i.renderCard(*window);
		}
	}
}

void Game::renderMoney() {
	window->draw(coinSprite);
	window->draw(balanceDisp);
}