#include <SFML/Graphics.hpp>

using namespace sf;

class MainMenu 
{
    
    public:
        MainMenu();
        void HandleEvents(int x, int y, RenderWindow *app, Event e);
        void Display(RenderWindow *app);
        int status;
};