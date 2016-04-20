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
#include <fstream>
#include <memory>
#include "board.h"
#include "player.h"
#include "humanplayer.h"
#include "computerplayer.h"

using namespace std;


int main() {
	/* Width of the board */
	int width = 0;
	/* Height of the board */
	int height = 0;
	/* int value to chose player A */
	int player_one = 10;
	/* int value to chose player B */
	int player_two = 10;
	/* bool for fullness of board*/
	bool full = false;
	/* entering the width and the height of our board */
	cout << "Enter width: " << std::endl;
	cin >> width;
	while(width > 30){
		cout << "A width of " << width << " is a little big..." << endl;
		cout << "Please enter a smaller number." << endl;
	}
	cout << "Enter height: " << std::endl;
	cin >> height;
	while(height > 30){
		cout << "A height of " << height << " is a little big..." << endl;
		cout << "Please enter a smaller number." << endl;
	}
	/* choice of player pairings */
	cout << "Who is the first player?" << std::endl;
	while(player_one < 1 || player_one > 2){
		cout << "Press 1 for Human 2 for Computer!" << std::endl;
		cin >> player_one;
	}
	cout << "Who is the second player?" << std::endl;
	while(player_two < 1 || player_two > 2){
		cout << "Press 1 for Human 2 for Computer!" << std::endl;
		cin >> player_two;
	}
	/* check which player combination was chosen */
	if(player_one == 1){
		if(player_two == 1){
			std::unique_ptr<HumanPlayer> player1(new HumanPlayer("A"));
			std::unique_ptr<HumanPlayer> player2(new HumanPlayer("B"));
			/* board is created */
			std::unique_ptr<Board> fear(new Board(width, height));

			while(fear->win_check() == "None"){
				/*Player A drops first*/
				cout << "Player A:" << endl;
				fear->draw();
				int choice = player1->drop_choice(width);
				while(fear->column_check(choice) == false){
					cout << "Not a valid choice" << endl;
					choice = player1->drop_choice(width);
				}
				fear->drop(choice, player1->coin_getter());
				if(fear->full_board_check()){
					full = true;
					fear->draw();
					break;
				}
				/*Player B drops second*/
				if(fear->win_check() == "None"){
					cout << "Player B:" << endl;
					fear->draw();
					int choice = player2->drop_choice(width);
					while(fear->column_check(choice) == false){
						cout << "Not a valid choice" << endl;
						choice = player1->drop_choice(width);
					}
					fear->drop(choice, player2->coin_getter());
					if(fear->full_board_check()){
						full = true;
						fear->draw();
						break;
					}
				}
			}
			if(!full){
				fear->draw();
				cout << "And the Winner is: " << fear->win_check() << std::endl;
			}
		}else{
			std::unique_ptr<HumanPlayer> player1(new HumanPlayer("A"));
			std::unique_ptr<ComputerPlayer> player2(new ComputerPlayer("B"));

			/* board is created */
			std::unique_ptr<Board> fear(new Board(width, height));

			while(fear->win_check() == "None"){
				/*Player A drops first*/
				cout << "Player A:" << endl;
				fear->draw();
				int choice = player1->drop_choice(width);
				while(fear->column_check(choice) == false){
					cout << "Not a valid choice" << endl;
					choice = player1->drop_choice(width);
				}
				fear->drop(choice, player1->coin_getter());
				if(fear->full_board_check()){
					full = true;
					fear->draw();
					break;
				}
				/*Player B drops second*/
				if(fear->win_check() == "None"){
					cout << "Player B:" << endl;
					fear->draw();
					int choice = player2->drop_choice(width);
					while(fear->column_check(choice) == false){
						choice = player2->drop_choice(width);
					}
					fear->drop(choice, player2->coin_getter());
					if(fear->full_board_check()){
						full = true;
						fear->draw();
						break;
					}
				}
			}
			if(!full){
				fear->draw();
				cout << "And the Winner is: " << fear->win_check() << std::endl;
			}
		}
	}else{
		if(player_two == 1){
			std::unique_ptr<ComputerPlayer> player1(new ComputerPlayer("A"));
			std::unique_ptr<HumanPlayer> player2(new HumanPlayer("B"));

			/* board is created */
			std::unique_ptr<Board> fear(new Board(width, height));

			while(fear->win_check() == "None"){
				/*Player A drops first*/
				cout << "Player A:" << endl;
				fear->draw();
				int choice = player1->drop_choice(width);
				while(fear->column_check(choice) == false){

					choice = player1->drop_choice(width);
				}
				fear->drop(choice, player1->coin_getter());
				if(fear->full_board_check()){
					full = true;
					fear->draw();
					break;
				}
				/*Player B drops second*/
				if(fear->win_check() == "None"){
					cout << "Player B:" << endl;
					fear->draw();
					int choice = player2->drop_choice(width);
					while(fear->column_check(choice) == false){
						cout << "Not a valid choice" << endl;
						choice = player2->drop_choice(width);
					}
					fear->drop(choice, player2->coin_getter());
					if(fear->full_board_check()){
						full = true;
						fear->draw();
						break;
					}
				}
			}
			if(!full){
				fear->draw();
				cout << "And the Winner is: " << fear->win_check() << std::endl;
			}
		}else{
			std::unique_ptr<ComputerPlayer> player1(new ComputerPlayer("A"));
			std::unique_ptr<ComputerPlayer> player2(new ComputerPlayer("B"));

			/* board is created */
			std::unique_ptr<Board> fear(new Board(width, height));

			while(fear->win_check() == "None"){
				/*Player A drops first*/
				cout << "Player A:" << endl;
				fear->draw();
				int choice = player1->drop_choice(width);
				while(fear->column_check(choice) == false){

					choice = player1->drop_choice(width);
				}
				fear->drop(choice, player1->coin_getter());
				if(fear->full_board_check()){
					full = true;
					fear->draw();
					break;
				}
				/*Player B drops second*/
				if(fear->win_check() == "None"){
					cout << "Player B:" << endl;
					fear->draw();
					int choice = player2->drop_choice(width);

					while(fear->column_check(choice) == false){
						choice = player2->drop_choice(width);
					}
					fear->drop(choice, player2->coin_getter());
					if(fear->full_board_check()){
						full = true;
						fear->draw();
						break;
					}
				}
			}
			if(!full){
				fear->draw();
				cout << "And the Winner is: " << fear->win_check() << std::endl;
			}
		}
	}
	if(full){
		cout << "The board is full, nobody won. How sad..." << endl;
	}

	return 0;
}
