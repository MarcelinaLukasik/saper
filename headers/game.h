#include <SFML/Graphics.hpp>
#include "menu.h"

using namespace sf;

class Game 
{
    private:
    
    VideoMode videoMode;
    
    void InitWindow();
    void InitMenu();
    

    public:
        Game();
        bool CheckIfOpen();
        Vector2i GetMousePosition();
        void HandleEvents(int **grid, int **sgrid, int x, int y);
        void Display(int **grid, int **sgrid, Sprite s, int x, int y, int w, std::string timeAsText);
        void DiscoverFields(int x, int y, int n, int **grid, int **sgrid, int i);
        RenderWindow* app;
        Event e;
        const int gridSize = 10;
        const int startTile = 10;
        const int w=32;
        Menu menu;
};