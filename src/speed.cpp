#include "speed.hpp"

Speed::Speed() {
    arrowTexture.loadFromFile("assets/AirSpeedArrow.png");
    arrow.setTexture(arrowTexture);
    backTexture.loadFromFile("assets/AirSpeed.png");
    back.setTexture(backTexture);
    arrow.setOrigin(500, 500);
    arrow.setPosition(500, 500);

    window.create(1000, 1000);
    window.clear(sf::Color(48, 48, 48));

    window.draw(back);
    window.draw(arrow);
    window.display();
}

void Speed::update(const SensorData& data) {
    arrow.setRotation((data.horizontalVelocity));
}

void Speed::draw(sf::RenderWindow& target) {
    window.clear(sf::Color(48, 48, 48));
    window.draw(back);
    window.draw(arrow);
    window.display();
    windowSprite.setTexture(window.getTexture());
    windowSprite.setOrigin(500, 500);
    windowSprite.setScale(0.35, 0.35);
    target.draw(windowSprite);
}