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
/*main class*/
class Player {
private:
  std::string coin;
public:
  Player(const std::string coin);
  ~Player();
};


#endif  // INCLUDE_PLAYERS_H_
