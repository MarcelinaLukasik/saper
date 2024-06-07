#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MainMenu.h"
#include "settings.h"
#include "highscore.h"

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
        bool over;
        bool win;
        bool inMenu;
        int discoveredFields =0;
        int fieldsToDiscover;
        std::string formatedTime;
        sf::Time elapsedTime;
        MainMenu *menu;
        Settings *settings;
        Highscore *highscore;
        VideoMode videoMode; 
        float scale = 1.0f;
        float scaleFactor = 0.0005f;
        sf::SoundBuffer buffer;
        sf::Sound sound;
        std::string playerInput;
        sf::RectangleShape bottomBar;
        
};