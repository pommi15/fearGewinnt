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
#include <memory>

#include "board.h"
#include "player.h"
#include "humanplayer.h"
#include "computerplayer.h"
#define MAX_BOARD_SIZE 30

/**
 * Check if the entered size is in the allowed board size
 * @param  size enterd width or height
 * @return      false if size is not in the range else true
 */
bool check_size(const int& size) {
  /** Size is bigger than allowed board size */
  if (size > MAX_BOARD_SIZE) {
    std::cout << size << " is a little big..." << std::endl;
    std::cout << "Please enter a smaller number." << std::endl;
  }
  /** Size is smaller than 1 not possible */
  else if (size < 1) {
    std::cout << size << " is a little small..." << std::endl;
    std::cout << "Please enter a bigger number." << std::endl;
  }
  /** Size is ok */
  else {
    return true;
  }
  std::cout << std::endl;
  return false;
}

/**
 * Get the player type
 * @return 0 for computer and 1 for human
 */
bool select_player_type() {
  int select_player = -1;
  /** ask for a valid value */
  while (select_player < 0 || select_player > 1) {
    std::cout << "Press 1 for Human 0 for Computer!" << std::endl;
    std::cin >> select_player;
  }
  return select_player;
}

/**
 * turn of a player
 * @param  player current player
 * @param  board  playing board
 * @return        true if board is full or false if not
 */
bool turn(const std::shared_ptr<Player> player, std::shared_ptr<Board> board) {
  std::cout << std::endl;
  /** print the board */
  board->draw();
  /** print the player */
  std::cout << std::endl << "Player " << player->get_coin() << ":" << std::endl;
  /** selected column of the player */
  int choice = 0;
  do {
    /** the player has selected at least once */
    if (choice) {
      std::cout << "There is no space for your coin at column: " << choice
                << std::endl;
    }
    /** get the choice of the player */
    choice = player->drop_choice(board->get_width());
  } while (!board->column_check(choice));
  /** insert coin */
  board->drop(choice, player->get_coin());
  /** return if the board is full */
  return board->full_board_check();
}

int main() {
  unsigned int turn_count = 0;
  /** board width */
  int width = 0;
  /** board height */
  int height = 0;
  /** bool defining if board is full*/
  bool full = false;
  /** first player */
  std::shared_ptr<Player> player1;
  /** second player */
  std::shared_ptr<Player> player2;

  std::cout << "Welcome to connect4" << std::endl << std::endl;
  std::cout << "Let's create the board:" << std::endl;

  /** get the width of the board */
  do {
    std::cout << "Enter width: " << std::endl;
    std::cin >> width;
  } while (!check_size(width));

  /** get the height of the board */
  do {
    std::cout << "Enter height: " << std::endl;
    std::cin >> height;
  } while (!check_size(height));

  /** create the board */
  auto board = std::make_shared<Board>(width, height);

  std::cout << std::endl
            << "Created the board. Let's create the players." << std::endl;
  /** select the type of the first player */
  std::cout << "Who is the first player?" << std::endl;
  /** human player */
  if (select_player_type()) {
    /** reset the ptr to a HumanPlayer */
    player1.reset(new HumanPlayer("A"));
    std::cout << "Created a boaring Human (muhahaha)." << std::endl;
  } else {
    /** reset the ptr to a ComputerPlayer */
    player1.reset(new ComputerPlayer("A"));
    std::cout << "Created a Termina...Computer." << std::endl;
  }
  /** select the type of the second player */
  std::cout << "Who is the second player?" << std::endl;
  /** human player */
  if (select_player_type()) {
    /** reset the ptr to a HumanPlayer */
    player2.reset(new HumanPlayer("B"));
    std::cout << "Created a boaring Human." << std::endl;
  } else {
    /** reset the ptr to a ComputerPlayer */
    player2.reset(new ComputerPlayer("B"));
    std::cout << "Created a Termina...Computer." << std::endl;
  }
  std::cout << std::endl << "Everything is set up. Let's play!" << std::endl;
  /** take turns until a winner is found or the board is full */
  while (!full && board->win_check() == "") {
    /** on each eaven turn the second player plays on each odd the first player
     * plays */
    full = ((turn_count) % 2 ? turn(player2, board) : turn(player1, board));
    /** increase the turn count */
    ++turn_count;
  }
  std::cout << std::endl << "The game has ended" << std::endl;
  board->draw();
  if (!full) {
    std::cout << std::endl
              << "And the Winner is: " << board->win_check() << std::endl;
  } else {
    std::cout << std::endl
              << "The board is full, nobody won. How sad..." << std::endl;
  }

  return 0;
}
