#include "MainMenu.h"

MainMenu::MainMenu()
{
    status = 0;
}

void MainMenu::Display(RenderWindow *app)
{
    //TODO move to separate method, remove magic numbers
     sf::Color darkBlue(0, 0, 128);

    sf::Font font;
    font.loadFromFile("SunnySpellsBasic.ttf");
    sf::Text startText("START", font, 30);
    startText.setPosition(app->getSize().x*0.43, 75);
    startText.setFillColor(sf::Color::White);

    sf::Text settingsText("SETTINGS", font, 30);
    settingsText.setPosition(app->getSize().x*0.43, 175);
    settingsText.setFillColor(sf::Color::White);


    sf::Text quitText("QUIT", font, 30);
    quitText.setPosition(app->getSize().x*0.43, 275);
    quitText.setFillColor(sf::Color::White);

    sf::RectangleShape startButton(sf::Vector2f(200, 60));
    startButton.setSize(sf::Vector2f(app->getSize().x*0.80, 70));
    startButton.setPosition(app->getSize().x*0.08, 60 ); 
    startButton.setFillColor(darkBlue);

    sf::RectangleShape settingsButton(sf::Vector2f(200, 60));
    settingsButton.setSize(sf::Vector2f(app->getSize().x*0.80, 70));
    settingsButton.setPosition(app->getSize().x*0.08, 160 );
    settingsButton.setFillColor(darkBlue);

    sf::RectangleShape quitButton(sf::Vector2f(200, 60));
    quitButton.setSize(sf::Vector2f(app->getSize().x*0.80, 70));
    quitButton.setPosition(app->getSize().x*0.08, 260 );
    quitButton.setFillColor(darkBlue);

    
    app->draw(startButton);
    app->draw(settingsButton);
    app->draw(quitButton);
    app->draw(startText);
    app->draw(settingsText);
    app->draw(quitText);
    app->display();
}

void MainMenu::HandleEvents(int x, int y, RenderWindow *app, Event e)
{
     while (app->pollEvent(e))
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
               
                  if (x >= 1 && x <= 10 && y >= 1 && y <= 2)
                  {
                     if (e.key.code == Mouse::Left) 
                     {
                        status = 1;
                     }
                        
                  }
                  if (x >= 1 && x <= 10 && y >= 5 && y <= 6)
                  {
                     if (e.key.code == Mouse::Left) 
                     {
                        status = 2;
                     }
                        
                  }

                   if (x >= 1 && x <= 10 && y >= 8 && y <= 9)
                  {
                     if (e.key.code == Mouse::Left) 
                     {
                        status = 3;
                     }
                        
                  }
                
                 
                  break;               
            }
            
        }
        app->clear(Color::White);
}