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
#include "include/players.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

/* Constructor taking name */
Players::Players(const std::string name){
  this->name = name;
}
/* Destructor */
Players::~Players(){
}

/* Constructor taking name */
HumanPlayers::HumanPlayers(const std::string name){
  this->name = name;
}
/* Destructor */
HumanPlayers::~HumanPlayers(){
}

/* Constructor taking name */
ComputerPlayers::ComputerPlayers(const std::string name){
  this->name = name;
}
/* Destructor */
ComputerPlayers::~ComputerPlayers(){
}
