#include "game.h"
#include <string>
#include<iostream>

Game::Game()
{
    this->InitWindow();
    menu = new MainMenu(this->app);
    settings = new Settings(this->app);
    highscore = new Highscore(this->app);
    buffer.loadFromFile("explosionSound.wav");
    sound = sf::Sound(buffer);
    playerInput.clear();
    
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
                    if (e.key.code == Keyboard::Enter && win)
                    {
                        highscore->Save(playerInput, formatedTime);
                        inMenu = true;
                        sf::FloatRect visibleArea(0, 0, 400, 400);
                        app->setView(sf::View(visibleArea));
                        app->setSize(sf::Vector2u(400,400)); 
                    }
                    if (e.key.code == Keyboard::Left)
                    {
                        inMenu = true;
                        sf::FloatRect visibleArea(0, 0, 400, 400);
                        app->setView(sf::View(visibleArea));
                        app->setSize(sf::Vector2u(400,400)); 
                    }

                    break;

                case Event::MouseButtonPressed:
                    if (x >= 0 && x <= settings->currentGridSize && y >= 0 && y <= settings->currentGridSize)
                    {
                        if (e.key.code == Mouse::Left) 
                        {
                            if (grid[x][y] == 0) 
                            {                         
                                int n=1;
                                Game::DiscoverFields(x, y, n, grid, sgrid);  
                            }
                            else if (grid[x][y] == 9)
                            {
                                sgrid[x][y]=grid[x][y];
                                sound.play();
                            }
                            else
                            {
                                sgrid[x][y]=grid[x][y];
                                discoveredFields++;
                            }                                               
                        }
                      
                        else if (e.key.code == Mouse::Right) sgrid[x][y]=11;
                    }                 
                    break;  

                case Event::Resized:
                {
                    // update the view to the new size of the window
                    sf::FloatRect visibleArea(0, 0, e.size.width, e.size.height);
                    app->setView(sf::View(visibleArea)); 
                    break;
                }   
                case Event::TextEntered:
                {   
                    if(win)
                    {
                        
                        if(!playerInput.empty() && e.text.unicode == '\b')
                        {
                            playerInput.pop_back();
                        }    
                        else 
                            playerInput += e.text.unicode;
                    }
                    break;                 
                }  
                
                           
            }           
        }
        app->clear(Color::White);
}

void Game::DiscoverFields(int x, int y, int n, int **grid, int **sgrid)
{
    if (x+n <settings->currentGridSize && x+n >= 0 && grid[x+n][y]!=9 && sgrid[x+n][y] != grid[x+n][y]) 
    {
        sgrid[x+n][y] = grid[x+n][y];
        discoveredFields++;
        if (grid[x+n][y] == 0) Game::DiscoverFields(x+n, y, n, grid, sgrid);
    }

    if (y+n <settings->currentGridSize && y+n >= 1 && grid[x][y+n]!=9 && sgrid[x][y+n] != grid[x][y+n]) 
    {
        sgrid[x][y+n] = grid[x][y+n];
        discoveredFields++;
        if (grid[x][y+n] == 0) Game::DiscoverFields(x, y+n, n, grid, sgrid);
    }

    if (x-n <settings->currentGridSize && x-n >= 0 && grid[x-n][y]!=9 && sgrid[x-n][y] != grid[x-n][y]) 
    {
        sgrid[x-n][y] = grid[x-n][y];
        discoveredFields++;
        if (grid[x-n][y] == 0) Game::DiscoverFields(x-n, y, n, grid, sgrid);
    }

     if (y-n <settings->currentGridSize && y-n >= 0 && grid[x][y-n]!=9 && sgrid[x][y-n] != grid[x][y-n]) 
    {
        sgrid[x][y-n] = grid[x][y-n];
        discoveredFields++;
        if (grid[x][y-n] == 0) Game::DiscoverFields(x, y-n, n, grid, sgrid);
    }

     if (x+n <settings->currentGridSize && x+n >= 0 && y+n <settings->currentGridSize && y+n >= 0  && grid[x+n][y+n]!=9 && sgrid[x+n][y+n] != grid[x+n][y+n]) 
    {
        sgrid[x+n][y+n] = grid[x+n][y+n];
        discoveredFields++;
        if (grid[x+n][y+n] == 0) Game::DiscoverFields(x+n, y+n, n, grid, sgrid);
    }

     if (x-n <settings->currentGridSize && x-n >= 0 && y-n <settings->currentGridSize && y-n >= 0 && grid[x-n][y-n]!=9 && sgrid[x-n][y-n] != grid[x-n][y-n]) 
    {
        sgrid[x-n][y-n] = grid[x-n][y-n];
        discoveredFields++;
        if (grid[x-n][y-n] == 0) Game::DiscoverFields(x-n, y-n, n, grid, sgrid);
    }

      if (x-n <settings->currentGridSize && x-n >= 0 && y+n <settings->currentGridSize && y+n >= 0 && grid[x-n][y+n]!=9 && sgrid[x-n][y+n] != grid[x-n][y+n]) 
    {
        sgrid[x-n][y+n] = grid[x-n][y+n];
        discoveredFields++;
        if (grid[x-n][y+n] == 0) Game::DiscoverFields(x-n, y+n, n, grid, sgrid);
    }

       if (x+n <settings->currentGridSize && x+n >= 0 && y-n <settings->currentGridSize && y-n >= 0 && grid[x+n][y-n]!=9 && sgrid[x+n][y-n] != grid[x+n][y-n]) 
    {
        sgrid[x+n][y-n] = grid[x+n][y-n];
        discoveredFields++;
        if (grid[x+n][y-n] == 0) Game::DiscoverFields(x+n, y-n, n, grid, sgrid);
    }
}

