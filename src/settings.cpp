#include "settings.h"
#include <SFML/Graphics.hpp>


Settings::Settings()
{
    status = 0;
    darkBlue = sf::Color (0, 0, 128);
}

void Settings::InitButtons(RenderWindow *app)
{
    
    easyButton = sf::RectangleShape (sf::Vector2f(200, 60));
    easyButton.setSize(sf::Vector2f(100, 70));
    easyButton.setPosition(app->getSize().x*0.05, 160 ); 
    easyButton.setFillColor(darkBlue);

    mediumButton = sf::RectangleShape (sf::Vector2f(200, 60));
    mediumButton.setSize(sf::Vector2f(100, 70));
    mediumButton.setPosition(app->getSize().x*0.35, 160 ); 
    mediumButton.setFillColor(darkBlue);

    hardButton = sf::RectangleShape (sf::Vector2f(200, 60));
    hardButton.setSize(sf::Vector2f(100, 70));
    hardButton.setPosition(app->getSize().x*0.65, 160 ); 
    hardButton.setFillColor(darkBlue);

    backButton = sf::RectangleShape (sf::Vector2f(200, 60));
    backButton.setSize(sf::Vector2f(100, 60));
    backButton.setPosition(app->getSize().x*0.35, 320 ); 
    backButton.setFillColor(darkBlue);
}

void Settings::Display(RenderWindow *app)
{
    //TODO move to separate method, remove magic numbers
     

    sf::Font font;
    font.loadFromFile("SunnySpellsBasic.ttf");

    sf::Text settingsText("SETTINGS", font, 30);
    settingsText.setPosition(app->getSize().x*0.40, 75);
    settingsText.setFillColor(sf::Color::Black);

    sf::Text difficultyText("Difficulty", font, 20);
    difficultyText.setPosition(app->getSize().x*0.43, 120);
    difficultyText.setFillColor(sf::Color::Black);

    sf::Text easyText("Easy", font, 30);
    easyText.setPosition(app->getSize().x*0.10, 175);
    easyText.setFillColor(sf::Color::White);

    sf::Text mediumText("Medium", font, 30);
    mediumText.setPosition(app->getSize().x*0.40, 175);
    mediumText.setFillColor(sf::Color::White);

    sf::Text hardText("Hard", font, 30);
    hardText.setPosition(app->getSize().x*0.70, 175);
    hardText.setFillColor(sf::Color::White);


    sf::Text backText("Back", font, 30);
    backText.setPosition(app->getSize().x*0.40, 325);
    backText.setFillColor(sf::Color::White);
  
    app->draw(easyButton);
    app->draw(mediumButton);
    app->draw(hardButton);
    app->draw(backButton);

    app->draw(settingsText);
    app->draw(difficultyText);
    app->draw(easyText);
    app->draw(mediumText);
    app->draw(hardText);
    app->draw(backText);
    app->display();
}

void Settings::HandleEvents(int x, int y, RenderWindow *app, Event e)
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
               
                  if (x >= 0 && x <= 2 && y >= 4 && y <= 5)
                  {
                     if (e.key.code == Mouse::Left) 
                     {
                        SetCurrentMode(1);
                     }
                        
                  }
                  if (x >= 3 && x <= 6 && y >= 4 && y <= 5)
                  {
                     if (e.key.code == Mouse::Left) 
                     {
                        SetCurrentMode(2);
                     }
                        
                  }

                   if (x >= 7 && x <= 10 && y >= 4 && y <= 5)
                  {
                     if (e.key.code == Mouse::Left) 
                     {
                        SetCurrentMode(3);
                     }
                        
                  }

                    if (x >= 3 && x <= 6 && y >= 9 && y <= 10)
                  {
                     if (e.key.code == Mouse::Left) 
                     {
                        open = false;
                     }
                        
                  }
                
                 
                  break;               
            }
            
        }
        app->clear(Color::White);
}

void Settings::SetCurrentMode(int modeNumber)
{
    switch(modeNumber)
            {
              case 1:
                  status = 1;
                  easyButton.setFillColor(sf::Color::Blue);
                  mediumButton.setFillColor(darkBlue);
                  hardButton.setFillColor(darkBlue);
                  break;

              case 2:
                  status = 2;
                  easyButton.setFillColor(darkBlue);
                  mediumButton.setFillColor(sf::Color::Blue);
                  hardButton.setFillColor(darkBlue);
                  break;

              case 3:
                  status = 3;
                  easyButton.setFillColor(darkBlue);
                  mediumButton.setFillColor(darkBlue);
                  hardButton.setFillColor(sf::Color::Blue);                
                  break;               
            }
}