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
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "humanplayer.h"

int Humanthrow(int boardWidth) {
  int column;
  while(column < 1 && column > boardwidth){
    cout << "Please enter a column to play between 1 and " << boardWidth << endl;
    cin >> column;
  }
  return column;
}
