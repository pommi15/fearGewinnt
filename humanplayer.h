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
#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_
#include <string>
#include "player.h"
/**
 * Class for human player
 */
class HumanPlayer : public Player {
public:
  /** constructor */
  HumanPlayer(const std::string &coin);
  /** get the column in which the player would like to drop a coin*/
  int drop_choice(int boardwidth);
};
#endif  // HUMANPLAYER_H_
