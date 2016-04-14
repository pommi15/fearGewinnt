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
#define FILLER '.'

Board::Board(int width, int height){
		// Make the board rows
		this->board = new std::string *[this->height];
		// Create the columns row for row
		for (int i = 0; i < this->height; ++i) {
				this->board[i] = new std::string[this->width];
				for (int j = 0; j < this->width; ++j) {
						// Fill each column with a the Filler
						this->board[i][j] = FILLER;
				}
		}
}
Board::~Board(){
		// Go through every row and delete it
		for (int i = 0; i < this->height; ++i) {
				delete[] this->board[i];
		}
		// delete the board
		delete[] this->board;
}
bool Board::drop(int coloumn){
		if (this->board[coloumn][0] != FILLER) {
				return false;
		}
		for (int i = 0; i < height; ++i) {
				if (this->board[coloumn][i] != FILLER) {
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
