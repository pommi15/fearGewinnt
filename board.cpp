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
#include "board.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#define MAXBOARD 30

using namespace std;

/* Constructor taking width and height */
Board::Board(int width, int height): width(width), height(height), winner("None") {
	std::vector<std::vector<std::string>> tmp(height + 1);
	/*if height or width are bigger than 100 they are set to 100*/
	if(height >= MAXBOARD){
		height = MAXBOARD;
	}
	if(width >= MAXBOARD){
		width = MAXBOARD;
	}
	for(auto &row : tmp){
		std::vector<std::string> tmp_row(width + 1);
		row.swap(tmp_row);
	}
	this->board.swap(tmp);
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      this->board[y][x] = ".";
    }
    this->board[y][width] = std::to_string(y + 1);
  }
  for (int x = 0; x < width; ++x) {
    this->board[height][x] = std::to_string(x + 1);
  }
}
/* Destructor */
Board::~Board() {}
/*Function checking if a coin may be dropped into a column*/
bool Board::column_check(int column) const {
  if(this->board[0][column] != "."){
		return false;
	}
  return true;
}
/*Function for dropping in coins */
void Board::drop(int column) {
  for (int y = 0; y <= height; ++y) {
    if (this->board[y][column] != ".") {
      this->board[y - 1][column] = "X";
    }
  }
}
/*Function for drawing the board*/
void Board::draw() const {
  // Go through every row
  for (int y = 0; y <= this->height; ++y) {
    // Go through every column
    for (int x = 0; x <= this->width; ++x) {
      // Cout the pixel
			if(this->width > 9 && y != this->height){
      	std::cout << "  " << this->board[y][x];
			}else{
				if(this->board[y][x].size() == 1 || this->board[y][x] == "10"){
					std::cout << " ";
				}
				std::cout << " " << this->board[y][x];

			}
		}
    // Print a linebreak after every row
    std::cout << std::endl;
  }
}
/*checks if there are 4 pieces in a row*/
bool Board::win_check(int x, int y, std::string player) const {
  /*checks if given space even has a players stone in it*/
  if (this->board[y][x] == ".") {
    return false;
  } else {
    player = this->board[y][x];
  }
  /*checkt NE tiles*/
  if (this->board[y + 1][x - 1] == player) {
    if (this->board[y + 2][x - 2] == player &&
        this->board[y + 3][x - 3] == player) {
      return true;
    }
    /*checkt E tiles*/
  } else if (this->board[y + 1][x] == player) {
    if (this->board[y + 2][x] == player && this->board[y + 3][x] == player) {
      return true;
    }
    /*checkt SE tiles*/
  } else if (this->board[y + 1][x + 1] == player) {
    if (this->board[y + 2][x + 2] == player &&
        this->board[y + 3][x + 3] == player) {
      return true;
    }
    /*checkt S tiles*/
  } else if (this->board[y][x + 1] == player) {
    if (this->board[y][x + 2] == player && this->board[y][x + 3] == player) {
      return true;
    }
  }
  return false;
}
