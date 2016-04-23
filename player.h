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
#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

class Player {
protected:
  /** coin of the player */
  std::string coin;
public:
  /** constructor */
  Player(const std::string &coin);
  /** get the coin of the player */
  virtual std::string get_coin();
  virtual int drop_choice(int boardwidth);
};


#endif  // PLAYER_H_
