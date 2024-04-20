#include <SFML/Graphics.hpp>

using namespace sf;

class Settings 
{
    
    public:
        Settings();
        void HandleEvents(int x, int y, RenderWindow *app, Event e);
        void Display(RenderWindow *app);
        void InitButtons(RenderWindow *app);
        void SetCurrentMode(int modeNumber);
        int status;
        bool open;
        sf::RectangleShape easyButton;
        sf::RectangleShape mediumButton;
        sf::RectangleShape hardButton;
        sf::RectangleShape backButton;
        sf::Color darkBlue;
};