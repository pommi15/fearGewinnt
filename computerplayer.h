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
#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include <string>
#include "player.h"

/**
 * class for Computer players
 */
class ComputerPlayer : public Player {
public:
  /** constructor */
  ComputerPlayer(const std::string coin);
  /** decide where to drop the coin */
  int drop_choice(int boardwidth);
};

#endif  // COMPUTERPLAYER_H_
