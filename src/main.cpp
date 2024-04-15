
#include "game.h"
#include <time.h>

int main()
{
    srand(time(0));
    Game game;


   
    //TODO move creating arrays to separate method in game class
    int** grid { new int*[12] }; // allocate an array of 12 int pointers — these are our rows
    for (int count { 0 }; count < 12; ++count)
      grid[count] = new int[12]; // these are our columns

    int** sgrid { new int*[12] };
    for (int count { 0 }; count < 12; ++count)
      sgrid[count] = new int[12];
    //////////////////////////////////

    //TODO move creating sprite to separate method in game class
    Texture t;
    t.loadFromFile("/Users/mac/Desktop/projekty_2024/saper_projekt/src/images/tiles.jpg");
    Sprite s(t);
    //////////////////////////////////

    // 9 is the index of bomb image
    for (int i=1;i<=game.gridSize;i++)
     for (int j=1;j<=game.gridSize;j++)
      {
        sgrid[i][j]=game.startTile;
        if (rand()%5==0)  grid[i][j]=9;
        else grid[i][j]=0;
      }

    for (int i=1;i<=game.gridSize;i++)
     for (int j=1;j<=game.gridSize;j++)
      {
        int n=0;
        if (grid[i][j]==9) continue;
        if (grid[i+1][j]==9) n++;
        if (grid[i][j+1]==9) n++;
        if (grid[i-1][j]==9) n++;
        if (grid[i][j-1]==9) n++;
        if (grid[i+1][j+1]==9) n++;
        if (grid[i-1][j-1]==9) n++;
        if (grid[i-1][j+1]==9) n++;
        if (grid[i+1][j-1]==9) n++;
        grid[i][j]=n;
      }
   

    sf::Clock clock;
        

    while (game.CheckIfOpen())
    {
        
        sf::Time elapsed = clock.getElapsedTime();
        float timeElapsed =  elapsed.asSeconds();
        std::string timeAsText = std::to_string(timeElapsed);
        std::string formatedTime = timeAsText.substr(0, timeAsText.length() - 5);
        Vector2i pos = game.GetMousePosition();
        int x = pos.x/game.w;
        int y = pos.y/game.w;

        game.HandleEvents(grid, sgrid, x, y);        
        game.Display(grid, sgrid, s, x, y, game.w, formatedTime);
    }

    // Deallocate memory
    //TODO move to game class method
    for (int i = 0; i < 12; ++i) {
        delete[] grid[i];
        delete[] sgrid[i];
    }
    delete[] grid;
    delete[] sgrid;

    return 0;
}
