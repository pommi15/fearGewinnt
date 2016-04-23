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


#include "humanplayer.h"

/**
 * Constructor inherited from Player class
 */
HumanPlayer::HumanPlayer(const std::string &coin) : Player(coin) {}

/**
 * Get the column in which the player would like to drop his coin.
 * @param  boardwidth width of the board
 * @return            column
 */
int HumanPlayer::drop_choice(int boardwidth) {
  int column = 0;
  /** user has to enter a column between 1 and boardwidth */
  while (column < 1 || boardwidth < column) {
    std::cout << "Please enter a column to play between 1 and ";
    std::cout << boardwidth << std::endl;
    std::cin >> column;
  }
  return column;
}
