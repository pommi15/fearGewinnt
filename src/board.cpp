/************************
*								 0000	         *
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

Board::Board(int width, int height){
	std::vector< std::vector <std::string> > board;
	for(int i = 0; i < width; ++i){
		for(int j = 0; j < height; ++j){
			board[i][j] = '.';
		}
	}
	for(int i = 0; i < width; ++i){
		board[i][height] = i + 1;
	}
}
Board::~Board(){
}
bool Board::drop(int coloumn){
		if (this->board[coloumn][0] != '.') {
				return false;
		}
		for (int i = 0; i < height; ++i) {
				if (this->board[coloumn][i] != '.') {
						this->board[coloumn][i - 1] = 'X';
				}
		}
		return true;
}
const void Board::draw(){
		// Go through every row
		for (int i = 0; i < this->height; ++i) {
				// Go through every column
				for (int j = 0; j < this->width; ++j) {
						// Cout the pixel
						std::cout << board[i][j];
				}
				// Print a linebreak after every row
				std::cout << std::endl;
		}
}
