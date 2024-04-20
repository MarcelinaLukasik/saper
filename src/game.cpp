#include "game.h"

Game::Game()
{
    this->InitWindow();
    menu = new MainMenu();
    settings = new Settings();
}

void Game::InitWindow()
{
    this->videoMode.height = 400;
    this->videoMode.width = 400;
    this->app = new sf::RenderWindow(videoMode, "Minesweeper!", sf::Style::Close);   
}


bool Game::CheckIfOpen()
{
    return this->app->isOpen();
}

Vector2i Game::GetMousePosition()
{
    return Mouse::getPosition(*this->app);
}

void Game::HandleEvents(int **grid, int **sgrid, int x, int y)
{
     while (app->pollEvent(this->e))
        {
            switch(e.type)
            {
              case Event::Closed:
                  app->close();
                  break;

              case Event::KeyPressed:
                  if (e.key.code == Keyboard::Escape)
                    app->close();
                  break;

              case Event::MouseButtonPressed:
                  if (x >= 0 && x <= currentGridSize && y >= 0 && y <= currentGridSize)
                  {
                     if (e.key.code == Mouse::Left) 
                     {
                        if (grid[x][y] == 0) {                         
                                int n=1;
                                Game::DiscoverFields(x, y, n, grid, sgrid);  
                        }
                        sgrid[x][y]=grid[x][y];
                     }
                        
                     else if (e.key.code == Mouse::Right) sgrid[x][y]=11;
                  }
                 
                  break;  

                   case Event::Resized:
                    {
                        // update the view to the new size of the window
                        sf::FloatRect visibleArea(0, 0, e.size.width, e.size.height);
                        app->setView(sf::View(visibleArea));
                    }             
            }
            
        }
        app->clear(Color::White);
}

void Game::DiscoverFields(int x, int y, int n, int **grid, int **sgrid)
{

    if (x+n <currentGridSize && x+n >= 1 && grid[x+n][y]!=9 && sgrid[x+n][y] != grid[x+n][y]) 
    {
        sgrid[x+n][y] = grid[x+n][y];
        if (grid[x+n][y] == 0) Game::DiscoverFields(x+n, y, n, grid, sgrid);
    }

    if (y+n <currentGridSize && y+n >= 1 && grid[x][y+n]!=9 && sgrid[x][y+n] != grid[x][y+n]) 
    {
        sgrid[x][y+n] = grid[x][y+n];
        if (grid[x][y+n] == 0) Game::DiscoverFields(x, y+n, n, grid, sgrid);
    }

    if (x-n <currentGridSize && x-n >= 1 && grid[x-n][y]!=9 && sgrid[x-n][y] != grid[x-n][y]) 
    {
        sgrid[x-n][y] = grid[x-n][y];
        if (grid[x-n][y] == 0) Game::DiscoverFields(x-n, y, n, grid, sgrid);
    }

     if (y-n <currentGridSize && y-n >= 1 && grid[x][y-n]!=9 && sgrid[x][y-n] != grid[x][y-n]) 
    {
        sgrid[x][y-n] = grid[x][y-n];
        if (grid[x][y-n] == 0) Game::DiscoverFields(x, y-n, n, grid, sgrid);
    }

     if (x+n <currentGridSize && x+n >= 1 && y+n <currentGridSize && y+n >= 1  && grid[x+n][y+n]!=9 && sgrid[x+n][y+n] != grid[x+n][y+n]) 
    {
        sgrid[x+n][y+n] = grid[x+n][y+n];
        if (grid[x+n][y+n] == 0) Game::DiscoverFields(x+n, y+n, n, grid, sgrid);
    }

     if (x-n <currentGridSize && x-n >= 1 && y-n <currentGridSize && y-n >= 1 && grid[x-n][y-n]!=9 && sgrid[x-n][y-n] != grid[x-n][y-n]) 
    {
        sgrid[x-n][y-n] = grid[x-n][y-n];
        if (grid[x-n][y-n] == 0) Game::DiscoverFields(x-n, y-n, n, grid, sgrid);
    }

      if (x-n <currentGridSize && x-n >= 1 && y+n <currentGridSize && y+n >= 1 && grid[x-n][y+n]!=9 && sgrid[x-n][y+n] != grid[x-n][y+n]) 
    {
        sgrid[x-n][y+n] = grid[x-n][y+n];
        if (grid[x-n][y+n] == 0) Game::DiscoverFields(x-n, y+n, n, grid, sgrid);
    }

       if (x+n <currentGridSize && x+n >= 1 && y-n <currentGridSize && y-n >= 1 && grid[x+n][y-n]!=9 && sgrid[x+n][y-n] != grid[x+n][y-n]) 
    {
        sgrid[x+n][y-n] = grid[x+n][y-n];
        if (grid[x+n][y-n] == 0) Game::DiscoverFields(x+n, y-n, n, grid, sgrid);
    }


}

void Game::Display(int **grid, int **sgrid, Sprite s, int x, int y, int w, std::string timeAsText)
{
    //TODO move to separate method, remove magic numbers
    sf::Font font;
    font.loadFromFile("SunnySpellsBasic.ttf");
    sf::Text text(timeAsText, font, 30);
    text.setPosition(app->getSize().x*0.45, app->getSize().y - text.getGlobalBounds().height - text.getGlobalBounds().top - 15);
    text.setFillColor(sf::Color::White);

    sf::RectangleShape bottomBar(sf::Vector2f(200, 70));

    bottomBar.setSize(sf::Vector2f(app->getSize().x*0.80, 40));
    bottomBar.setPosition(app->getSize().x*0.08, app->getSize().y - bottomBar.getGlobalBounds().height - bottomBar.getGlobalBounds().top - 5);
    sf::Color darkBlue(0, 0, 128);
    bottomBar.setFillColor(darkBlue);

    for (int i=0;i<currentGridSize;i++)
         for (int j=0;j<currentGridSize;j++)
          {
              if (x >= 0 && x < currentGridSize && y >= 0 && y < currentGridSize)
           {
              if (sgrid[x][y]==9) sgrid[i][j]=grid[i][j];
           }
           s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
           s.setPosition((i+1)*w, (j+1)*w);
           app->draw(s);
           
          }
    app->draw(bottomBar);
    app->draw(text);
    app->display();
}

void Game::SetGridSize(int status)
{
        switch(status)
        {
            case 1:
                currentGridSize = smallGridSize;
                break;
            case 2:
                currentGridSize = mediumGridSize;
                break;
            case 3:
                currentGridSize = largeGridSize;
                break;
        }
}