#include "Game.h"


using namespace std;
//Overloading operators
std::ostream& operator<<(std::ostream& out, const sf::Vector2f v) {
	out << "[" << v.x << ", " << v.y << "]";
	return out;
}
sf::Vector2i operator+(sf::Vector2i v1, sf::Vector2i v2) {
	return sf::Vector2i(v1.x + v2.x, v1.y + v2.y);
}

//Constructors & Destructors
Game::Game() {

}
void Game::initAll() {
	initVars();
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

float viewOffsetY = 0;
float spriteOffsetY = 0;
unsigned int textureHeight;

//Private
void Game::initVars() {
	window = nullptr;
	WIDTH = 1920; //1280
	HEIGHT = 1080; //720
	farmSize = 12;
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
}
void Game::initWindow() {
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Farmer", sf::Style::Titlebar | sf::Style::Fullscreen, sf::ContextSettings::ContextSettings(0, 0, 10, 2, 0));
	//window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window->setFramerateLimit(60);
	view.setCenter(WIDTH / 2, HEIGHT / 2);
	view.setSize(window->getDefaultView().getSize());
	window->setView(view);
}


//Public

sf::Vector2f oldPos;
sf::Vector2f newPos;
sf::Vector2f deltaPos;
sf::Vector2f viewCenter;
bool moving = false;
float zoom = 1;

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
				moving = true;
				oldPos = sf::Vector2f(mousePos);
			}
			break;
		case  sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == 0) {
				moving = false;
			}
			break;
		case sf::Event::MouseMoved:

			if (!moving) {
				break;
			}

			newPos = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
			deltaPos = oldPos - newPos;

			viewCenter = view.getCenter() + deltaPos * zoom;
			/*if (viewCenter.y > 340 && viewCenter.y < 660 && viewCenter.x > 400 && viewCenter.x < 650) {
				view.move(deltaPos * zoom);
			}*/
			view.move(deltaPos * zoom);

			//cout << view.getCenter() << endl;
			window->setView(view);

			oldPos = newPos;
			break;

			//Uncomment it when you are ready for this!!!
			// 
			//case sf::Event::MouseWheelScrolled:
			//	if (moving) {
			//		break;
			//	}

			//	if (event.mouseWheelScroll.delta <= -1)
			//		zoom = std::min(2.f, zoom + .2f);
			//	else if (event.mouseWheelScroll.delta >= 1)
			//		zoom = std::max(.6f, zoom - .2f);

			//	//Update the view
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
}

void Game::render() {

	window->clear(bgColor);

	//Drawing tiles
	for (int i = 0; i < tiles.size(); i++) {
		//Drawing
		if (tiles[i].getBg().getGlobalBounds().contains(mousePos.x * zoom + view.getCenter().x - WIDTH / 2 * zoom, mousePos.y * zoom + view.getCenter().y - HEIGHT / 2 * zoom)) {
			tiles[i].isHovered = true;
		}
		else {
			tiles[i].isHovered = false;
		}
		tiles[i].renderTile(*window);
		
	}

	window->display();
}
