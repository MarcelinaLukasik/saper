#include <SFML/Graphics.hpp>
using namespace sf;

class Game 
{
    private:

    
    VideoMode videoMode;
    Event e;
    void InitWindow();
    

    public:
        Game();
        bool CheckIfOpen();
        Vector2i GetMousePosition();
        void HandleEvents(int **grid, int **sgrid, int x, int y);
        void Display(int **grid, int **sgrid, Sprite s, int x, int y, int w);
        RenderWindow* app;
        const int gridSize = 10;
        const int w=32;
};