#include "highscore.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

Highscore::Highscore(RenderWindow *app)
{
    fileName = "highscores.txt";
    backButton = CreateButton(200, 60, 100, 60, app->getSize().x*0.35, 320, darkBlue);
    backText = CreateText("Back", 25, app->getSize().x*0.40, 325, sf::Color::White);
}

int Highscore::Save(std::string nick, std::string score)
{
    std::ofstream out(fileName, std::ios::app);
    std::string result = nick + " : " + score;
    out << result << "\n";
    out.close();
    return 0;
}

int Highscore::LoadScores()
{
    scores.clear();
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file";
        return -1;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string nick;
        int score;
        char colon;
        if (iss >> nick >> colon >> score)
        {
            scores.push_back(std::make_pair(nick, score));
        }
    }
    file.close();

    return 0;
}
bool CompareScores(const std::pair<std::string, int>& score1, const std::pair<std::string, int>& score2)
{
    return score1.second < score2.second; // Sort in ascending order
}

void Highscore::OrderScoresByScore()
{
    std::sort(scores.begin(), scores.end(), CompareScores);
}

void Highscore::ProcessScores(RenderWindow *app)
{   
    sf::Text header = CreateText("HIGHSCORES", 30, app->getSize().x*0.35, 20, sf::Color::Red);
    app->draw(header);
    
    LoadScores();
    OrderScoresByScore();
    int space = 20;
    int yPosition = 30;
    int count = 0;
    for (const auto& score : scores)
    {
        if (count >= 10) break; 
        yPosition = yPosition + space;
        sf::Text resultsText = CreateText(score.first + " : " + std::to_string(score.second), 20, app->getSize().x*0.40, yPosition, sf::Color::Black);
        app->draw(resultsText);
        count++;
    }
    app->draw(backButton);
    app->draw(backText);
}

void Highscore::HandleEvents(int x, int y, RenderWindow *app, Event e)
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
               
                if (x >= 4 && x <= 7 && y >= 10 && y <= 11)
                  {
                     if (e.key.code == Mouse::Left) 
                        open = false;                     
                  }
                        
                break;               
            }
            
        }
    app->clear(Color::White);
}