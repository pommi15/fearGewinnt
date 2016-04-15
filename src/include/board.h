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
#ifndef SRC_INCLUDE_BOARD_H_
#define SRC_INCLUDE_BOARD_H_
#include <string>
#include <iostream>
#include <vector>

class Board {
private:
		int width;
		int height;
		std::vector< std::vector <std::string> > board;
public:
		Board(int width, int height);
		~Board();
		bool drop(int coloumn);
		const void draw();
};

#endif  // SRC_INCLUDE_BOARD_H_
