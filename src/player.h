#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>

#define SCORES_FILENAME "scores.txt"

class Player {
  public:
    Player(std::string name);
    Player(std::string name, int score);

    int getScore() const;
    std::string getName() const;

    void setScore(const int& s);
    void saveScore();

  private:

    int findPlayerScore(std::string& name);
    bool _isNewPlayer;
    std::string _name;
    int _score;

};
#endif