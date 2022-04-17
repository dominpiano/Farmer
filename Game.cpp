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

//Constructors & Destructors
Game::Game() {

}
void Game::initAll() {
	initVars();
	initSpritesUI();
	updateFarmSize();
	initWindow();
}
Game::~Game() {
	delete this->window;
}

//Getters Accessors
const bool Game::isWindowOpen() {
	return this->window->isOpen();
}


//Private
void Game::initVars() {
	window = nullptr;
	WIDTH = 1920;
	HEIGHT = 1080;
	farmSize = 12;
	sf::Sprite tmp;
	for (int i = -2; i < 16; i++) {
		for (int j = -8; j < 20; j++) {
			tmp = Sprites::grassSprite;
			tmp.setPosition(j * 100, i * 100);
			backGround.emplace_back(tmp);
		}
	}
}

void Game::initSpritesUI() {
	shovelSprite = Sprites::shovelSprite;
	shovelSprite.setPosition(WIDTH - 80, HEIGHT - 80);
}

void Game::initWindow() {
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Farmer", sf::Style::Titlebar | sf::Style::Fullscreen, sf::ContextSettings::ContextSettings(0, 0, 10, 2, 0));
	//window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window->setFramerateLimit(60);
	view.setCenter(WIDTH / 2, HEIGHT / 2);
	view.setSize(window->getDefaultView().getSize());
	window->setView(view);
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
		break;

	case 1:
		toolChooseSprite = Sprites::hoverSprite;
		toolChooseSprite.setScale(0.8f, 0.8f);
		toolChooseSprite.setPosition(getRightDownCorner().x - 80, getRightDownCorner().y - 80);
	}
}

//Public

void Game::pollEvents() {

	while (this->window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) {
				window->close();
			}
			break;

		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == 0) {
				//Tool check
				if (shovelSprite.getGlobalBounds().contains(relMousePos.x, relMousePos.y)) {
					toolChosen = 1;
				}
				moving = true;
				oldPos = sf::Vector2f(mousePos);
			}
			else if (event.mouseButton.button == 1) {
				toolChosen = 0;
			}
			break;

		case  sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == 0) {
				switch (toolChosen) {
				case 1:
					//Check if mouse is still over this particular Tile, then change the background
					if (tiles[whichTileHovered].getBg().getGlobalBounds().contains(relMousePos.x, relMousePos.y)) {
						tiles[whichTileHovered].setBg(Sprites::soil0Sprite);
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
			shovelSprite.setPosition(getRightDownCorner().x - 80, getRightDownCorner().y - 80);
			
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
}

void Game::render() {

	window->clear(bgColor);

	renderTiles();
	renderTools();

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
		if (tiles[i].getBg().getGlobalBounds().contains(relMousePos.x, relMousePos.y) && !moving && !tiles[i].hasFence) {
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
	window->draw(shovelSprite);
	if (toolChosen != 0) {
		window->draw(toolChooseSprite);
	}
}