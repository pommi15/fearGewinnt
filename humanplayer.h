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
#ifndef INCLUDE_HUMANPLAYER_H_
#define INCLUDE_HUMANPLAYER_H_
#include <string>
#include <iostream>
#include <vector>
#include "player.h"
/*class for Human players*/
class HumanPlayer: public Player {
private:
  std::string coin;
public:
  int human_drop();
};
#endif // INCLUDE_HUMANPLAYER_H_
