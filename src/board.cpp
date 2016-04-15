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
/* Constucotr taking width and height */
Board::Board(int width, int height){
	std::vector< std::vector <std::string> > board;
	std::string winner = "None";
	for(int i = 0; i < height; ++i){
		for(int j = 0; j < width; ++j){
			board[i][j] = '.';
		}
		board[i][width]= std::to_string(i);
	}
	for(int i = 0; i < width; ++i){
		board[i][height] = std::to_string(i+1);
	}
}
/* Destructor */
Board::~Board(){
}
/*Function for dropping in coins *//*
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
}*/
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
