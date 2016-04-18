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
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "player.h"

/* Constructor taking name */
Player::Player(const std::string name){
  this->name = name;
}
/* Destructor */
Player::~Player(){
}
