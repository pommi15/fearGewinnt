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
#include "include/board.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
/* Constructor taking width and height */
Players::Players(const std::string name){
  this->name = name;
}
/* Destructor */
Players::~Players(){
}
