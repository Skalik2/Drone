#include "horizon.hpp"

Horizon::Horizon() {
    backgroundTexture.loadFromFile("assets/frame.png");
    background.setTexture(backgroundTexture);
    planeIndicatorTexture.loadFromFile("assets/horizon_plane.png");
    planeIndicator.setTexture(planeIndicatorTexture);
    scaleTexture.loadFromFile("assets/horizon_scale.png");
    scale.setTexture(scaleTexture);
    scale.setOrigin(500, 500);
    scale.setPosition(500, 500);
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
    window.draw(scale);
    window.clear();
}

void Horizon::update(const SensorData& data) {
    blueShape.setRotation(data.rotation.x);
    blueShape.setPosition(500, 500 + data.rotation.y);
    brownShape.setRotation(data.rotation.x);
    brownShape.setPosition(500, 500 + data.rotation.y);
    scale.setRotation(data.rotation.x);
}

void Horizon::draw(sf::RenderWindow& target) {
    window.clear(sf::Color(255, 255, 255));
    window.draw(blueShape);
    window.draw(brownShape);
    window.draw(scale);
    window.draw(background);
    window.draw(planeIndicator);

    window.display();
    textureSprite.setTexture(window.getTexture());
    textureSprite.setScale(0.75, 0.75);
    target.draw(textureSprite);
}