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
#ifndef INCLUDE_BOARD_H_
#define INCLUDE_BOARD_H_
#include <string>
#include <iostream>
#include <vector>

class Board {
private:
	int width;
	int height;
	std::string winner;
	std::vector< std::vector <std::string> > board;
public:
	Board(int width, int height);
	~Board();
	bool coloumn_check();
	bool drop(int coloumn);
	const void draw();
	bool win_check(int x, int y, std::string player);
};

#endif  // INCLUDE_BOARD_H_
