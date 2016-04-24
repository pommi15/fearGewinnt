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
#include <cstdlib>
#include <ctime>

#include "computerplayer.h"

using namespace std;
/**
 * Constructor
 */
ComputerPlayer::ComputerPlayer(const std::string coin) : Player(coin) {
  /** create a new random seed based on the current time */
  std::srand(std::time(nullptr));
}

/**
 * Decide where to drop the coin.
 * Uses the sneaky random algorithm to decide.
 * @param  boardwidth width of the board
 * @return            colum to drop the coin
 */
int ComputerPlayer::drop_choice(int boardwidth) {
  /** pick a random column between 1 and boardwidth */
  int column = std::rand() % boardwidth + 1;
  return column;
}
