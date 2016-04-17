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
/*Function checking if a coin may be dropped into a coloumn*/
bool Board::coloumn_check(){
	if (this->board[coloumn][0] != '.') {
			return false;
	}
}
/*Function for dropping in coins */
bool Board::drop(int coloumn){
		for (int i = 0; i < height; ++i) {
				if (this->board[coloumn][i] != '.') {
						this->board[coloumn][i - 1] = 'X';
				}
		}
		return true;
}
/*Function for drawing the board*/
const void Board::draw(){
		// Go through every row
		for (int i = 0; i <= this->height; ++i) {
				// Go through every column
				for (int j = 0; j <= this->width; ++j) {
						// Cout the pixel
						std::cout << board[i][j];
				}
				// Print a linebreak after every row
				std::cout << std::endl;
		}
}
bool Board::win_check(int x, int y, std::string player){
		/*checkt NE tiles*/
		if(this->board[x+1][y-1] == player)[
			if(this->board[x+2][y-2] == player && this->board[x+3][y-3] == player){
				return true;
			}
		/*checkt E tiles*/
		]else if(this->board[x+1][y] == player){
			if(this->board[x+2][y] == player && this->board[x+3][y] == player){
				return true;
			}
		/*checkt SE tiles*/
		}else if(this->board[x+1][y+1] == player){
			if(this->board[x+2][y+2] == player && this->board[x+3][y+3] == player){
				return true;
			}
		/*checkt S tiles*/
		}else if(this->board[x][y+1] == player){
			if(this->board[x][y+2] == player && this->board[x][y+3] == player){
				return true;
			}
		}
		return false;
	}
