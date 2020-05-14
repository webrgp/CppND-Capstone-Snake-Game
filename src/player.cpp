#include "player.h"

Player::Player(std::string name): _name(name) {
  _score = 0;
}

Player::Player(std::string name, int score): _name(name), _score(score) {}

int Player::score() const { return _score; }
void Player::score(const int &score) {
  _score = score;
}

void Player::incrementScore() {
  _score++;
}

std::string Player::name() const { return _name;}

void Player::saveScore() {

  std::vector<Player> players;

  bool isNewPlayer{true};
  int score;
  std::string line;
  std::string name;

  std::ifstream f;
  f.open(SCORES_FILENAME);

  if(f) {
    while(getline(f, line)){
      std::istringstream lineStream(line);
      lineStream >> name;
      if(name == this->_name) {
        score = this->_score;
        isNewPlayer = false;
      } else {
        lineStream >> score;
      }
      players.push_back(Player(name, score));
    }

    f.close();
  }

  if(isNewPlayer) {
    players.push_back(Player(this->_name, this->_score));
  }

  //sort top score
  std::sort(players.begin(), players.end(), [](const Player a, const Player &b) -> bool{
    return a._score > b._score;
  });

  // Update scores
  std::ofstream fout;
  fout.open(SCORES_FILENAME, std::ofstream::trunc);
  for(auto &player: players)
  {
    fout << player._name << " " << std::to_string(player._score) << std::endl;
  }
	fout.close();
}