#include "game.h"
#include <time.h>

int main()
{
    srand(time(0));
    Game game;

     while (game.CheckIfOpen())
     {
          Vector2i pos = game.GetMousePosition();
          int x = (pos.x/game.w);
          int y = (pos.y/game.w);
          game.menu->Display(game.app);
          game.menu->HandleEvents(x,y, game.app, game.e);
          if (game.menu->start) break;
          while (game.menu->inSettings && game.CheckIfOpen())
          {
            game.settings->open = true;
            Vector2i pos = game.GetMousePosition();
            int x = (pos.x/game.w);
            int y = (pos.y/game.w);

            game.app->clear(Color::White);
            game.settings->Display(game.app);
            game.settings->HandleEvents(x,y, game.app, game.e);
            if (!game.settings->open) 
            {             
              game.menu->inSettings = false;
              break;
            }
          }
     }
    game.app->setSize(sf::Vector2u (game.settings->currentGridSize*game.w,game.settings->currentGridSize*game.w + game.bottomBarHeight));
   
    //TODO move creating arrays to separate method in game class
    int** grid { new int*[game.settings->currentGridSize] }; // allocate an array of 12 int pointers — these are our rows
    for (int count { 0 }; count < game.settings->currentGridSize; ++count)
      grid[count] = new int[game.settings->currentGridSize]; // these are our columns

    int** sgrid { new int*[game.settings->currentGridSize] };
    for (int count { 0 }; count < game.settings->currentGridSize; ++count)
      sgrid[count] = new int[game.settings->currentGridSize];
    //////////////////////////////////

    //TODO move creating sprite to separate method in game class
    Texture t;
    t.loadFromFile("/Users/mac/Desktop/projekty_2024/saper_projekt/src/images/tiles.jpg");
    Sprite s(t);
    //////////////////////////////////

    // 9 is the index of bomb image
    if (game.settings->isCustom)
    {
      int minesCounter;
      while(minesCounter != game.settings->minesCount)
      {
        for (int i=0;i<game.settings->currentGridSize;i++)
        {
          for (int j=0;j<game.settings->currentGridSize;j++)
          {      
              sgrid[i][j]=game.startTile;
              if (minesCounter != game.settings->minesCount)
              {                 
                if (rand()%7==0)
                {
                  grid[i][j]=9;
                  minesCounter++;
                }                 
                else grid[i][j]=0;
              }
                
          }       
        }   
      } 
    }   
    else
    {
      for (int i=0;i<game.settings->currentGridSize;i++)
      for (int j=0;j<game.settings->currentGridSize;j++)
        {
          sgrid[i][j]=game.startTile;
          if (rand()%7==0)  grid[i][j]=9;
          else grid[i][j]=0;
        }
    }
 
    

    for (int i=0;i<game.settings->currentGridSize;i++)
     for (int j=0;j<game.settings->currentGridSize;j++)
      {
        int n=0;
        if (grid[i][j]==9) continue;
        if (i+1 < game.settings->currentGridSize)
            if (grid[i+1][j]==9) n++;
        if (j+1 < game.settings->currentGridSize)
            if (grid[i][j+1]==9) n++;
        if (i-1 >= 0)
            if (grid[i-1][j]==9) n++;
        if (j-1 >= 0)  
            if (grid[i][j-1]==9) n++;
        if (i+1 < game.settings->currentGridSize && j+1 < game.settings->currentGridSize)
            if (grid[i+1][j+1]==9) n++;
        if (i-1 >= 0 && j-1 >= 0)
            if (grid[i-1][j-1]==9) n++;
        if (i-1 >= 0 && j+1 < game.settings->currentGridSize)
            if (grid[i-1][j+1]==9) n++;
        if (i+1 < game.settings->currentGridSize && j-1 >= 0)   
            if (grid[i+1][j-1]==9) n++;
        grid[i][j]=n;
      }
   

    sf::Clock clock;

    while (game.CheckIfOpen())
    {
        if(!game.end)
        {
          game.elapsedTime = clock.getElapsedTime();
        }
        
        float timeInSeconds =  game.elapsedTime.asSeconds();
        std::string timeAsText = std::to_string(timeInSeconds);
        std::string formatedTime = timeAsText.substr(0, timeAsText.length() - 5);
        Vector2i pos = game.GetMousePosition();
        int x = (pos.x/game.w);
        int y = (pos.y/game.w);

        game.HandleEvents(grid, sgrid, x, y);        
        game.Display(grid, sgrid, s, x, y, game.w, formatedTime);
    }
    
    // Deallocate memory
    //TODO move to game class method
    for (int i = 0; i < game.settings->currentGridSize; ++i) {
        delete[] grid[i];
        delete[] sgrid[i];
    }
    delete[] grid;
    delete[] sgrid;

    return 0;
}
