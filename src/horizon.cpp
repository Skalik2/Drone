#include "horizon.hpp"

Horizon::Horizon() {
    backgroundTexture.loadFromFile("assets/frame.png");
    background.setTexture(backgroundTexture);
    planeIndicatorTexture.loadFromFile("assets/horizon_plane.png");
    planeIndicator.setTexture(planeIndicatorTexture);
    planeIndicator.setOrigin(250, 50);
    planeIndicator.setPosition(500, 500);
    window.create(1000, 1000);
    window.clear(sf::Color(48, 48, 48));
    blueShape.setFillColor(sf::Color(127, 138, 217));
    blueShape.setSize(sf::Vector2f(10000, 10000));
    blueShape.setOrigin(5000, 10000);
    blueShape.setPosition(500, 500);
    brownShape.setFillColor(sf::Color(167, 117, 42));
    brownShape.setSize(sf::Vector2f(10000, 10000));
    brownShape.setOrigin(5000, 0);
    brownShape.setPosition(500, 500);
    window.draw(blueShape);
    window.draw(brownShape);
    window.draw(background);
    window.draw(planeIndicator);
    window.clear();
}

void Horizon::update(const SensorData& data) {
    blueShape.setRotation(data.rotation.x);
    blueShape.setPosition(500, 500 + data.rotation.y);
    brownShape.setRotation(data.rotation.x);
    brownShape.setPosition(500, 500 + data.rotation.y);
}

void Horizon::draw(sf::RenderWindow& target) {
    window.clear(sf::Color(48, 48, 48));
    window.draw(blueShape);
    window.draw(brownShape);
    window.draw(background);
    window.draw(planeIndicator);
    window.display();
    textureSprite.setTexture(window.getTexture());
    textureSprite.setScale(0.5, 0.5);
    target.draw(textureSprite);
}