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

    int score() const;
    void score(const int& score);
    void incrementScore();

    std::string name() const;
    void saveScore();

  private:

    std::string _name;
    int _score{0};
};
#endif