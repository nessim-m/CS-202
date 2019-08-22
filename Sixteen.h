#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class sixteen
{
public:
  static const int SIZE=3;//represents the number of rows and columns the game board has.
  static const int WIN=16;// represents the number that must be in a tile in order to win.
  sixteen();// the default constructor, sets all the elements in board to 0 except for the top left and bottom left elements, will be set to the value of 2.
  void moveLeft();// slides all the tiles on each row to the left and combines two adjacent non zero tiles from left to right into one tile and set a value 2 in a random position.
  void moveRight();// slides all the tiles on each row to the right and combines two adjacent non zero tiles from right to left into one tile and set a value 2 in a random position.
  void moveUp(); //slides all the tiles on each column to the top and combines two adjacent non zero tiles from top to bottom into one tile and set a value 2 in a random position.
  void moveDown();// slides all the tiles on each column to the bottom and combines two adjacent non zero tiles from bottom to top into one tile and set a value 2 in a random position.
  int over() const;// it checks the status of the game and determines loss and win, otherwsie it returns continue.
  void output() const;// it outputs the game board on the screen after each move.

private:
  int board[SIZE][SIZE];//declared 2d array that represents the game board.
};