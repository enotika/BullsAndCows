#ifndef GAME_H
#define GAME_H
#include <string>
#include <random>
#include <set>
#include <ctime>
class Game
{
private:
public:
    Game();
    std::string have;
    std::string given;
    int count = 0;
    std::set<std::pair<int, std::string>> rec;

    void startGame();
    void setGiven(std::string a);
    std::pair < int, int > check();
    bool isFinished();
    bool goodString(std::string a);
    void saveRecord(std::string aName);
};

#endif // GAME_H
