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
#ifndef INCLUDE_COMPUTERPLAYER_H_
#define INCLUDE_COMPUTERPLAYER_H_

#include <string>
#include <iostream>
#include <vector>
#include "player.h"

/*class for Computer players*/
class ComputerPlayer : public Player {
public:
  ComputerPlayer(const std::string coin);
  int drop_choice(int boardwidth);
  std::string coin_getter();
};

#endif  // INCLUDE_COMPUTERPLAYER_H_
