#include <SFML/Graphics.hpp>
#include "buttonFactory.h"

using namespace sf;

class MainMenu : public ButtonFactory
{
    
    public:
        MainMenu(RenderWindow *app);
        void HandleEvents(int x, int y, RenderWindow *app, Event e);
        void Display(RenderWindow *app);
    
        bool start;
        bool inSettings;
        bool inHighscore;
  
        sf::Text startText;
        sf::Text settingsText;
        sf::Text quitText;
        sf::Text scoreText;
        sf::RectangleShape startButton;
        sf::RectangleShape settingsButton;
        sf::RectangleShape quitButton;
        sf::RectangleShape scoreButton;
};