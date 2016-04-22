/*************************
 *         0000          *
 *      fearGewinnt      *
 *         Game          *
 *          by           *
 *    Thomas RAUHOFER    *
 *        if15b029       *
 *          and          *
 *     Tobias WATZEK     *
 *        if15b038       *
 *************************/
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "humanplayer.h"

using namespace std;
/* Constructor */
HumanPlayer::HumanPlayer(const std::string &coin) : Player(coin) {}

int HumanPlayer::drop_choice(int boardwidth) {
  int column = boardwidth + 1;
  while (column < 1 || column > boardwidth) {
    cout << "Please enter a column to play between 1 and " << boardwidth
         << endl;
    cin >> column;
  }
  return column;
}
std::string HumanPlayer::coin_getter() { return this->coin; }
