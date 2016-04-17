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
  std::string name;
public:
  Player(const std::string name);
  ~Player();
}
/*class for Human players*/
class HumanPlayer public Payer {
private:
  std::string name;
public:
  HumanPlayer(const std::string name);
}
/*class for Computer players*/
class ComputerPlayer public Payer {
private:
  std::string name;
public:
  ComputerPlayer(const std::string name);
}
#endif  // INCLUDE_PLAYERS_H_
