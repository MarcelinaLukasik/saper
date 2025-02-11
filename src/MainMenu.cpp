#include "MainMenu.h"

MainMenu::MainMenu(RenderWindow *app)
{
   startText = CreateText("START", 30, app->getSize().x*0.43, 75, sf::Color::White);
   settingsText = CreateText("SETTINGS", 30, app->getSize().x*0.43, 175, sf::Color::White);
   quitText = CreateText("QUIT", 30, app->getSize().x*0.43, 275, sf::Color::White);

   startButton = CreateButton(200, 60, app->getSize().x*0.80, 70, app->getSize().x*0.08, 60, darkBlue);
   settingsButton = CreateButton(200, 60, app->getSize().x*0.80, 70, app->getSize().x*0.08, 160, darkBlue);
   quitButton = CreateButton(200, 60, app->getSize().x*0.80, 70, app->getSize().x*0.08, 260, darkBlue);
}

void MainMenu::Display(RenderWindow *app)
{   
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
            
               if (x >= 1 && x <= 10 && y >= 2 && y <= 4)
               {
                  if (e.key.code == Mouse::Left) 
                     start = true;                       
               }
               if (x >= 1 && x <= 10 && y >= 5 && y <= 7)
               {
                  if (e.key.code == Mouse::Left) 
                     inSettings = true;                      
               }

                  if (x >= 1 && x <= 10 && y >= 8 && y <= 10)
               {
                  if (e.key.code == Mouse::Left) 
                     app->close();           
               }                
               break;               
         }           
      }
      app->clear(Color::White);
}

