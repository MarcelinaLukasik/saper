#include <SFML/Graphics.hpp>
#include "buttonFactory.h"

using namespace sf;

class Settings : public ButtonFactory
{
    
    public:
        Settings(RenderWindow *app);
        void HandleEvents(int x, int y, RenderWindow *app, Event e);
        void Display(RenderWindow *app);
        void SetCurrentMode(int modeNumber);
        int status;
        bool open;
        bool isCustom;
        const int smallGridSize = 5;
        const int mediumGridSize = 10;
        const int largeGridSize = 15;
        int currentGridSize = 10;
        int minesCount = 10;
        sf::RectangleShape easyButton;
        sf::RectangleShape mediumButton;
        sf::RectangleShape hardButton;
        sf::RectangleShape customButton;
        sf::RectangleShape sizeMinusButton;
        sf::RectangleShape sizePlusButton;
        sf::RectangleShape minesMinusButton;
        sf::RectangleShape minesPlusButton;
        sf::RectangleShape backButton;
        sf::Text settingsText;
        sf::Text difficultyText;
        sf::Text easyText;
        sf::Text mediumText;
        sf::Text hardText;
        sf::Text customText;
        sf::Text sizeText;
        sf::Text sizeMinusText;
        sf::Text sizePlusText;
        sf::Text minesMinusText;
        sf::Text minesPlusText;
        sf::Text backText;
        sf::Text chosenSizeText;
        sf::Text chosenMinesText;
        sf::Text minesText;
};