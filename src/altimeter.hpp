#ifndef ALT_HPP
#define ALT_HPP

#include <SFML/Graphics.hpp>
#include "data.hpp"

struct Altimeter {
	sf::RenderTexture window;
	sf::Sprite altiSprite, arrowSprite, windowSprite;
	sf::Texture altiTexture, arrowTexture;

	Altimeter();
	void update(const SensorData &data);
	void draw(sf::RenderWindow& target);
};

inline Altimeter altimeter;

#endif //SENSOR_OBJECTS_HPP
