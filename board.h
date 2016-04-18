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
	std::vector<std::vector<std::string>> board;
public:
	Board(int width, int height);
	~Board();
	bool column_check(int column) const;
	void drop(int column);
  void draw() const;
	bool win_check(int x, int y, std::string player) const;
};

#endif  // INCLUDE_BOARD_H_