void Game::Display(int **grid, int **sgrid, Sprite s, int x, int y, int w, std::string timeAsText)
{
    sf::Font font;
    font.loadFromFile("SunnySpellsBasic.ttf"); 
    sf::Text text(timeAsText, font, 30);
    text.setPosition(app->getSize().x*0.45, app->getSize().y - text.getGlobalBounds().height - text.getGlobalBounds().top - 15);
    text.setFillColor(sf::Color::White);
      
    sf::RectangleShape bottomBar(sf::Vector2f(200, 70));
    int bottomBarWidth = w*settings->currentGridSize;
    bottomBar.setSize(sf::Vector2f(bottomBarWidth, bottomBarHeight));
    bottomBar.setPosition(app->getSize().x/2.f -bottomBarWidth/2, app->getSize().y - bottomBar.getGlobalBounds().height - bottomBar.getGlobalBounds().top - 5);
    sf::Color darkBlue(0, 0, 128);
    bottomBar.setFillColor(darkBlue);

    sf::Text playerText(playerInput, font, 30);
    playerText.setPosition(app->getSize().x*0.45, app->getSize().y - playerText.getGlobalBounds().height - playerText.getGlobalBounds().top - 50);
    playerText.setFillColor(sf::Color::Black);

    sf::RectangleShape scoreField(sf::Vector2f(200, 70));
    int scoreFieldWidth = w*settings->currentGridSize;
    scoreField.setSize(sf::Vector2f(scoreFieldWidth, 70));
    scoreField.setPosition(app->getSize().x/2.f -scoreFieldWidth/2, app->getSize().y - scoreField.getGlobalBounds().height - scoreField.getGlobalBounds().top - 40);
    scoreField.setFillColor(sf::Color::White);
   

    for (int i=0;i<settings->currentGridSize;i++)
         for (int j=0;j<settings->currentGridSize;j++)
          {
            if (x >= 0 && x < settings->currentGridSize && y >= 0 && y < settings->currentGridSize)
            {
                if (sgrid[x][y]==9) 
                    sgrid[i][j]=grid[i][j];
            }
           s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
           s.setPosition((i)*w, (j)*w);
           app->draw(s);          
          }

    if (x >= 0 && x < settings->currentGridSize && y >= 0 && y < settings->currentGridSize)
        if (sgrid[x][y]==9 && !win)
            over = true;                   
    if (over == true)
    {
        sf::Text gameEndText("GAME OVER", font, 50);
        gameEndText.setPosition(app->getSize().x/2 -50, app->getSize().y/2 - 100);
        gameEndText.setFillColor(sf::Color::Red);
        gameEndText.setOutlineColor(sf::Color::White);
        gameEndText.setOutlineThickness(5);
        gameEndText.setRotation(40);
        if (scale < 1.5)
            scale += scaleFactor;
        gameEndText.setScale(scale, scale);
        app->draw(gameEndText);
    }
    if (fieldsToDiscover == discoveredFields)
    {
        win = true;
        sf::Text scoreHeaderText("Your name:", font, 25);
        scoreHeaderText.setPosition(app->getSize().x*0.35, app->getSize().y - scoreHeaderText.getGlobalBounds().height - scoreHeaderText.getGlobalBounds().top - 80);
        scoreHeaderText.setFillColor(sf::Color::Black);
        sf::Text gameEndText("YOU WIN", font, 50);
        gameEndText.setPosition(app->getSize().x/2 -50, app->getSize().y/2 - 100);
        gameEndText.setFillColor(sf::Color::Green);
        gameEndText.setOutlineColor(sf::Color::White);
        gameEndText.setOutlineThickness(5);
        gameEndText.setRotation(40);
        
        if (scale < 1.5)
            scale += scaleFactor;
        gameEndText.setScale(scale, scale);
        app->draw(gameEndText);      
        app->draw(scoreField);
        app->draw(scoreHeaderText);
        app->draw(playerText);
    }
    app->draw(bottomBar);
   
    app->draw(text);
    app->display();
}


