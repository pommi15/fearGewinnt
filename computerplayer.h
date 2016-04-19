/************************
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
class ComputerPlayer: public Player {
private:
  std::string coin;
public:
};

#endif  // INCLUDE_COMPUTERPLAYER_H_
