#include <SFML/Graphics.hpp>
#include "buttonFactory.h"

using namespace sf;

class Highscore : public ButtonFactory
{
    public:
    Highscore(RenderWindow *app);
    int Save(std::string nick, std::string score);
    int LoadScores();
    void ProcessScores(RenderWindow *app);
    void HandleEvents(int x, int y, RenderWindow *app, Event e);
    bool open;
    std::string results;
    std::string fileName;
    bool scoresProcessed = false;

    private:
    sf::RectangleShape backButton;
    sf::Text backText;
    std::vector<std::pair<std::string, int>> scores;
    //bool CompareScores(const std::pair<std::string, int>& score1, const std::pair<std::string, int>& score2);
    void OrderScoresByScore();

};
