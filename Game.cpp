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
	initTextures();
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
	WIDTH = 1280; //1280
	HEIGHT = 720; //720
	farmSize = 10;
}
void Game::initTextures() {
	//Background
	bgTexture.loadFromFile("assets/grass.png");
	bgSprite.setTexture(bgTexture);
	//Hover indicator
	hoverTexture.loadFromFile("assets/hoverIndicate.png");
	hoverSprite.setTexture(hoverTexture);
}
int counter = 1;
void Game::updateFarmSize() {
	for (int i = 0; i < farmSize; i++) {
		for (int j = 0; j < farmSize; j++) {
			counter++;
			if (counter > tiles.size()){
				tiles.emplace_back(bgSprite);
				tiles[i * farmSize + j].setPosition(j * 100, i * 100);
				hoverIndicators.emplace_back(hoverSprite);
				hoverIndicators[i * farmSize + j].setPosition(j * 100, i * 100);
			}
		}
	}
}
void Game::updateMousePosition() {
	mousePos = sf::Mouse::getPosition(*window);
}
void Game::initWindow() {
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Farmer", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings::ContextSettings(0, 0, 10, 2, 0));
	//window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window->setFramerateLimit(30);
	view.setCenter(WIDTH/2, HEIGHT/2);
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

			viewCenter = view.getCenter() + deltaPos;
			if (viewCenter.y > 340 && viewCenter.y < 660 && viewCenter.x > 400 && viewCenter.x < 650) {
				view.move(deltaPos * zoom);
			}

			cout << view.getCenter() << endl;
			window->setView(view);

			oldPos = newPos;
			break;

		case sf::Event::MouseWheelScrolled:
			if (moving) {
				break;
			}

			if (event.mouseWheelScroll.delta <= -1)
				zoom = std::min(4.f, zoom + .2f);
			else if (event.mouseWheelScroll.delta >= 1)
				zoom = std::max(.2f, zoom - .2f);

			//Update the view
			view.setSize(window->getDefaultView().getSize());
			view.zoom(zoom);
			window->setView(view);
			break;
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
		window->draw(tiles[i]);
		if (tiles[i].getGlobalBounds().contains(mousePos.x * zoom + view.getCenter().x - WIDTH/2 * zoom, mousePos.y * zoom + view.getCenter().y - HEIGHT/2 * zoom)) {
			if (!moving) {
				window->draw(hoverIndicators[i]);
			}
		}
		
		
	}

	window->display();
}