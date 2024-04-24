#include <SFML/Graphics.hpp>
#ifndef buttonFactory
#define buttonFactory

using namespace sf;

class ButtonFactory
{
    public:
    ButtonFactory();
    sf::Text CreateText(std::string text, int fontSize, float x, float y, sf::Color color);
    sf::RectangleShape CreateButton(float shapeX, float shapeY, float sizeX, float sizeY, float positionX, float positionY, sf::Color color);
    sf::Font font;
    sf::Color darkBlue;
};

#endif