#include "altimeter.hpp"

Altimeter::Altimeter() {
	altiTexture.loadFromFile("assets/altitude.png");
	altiSprite.setTexture(altiTexture);
	arrowTexture.loadFromFile("assets/altitudeArrow.png");
	arrowSprite.setTexture(arrowTexture);
	arrowSprite.setOrigin(500, 500);
	arrowSprite.setPosition(500, 500);


	window.create(1000, 1000);
	window.clear(sf::Color(48, 48, 48));

	window.draw(altiSprite);
	window.draw(arrowSprite);
	window.display();
}

void Altimeter::update(const SensorData& data) {
	arrowSprite.setRotation( (data.altitude * 18.f / 1000.f));
}

void Altimeter::draw(sf::RenderWindow& target) {
	window.clear(sf::Color(48,48,48));
	window.draw(altiSprite);
	window.draw(arrowSprite);
	window.display();
	windowSprite.setTexture(window.getTexture());
	windowSprite.setOrigin(500, 500);
	windowSprite.setScale(0.5, 0.5);
	target.draw(windowSprite);
}