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
  return this->board[0][column-1] == ".";
}
/*Function for dropping in coins */
int Board::drop(int column) {
	int coin;
  for (int y = 0; y <= height; ++y) {
    if (this->board[y][column-1] != ".") {
      this->board[y - 1][column-1] = "X";
			coin = y;
			break;
    }
	}
	return coin;
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
std::string Board::win_check() const {
	std::string winner;
  /*checks if given space even has a players stone in it*/
	for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
			if (this->board[y][x] != ".") {
				winner = this->board[y][x];
				if(x>2 && (y-3) < height){
					/*checkt SW tiles*/
				  if (this->board[y + 1][x - 1] == winner) {
				    if (this->board[y + 2][x - 2] == winner &&
				        this->board[y + 3][x - 3] == winner) {
				      return winner;
				    }
					}
				}
				if((y + 3) < height){
				  /*checkt S tiles*/
					if (this->board[y + 1][x] == winner) {
				    if (this->board[y + 2][x] == winner && this->board[y + 3][x] == winner) {
				      return winner;
				    }
					}
				}
				if((y + 3) < height && (x + 3) < width){
				  /*checkt SE tiles*/
					if (this->board[y + 1][x + 1] == winner) {
				    if (this->board[y + 2][x + 2] == winner && this->board[y + 3][x + 3] == winner) {
				      return winner;
				    }
					}
				}
				if((x + 3) < width){
				  /*checkt W tiles*/
					if (this->board[y][x + 1] == winner) {
				    if (this->board[y][x + 2] == winner && this->board[y][x + 3] == winner) {
				      return winner;
				    }
				  }
				}
			}
		}
	}
	return "None";
}
