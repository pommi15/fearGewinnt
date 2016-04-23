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
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "player.h"

/**
 * Constructor taking coin of the player
 */
Player::Player(const std::string& coin) : coin(coin) {}
/** Get the coin of the player */
std::string Player::get_coin() {
  return this->coin;
}
int Player::drop_choice(int boardwidth) {return 0;}
