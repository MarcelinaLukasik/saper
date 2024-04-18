#include <SFML/Graphics.hpp>

using namespace sf;

class Menu 
{
    
    public:
        Menu();
        void HandleEvents(int x, int y, RenderWindow *app, Event e);
        void Display(RenderWindow *app);
        int status;
};