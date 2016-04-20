/*************************
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
	void drop(int column, std::string player);
  void draw() const;
	std::string win_check() const;
	bool full_board_check() const;
};

#endif  // INCLUDE_BOARD_H_
