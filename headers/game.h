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
        void SetGridSize(int status);
        RenderWindow* app;
        Event e;
        const int smallGridSize = 5;
        const int mediumGridSize = 10;
        const int largeGridSize = 15;
        const int startTile = 10;
        int currentGridSize = 10;
        const int w=32;
        MainMenu *menu;
        Settings *settings;
         VideoMode videoMode; 
};