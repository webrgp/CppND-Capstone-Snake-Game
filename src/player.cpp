#include "player.h"

Player::Player(std::string name): _name(name) {
  _score = findPlayerScore(name);
  _isNewPlayer = (_score == 0) ? true : false;
}

Player::Player(std::string name, int score): _name(name), _score(score), _isNewPlayer(false){}

int Player::getScore() const { return _score; }
std::string Player::getName() const { return _name;}

int Player::findPlayerScore(std::string& playerName)
{
  std::ifstream f;
  f.open(SCORES_FILENAME);

  int score;
  std::string line;
  std::string name;

  if(f) {
    while(std::getline(f, line)) {
      std::istringstream lineStream(line);
      lineStream >> name >> score;
      if(name == playerName)
      {
        return score;
      }
    }

    f.close();
  }

  return 0;
}

void Player::setScore(const int &score) {
  _score = score;
}

void Player::saveScore() {

  std::vector<Player> players;

  int score;
  std::string line;
  std::string name;

  std::ifstream f;
  f.open(SCORES_FILENAME);

  if(f) {
    while(getline(f, line)){
      std::istringstream lineStream(line);
      lineStream >> name;
      if(name == _name)
        score = _score;
      else
        lineStream >> score;
      players.push_back(Player(name, score));
    }

    f.close();
  }

  if(_isNewPlayer) {
    players.push_back(Player(_name, _score));
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