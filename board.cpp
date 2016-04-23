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
#include <string>
#include <iostream>
#include <vector>

#include "board.h"

using namespace std;

/* Constructor taking width and height */
Board::Board(int width, int height)
    : width(width), height(height), winner("") {
  /** Create a tmp 2d vector */
  std::vector<std::vector<std::string>> tmp(height + 1);
  /** Loop trough the rows of the tmp vector */
  for (auto& row : tmp) {
    /**
    * Create a tmp row with the entered width plus one
    * for the numbering and fill with dots
    */
    std::vector<std::string> tmp_row(width + 1, ".");
    /** replace the row with the tmp row */
    row.swap(tmp_row);
  }
  /** swap the board with the tmp board */
  this->board.swap(tmp);
  /** Counter variable */
  int y_count = 1;
  /** Loop through the rows of the board */
  for (auto& row : this->board) {
    /** Add the row numbering to the board */
    if (y_count <= this->height) {
      row[width] = std::to_string(y_count);
    } else {
      /** Loop through the columns to add the numbering */
      for (int x = 0; x < width; ++x) {
        row[x] = std::to_string(x + 1);
      }
      /** Last  column is empty string */
      row[width] = "";
    }
    /** increment the countera */
    ++y_count;
  }
}
/**
* Function checking if a coin may be dropped into a column
* @param  column number of the column
* @return boolean true if space is available
*/
bool Board::column_check(int column) const {
  /** Check if the cell on the top is marked empty */
  return this->board[0][column - 1] == ".";
}

/**
* Function to drop coins into the board
* @param column column to drop the coin in
* @param player player who dropped the coin
*/
void Board::drop(int column, std::string player) {
  /** decrease the column by one */
  --column;
  /** loop through the rows */
  for (int y = 0; y <= height; ++y) {
    /** Check if the space is empty */
    if (this->board[y][column] != ".") {
      /** set the flag of the player */
      this->board[y - 1][column] = player;
      /** leave the loop */
      break;
    }
  }
}
/**
* Print the board to the screen
*/
void Board::draw() const {
  /** loop through the rows */
  for (auto& row : this->board) {
    /** loop through the columns of the row */
    for (int x = 0; x <= this->width; ++x) {
      /** not a single digit -> prepend with 1 space */
      if (row[x].size() > 1) {
        std::cout << " ";
      } else {
        /** single digit -> prepend with two spaces */
        std::cout << "  ";
      }
      /** print the cell */
      std::cout << row[x];
    }
    /** linebreak after the row */
    std::cout << std::endl;
  }
}

/**
* Check if there are four coins in a row
* @return winner
*/
std::string Board::win_check() const {
  /** winner flag */
  std::string winner;
  /** loop through the rows */
  for (int y = 0; y < height; ++y) {
    /** loop through the columns */
    for (int x = 0; x < width; ++x) {
      /** current cell is not empty */
      if (this->board[y][x] != ".") {
        /** set the winner to the current position */
        winner = this->board[y][x];
        /** check SW cells */
        /** check if still in the board */
        if (x > 2 && (y - 3) < height) {
          if (this->board[y + 1][x - 1] == winner &&
              this->board[y + 2][x - 2] == winner &&
              this->board[y + 3][x - 3] == winner) {
            return winner;
          }
        }
        /** check S cells */
        /** check if still in the board */
        if ((y + 3) < height) {
          if (this->board[y + 1][x] == winner &&
              this->board[y + 2][x] == winner &&
              this->board[y + 3][x] == winner) {
            return winner;
          }
        }

        /** check SE cells */
        if ((y + 3) < height && (x + 3) < width) {
          if (this->board[y + 1][x + 1] == winner &&
              this->board[y + 2][x + 2] == winner &&
              this->board[y + 3][x + 3] == winner) {
            return winner;
          }
        }

        /** check W tiles */
        if ((x + 3) < width) {
          if (this->board[y][x + 1] == winner &&
              this->board[y][x + 2] == winner &&
              this->board[y][x + 3] == winner) {
            return winner;
          }
        }
      }
    }
  }
  return "";
}

/**
 * Check if board is full
 * @return boolean true if it is full
 */
bool Board::full_board_check() const {
  /** loop through the columns */
  for (int x = 0; x < width; ++x) {
    /** check if column is free */
    if (column_check(x + 1)) {
      /** board is not full */
      return false;
    }
  }
  /** board is full */
  return true;
}

/**
 * Get the width of the board
 * @return width of board
 */
int Board::get_width() const {
  return this->width;
}
