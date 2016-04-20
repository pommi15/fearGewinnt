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
#ifndef INCLUDE_PLAYERS_H_
#define INCLUDE_PLAYERS_H_
#include <string>
#include <iostream>
#include <vector>
/* main class */
class Player {
protected:
  std::string coin;
public:
  Player(const std::string &coin);
  virtual ~Player();
  std::string coin_getter();
};


#endif  // INCLUDE_PLAYERS_H_
