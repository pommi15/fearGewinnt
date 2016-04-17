/************************
*			  	0000	        *
*      fearGewinnt      *
*         Game          *
*          by           *
*    Thomas RAUHOFER    *
*        if15b029       *
*          and          *
*     Tobias WATZEK     *
*        if15b038       *
*************************/
#ifndef INCLUDE_PLAYERS_H_
#define INCLUDE_PLAYERS_H_
#include <string>
#include <iostream>
#include <vector>

class Player {
private:
  std::string name;
public:
  Player(const std::string name);
  ~Player();
}
#endif  // INCLUDE_PLAYERS_H_
