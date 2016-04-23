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
#ifndef BOARD_H_
#define BOARD_H_
#include <string>
#include <iostream>
#include <vector>

class Board {
 private:
 	/** width of the board */
  int width;
  /** height of the board */
  int height;
  /** winner of the game */
  std::string winner;
  /** board */
  std::vector<std::vector<std::string>> board;

 public:
 	/** constructor */
  Board(int width, int height);
  bool column_check(int column) const;
  void drop(int column, std::string player);
  void draw() const;
  std::string win_check() const;
  bool full_board_check() const;
  int get_width() const;
};

#endif  // BOARD_H_
