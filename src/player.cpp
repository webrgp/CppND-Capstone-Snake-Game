#include "player.h"

Player::Player(std::string name): name(name) {
  score = findPlayerScore(name);
  isNewPlayer = (score == 0) ? true : false;
}

Player::Player(std::string name, int score): name(name), score(score), isNewPlayer(false){}

int Player::getScore() const { return score; }
std::string Player::getName() const { return name;}

int Player::findPlayerScore(std::string& name)
{
  std::ifstream f;
  f.open(SCORES_FILENAME);

  int pscore;
  std::string line;
  std::string pname;

  if(f) {
    while(std::getline(f, line)) {
      std::istringstream lineStream(line);
      lineStream >> pname >> pscore;
      if(pname == name)
      {
        return pscore;
      }
    }

    f.close();
  }

  return 0;
}

void Player::setScore(const int &s) {
  score = s;
}

void Player::saveScore() {

  std::vector<Player> players;

  int pscore;
  std::string line;
  std::string pname;

  std::ifstream f;
  f.open(SCORES_FILENAME);

  if(f) {
    while(getline(f, line)){
      std::istringstream lineStream(line);
      lineStream >> pname;
      if(pname == this->name)
        pscore = this->score;
      else
        lineStream >> pscore;
      players.push_back(Player(pname, pscore));
    }

    f.close();
  }

  if(this->isNewPlayer) {
    players.push_back(Player(this->name, this->score));
  }

  //sort top score
  std::sort(players.begin(), players.end(), [](const Player a, const Player &b) -> bool{
    return a.score > b.score;
  });

  // Update scores
  std::ofstream fout;
  fout.open(SCORES_FILENAME, std::ofstream::trunc);
  for(auto &player: players)
  {
    fout << player.name << " " << std::to_string(player.score) << std::endl;
  }
	fout.close();
}