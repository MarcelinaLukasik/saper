#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "settings.h"

using namespace sf;

class Game 
{
    private:
    void InitWindow();
    void InitMenu();
    

    public:
        Game();
        bool CheckIfOpen();
        Vector2i GetMousePosition();
        void HandleEvents(int **grid, int **sgrid, int x, int y);
        void Display(int **grid, int **sgrid, Sprite s, int x, int y, int w, std::string timeAsText);
        void DiscoverFields(int x, int y, int n, int **grid, int **sgrid);
        RenderWindow* app;
        Event e;
        const int startTile = 10;    
        int bottomBarHeight = 40;
        const int w=32;
        bool end;
        std::string totalTime;
        sf::Time elapsedTime;
        MainMenu *menu;
        Settings *settings;
        VideoMode videoMode; 
};