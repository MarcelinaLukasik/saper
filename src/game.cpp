#include "game.h"

Game::Game()
{
    this->InitWindow();
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
                  if (x >= 0 && x <= gridSize && y >= 0 && y <= gridSize){
                     if (e.key.code == Mouse::Left) sgrid[x][y]=grid[x][y];
                     else if (e.key.code == Mouse::Right) sgrid[x][y]=11;
                  }
                 
                  break;               
            }
            
        }
        app->clear(Color::White);
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

    for (int i=1;i<=10;i++)
         for (int j=1;j<=10;j++)
          {
              if (x >= 0 && x <= gridSize && y >= 0 && y <= gridSize)
           {
              if (sgrid[x][y]==9) sgrid[i][j]=grid[i][j];
           }
           s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
           s.setPosition(i*w, j*w);
           app->draw(s);
           
          }
    app->draw(bottomBar);
    app->draw(text);
    app->display();
}