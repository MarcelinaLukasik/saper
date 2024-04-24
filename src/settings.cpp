#include "settings.h"
#include <SFML/Graphics.hpp>


Settings::Settings(RenderWindow *app)
{
    status = 0;

    settingsText = CreateText("SETTINGS", 25, app->getSize().x*0.40, 75, sf::Color::Black);
    difficultyText = CreateText("DIfficulty", 20, app->getSize().x*0.43, 120, sf::Color::Black);
    easyText = CreateText("Easy", 25, app->getSize().x*0.10, 175, sf::Color::White);
    mediumText = CreateText("Medium", 25, app->getSize().x*0.40, 175, sf::Color::White);
    hardText = CreateText("Hard", 25, app->getSize().x*0.70, 175, sf::Color::White);
    customText = CreateText("Custom", 25, app->getSize().x*0.43, 230, sf::Color::White);
    sizeText = CreateText("Size", 20, app->getSize().x*0.15, 240, sf::Color::Black);
    minusText = CreateText("-", 30, app->getSize().x*0.08, 265, sf::Color::White);
    plusText = CreateText("+", 30, app->getSize().x*0.28, 265, sf::Color::White);   
    backText = CreateText("Back", 25, app->getSize().x*0.40, 325, sf::Color::White);

    easyButton = CreateButton(200, 60, 100, 50, app->getSize().x*0.05, 160, darkBlue);
    mediumButton = CreateButton(200, 60, 100, 50, app->getSize().x*0.35, 160, darkBlue);
    hardButton = CreateButton(200, 60, 100, 50, app->getSize().x*0.65, 160, darkBlue);
    customButton = CreateButton(200, 60, 100, 50, app->getSize().x*0.35, 220, darkBlue);
    minusButton = CreateButton(200, 60, 30, 30, app->getSize().x*0.05, 270, darkBlue);
    plusButton = CreateButton(200, 60, 30, 30, app->getSize().x*0.25, 270, darkBlue);
    backButton = CreateButton(200, 60, 100, 60, app->getSize().x*0.35, 320, darkBlue);

}

void Settings::Display(RenderWindow *app)
{
    chosenSizeText = CreateText(std::to_string(currentGridSize), 20, app->getSize().x*0.17, 270, sf::Color::Black);

    app->draw(easyButton);
    app->draw(mediumButton);
    app->draw(hardButton);
    app->draw(customButton);
    app->draw(minusButton);
    app->draw(plusButton);
    app->draw(backButton);

    app->draw(settingsText);
    app->draw(difficultyText);
    app->draw(easyText);
    app->draw(mediumText);
    app->draw(hardText);
    app->draw(backText);
    app->draw(customText);
    app->draw(sizeText);
    app->draw(minusText);
    app->draw(chosenSizeText);
    app->draw(plusText);
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
                        SetCurrentMode(1);                     
                  }
                if (x >= 3 && x <= 6 && y >= 4 && y <= 5)
                  {
                     if (e.key.code == Mouse::Left) 
                        SetCurrentMode(2);                      
                  }

                if (x >= 7 && x <= 10 && y >= 4 && y <= 5)
                  {
                     if (e.key.code == Mouse::Left)
                        SetCurrentMode(3);                        
                  }

                if (x >= 4 && x <= 7 && y >= 7 && y <= 8)
                  {
                     if (e.key.code == Mouse::Left) 
                        SetCurrentMode(4);                    
                  }

                if (x >= 0 && x <= 1 && y >= 8 && y <=9)
                  {
                    if (currentGridSize > 5)
                        currentGridSize -= 1;
                  }
                   if (x >= 3 && x <= 4 && y >= 8 && y <=9)
                  {
                    if (currentGridSize < 25)
                        currentGridSize += 1;
                  }

                    if (x >= 3 && x <= 6 && y >= 9 && y <= 10)
                  {
                     if (e.key.code == Mouse::Left)
                        open = false;                       
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
              currentGridSize = smallGridSize;
              easyButton.setFillColor(sf::Color::Blue);
              mediumButton.setFillColor(darkBlue);
              hardButton.setFillColor(darkBlue);
              customButton.setFillColor(darkBlue);
              break;

          case 2:
              currentGridSize = mediumGridSize;
              easyButton.setFillColor(darkBlue);
              mediumButton.setFillColor(sf::Color::Blue);
              hardButton.setFillColor(darkBlue);
              customButton.setFillColor(darkBlue);
              break;

          case 3:
              currentGridSize = largeGridSize;
              easyButton.setFillColor(darkBlue);
              mediumButton.setFillColor(darkBlue);
              hardButton.setFillColor(sf::Color::Blue);  
              customButton.setFillColor(darkBlue);              
              break; 
                
          case 4:
              currentGridSize = mediumGridSize;
              easyButton.setFillColor(darkBlue);
              mediumButton.setFillColor(darkBlue);
              hardButton.setFillColor(darkBlue); 
              customButton.setFillColor(sf::Color::Blue);               
              break;              
        }
}