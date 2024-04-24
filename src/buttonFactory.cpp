#include "buttonFactory.h"

ButtonFactory::ButtonFactory()
{
    font.loadFromFile("SunnySpellsBasic.ttf");
    darkBlue = sf::Color(0, 0, 128);
}

sf::Text ButtonFactory::CreateText(std::string text, int fontSize, float x, float y, sf::Color color)
{
   sf::Text txt(text, font, fontSize);
   txt.setPosition(x, y);
   txt.setFillColor(color);
   return txt;
}

sf::RectangleShape ButtonFactory::CreateButton(float shapeX, float shapeY, float sizeX, float sizeY, float positionX, float positionY, sf::Color color)
{
   sf::RectangleShape button(sf::Vector2f(shapeX, shapeY));
   button.setSize(sf::Vector2f(sizeX, sizeY));
   button.setPosition(positionX, positionY ); 
   button.setFillColor(color);
   return button;
}