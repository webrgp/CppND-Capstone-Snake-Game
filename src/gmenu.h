#ifndef GMENU_H
#define GMENU_H

#include <iomanip>
#include <iostream>
#include <string>

class GMenu {
  public:
    GMenu(){};
    ~GMenu(){};
    void displayPlayerNamePrompt();
    void displayPlayerScore(std::string name, int score, int size);
    std::string getPlayerName();
  private:
    std::string _playerName;
};

#endif