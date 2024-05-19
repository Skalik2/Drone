#include "vertical.hpp"

Vertical::Vertical() {
    arrowTexture.loadFromFile("assets/verticalSpeedArrow.png");
    arrow.setTexture(arrowTexture);
    backTexture.loadFromFile("assets/verticalSpeed.png");
    back.setTexture(backTexture);
    arrow.setOrigin(500, 500);
    arrow.setPosition(500, 500);

    window.create(1000, 1000);
    window.clear(sf::Color(48, 48, 48));

    window.draw(back);
    window.draw(arrow);
    window.display();
}

void Vertical::update(const SensorData& data) {
    arrow.setRotation((data.verticalVelocity));
}

void Vertical::draw(sf::RenderWindow& target) {
    window.clear(sf::Color(48, 48, 48));
    window.draw(back);
    window.draw(arrow);
    window.display();
    windowSprite.setTexture(window.getTexture());
    windowSprite.setOrigin(500, 500);
    windowSprite.setScale(0.5, 0.5);
    target.draw(windowSprite);
}