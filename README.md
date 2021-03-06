# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## General description

When the snake game starts, player will be asked to enter his/her name. After that a play window will pop-up with the snake and food. The player must use keyboard to move the snake toward food. If the snake hit the food the player will receive a score, and another food will be created at another place in the playing window. If the snake hit its body it will die and the game is over.

The player score is stored in a file after the game finishes. When the game starts the record will be read from the file and when the game finishes, if a new score is established, it will be written in the `scores.txt` file.

## Code structure

The code is organized in following modules:

controller
- game
- gmenu
- player
- renderer
- snake

| class name | Purpose  |
|------------|----------|
| Controller | Interact with users, let users use keyboard to control the snake in the game. |
| Game       | Game class stores the state in the game, running in loops til end. |
| GMenu      | Game Menu class handles command line player I/O. |
| Player     | Basic information about the player and storing the the score. |
| Render     | render the game to the screen. |
| Snake      | contains attributes to keep track of the Snake speed, size, and location. |

## Rubric Points

### Loops, Functions, I/O

- The project demonstrates an understanding of C++ functions and control structures. I used a lot of control structures and loops throut the code. In the `player.cpp` for example, in the [`Player::saveScore()`](https://github.com/webrgp/CppND-Capstone-Snake-Game/blob/c23a6e092744aef94c9cf6917c1e1b0e547b3702/src/player.cpp#L32-L46) method, I used if-statements to check if the `scores.txt` file exists, if not, then the program will create one. A while-loop to write the player data to the file.

- The project accepts user input and processes the input. The *GMenu* class is defined to accept user input and process the input. In `gmenu.cpp` [`GMenu::displayPlayerNamePrompt()`](https://github.com/webrgp/CppND-Capstone-Snake-Game/blob/c23a6e092744aef94c9cf6917c1e1b0e547b3702/src/gmenu.cpp#L3-L16), will let the user enter his player name to be used in the `scores.txt` file.

### Object Oriented Programming

- The project uses Object Oriented Programming techniques. The [*GMenu*](https://github.com/webrgp/CppND-Capstone-Snake-Game/blob/master/src/gmenu.cpp) class and [*Player*](https://github.com/webrgp/CppND-Capstone-Snake-Game/blob/master/src/player.cpp) class are defined to improve the structure of the program. Classes use appropriate access specifiers for class members and utilize member initialization lists.

### Memory Management

- Modify the `Game` contructor to use `GMenu` reference in the [`Game::Game(std::size_t grid_width, std::size_t grid_height, GMenu &gm)`](https://github.com/webrgp/CppND-Capstone-Snake-Game/blob/c23a6e092744aef94c9cf6917c1e1b0e547b3702/src/game.cpp#L5) line.