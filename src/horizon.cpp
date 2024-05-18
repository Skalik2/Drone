#include "horizon.hpp"

#define VERTICAL_SCALING 8

Horizon::Horizon() {
    backgroundTexture.loadFromFile("assets/frame.png");
    background.setTexture(backgroundTexture);
    planeIndicatorTexture.loadFromFile("assets/horizon_plane.png");
    planeIndicator.setTexture(planeIndicatorTexture);
    scaleTexture.loadFromFile("assets/horizon_scale.png");
    textureSprite.setScale(0.6, 0.6);
    angleTexture.loadFromFile("assets/horizon_angle.png");
    angle.setTexture(angleTexture);
    angle.setOrigin(500, 500);
    angle.setPosition(500, 500);
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
    window.draw(planeIndicator);
    window.draw(scale);
    window.draw(background);
    window.clear();
}

void Horizon::update(const SensorData& data) {
    blueShape.setRotation(data.rotation.x);
    blueShape.setPosition(500, 500 + (data.rotation.y * VERTICAL_SCALING));
    brownShape.setRotation(data.rotation.x);
    brownShape.setPosition(500, 500 + (data.rotation.y * VERTICAL_SCALING));
    scale.setRotation(data.rotation.x);
    // TODO: poprawić pozycje znacznika przechyłu
    angle.setPosition(500, 500 + (data.rotation.y * VERTICAL_SCALING));
    angle.setRotation(data.rotation.x);
}

void Horizon::draw(sf::RenderWindow& target) {
    window.clear(sf::Color(255, 255, 255));
    window.draw(blueShape);
    window.draw(brownShape);
    window.draw(scale);
    window.draw(angle);
    window.draw(planeIndicator);
    window.draw(background);
    window.display();
    textureSprite.setTexture(window.getTexture());
    textureSprite.setOrigin(500, 500);
    target.draw(textureSprite);
}