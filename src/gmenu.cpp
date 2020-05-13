#include "gmenu.h"

void GMenu::displayPlayerNamePrompt() {

  std::string playerName;

  std::cout << "Please enter your name: ";
  std::cin >> playerName;

  if (std::cin.fail()) {
    playerName = "<UNKNOWN>";
    std::cerr << "Wrong Input" << std::endl;
  }

  _playerName = std::move(playerName);
};

std::string GMenu::getPlayerName() {
  return _playerName;
}