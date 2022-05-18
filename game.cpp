#include "game.h"

Game::Game()
{
    startGame();
}

void Game::startGame()
{
    std::string s;
    count = 0;
    std::random_device rd;
    std::mt19937 gen(time(0));
    std::set<int>st;
    for(int i = 0; i < 4; i++){
        int x = gen() % 10;
        while(st.count(x)){
            x = gen() % 10;
        }
        st.insert(x);
        s += (x + '0');
    }
    have = s;
}

void Game::setGiven(std::string a)
{
    given = a;
    count++;
}

std::pair<int, int> Game::check()
{

    int bull = 0;
    int cow = 0;
    for(int i = 0; i < 4; i++){
        if(given[i] == have[i]){
            bull++;
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(given[i] == have[j] && i != j){
                cow++;
            }
        }
    }
    return std::make_pair(cow, bull);
}

bool Game::isFinished()
{
    return (have == given);
}

bool Game::goodString(std::string a)
{
    std::set < int > st;
    for(int i = 0; i < 4; i++){
        st.insert(a[i] - '0');
    }
    return (st.size() == 4);
}

void Game::saveRecord(std::string aName)
{
    int cnt = 0;
    for(auto to : rec){
        cnt++;
        if(cnt == 10){
            rec.erase(to);
        }
    }
    rec.insert({count, aName});
}
