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
        const int smallGridSize = 5;
        const int mediumGridSize = 10;
        const int largeGridSize = 15;
        int currentGridSize = 10;
        sf::RectangleShape easyButton;
        sf::RectangleShape mediumButton;
        sf::RectangleShape hardButton;
        sf::RectangleShape customButton;
        sf::RectangleShape minusButton;
        sf::RectangleShape plusButton;
        sf::RectangleShape backButton;
        sf::Text settingsText;
        sf::Text difficultyText;
        sf::Text easyText;
        sf::Text mediumText;
        sf::Text hardText;
        sf::Text customText;
        sf::Text sizeText;
        sf::Text minusText;
        sf::Text plusText;
        sf::Text backText;
        sf::Text chosenSizeText;
};