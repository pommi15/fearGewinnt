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
	// Width of the board
	int width = 0;
	// Height of the board
	int height = 0;
	int player_one = 10;
	int player_two = 10;
	cout << "Enter width: " << std::endl;
	cin >> width;
	cout << "Enter height: " << std::endl;
	cin >> height;
	cout << "Who is the first player?" << std::endl;
	/* choice of player pairings */
	while(player_one < 1 || player_one > 2){
		cout << "Press 1 for Human 2 for Computer!" << std::endl;
		cin >> player_one;
	}
	cout << "Who is the second player?" << std::endl;
	while(player_two < 1 || player_two > 2){
		cout << "Press 1 for Human 2 for Computer!" << std::endl;
		cin >> player_two;
	}
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
				/*Player 2 drops second*/
				if(fear->win_check() == "None"){
					cout << "Player B:" << endl;
					fear->draw();
					int choice = player2->drop_choice(width);
					while(fear->column_check(choice) == false){
						cout << "Not a valid choice" << endl;
						choice = player1->drop_choice(width);
					}
					fear->drop(choice, player2->coin_getter());
				}
			}
			fear->draw();
			cout << "And the Winner is: " << fear->win_check() << std::endl;
		}else{
			std::unique_ptr<HumanPlayer> player1(new HumanPlayer("A"));
			std::unique_ptr<ComputerPlayer> player2(new ComputerPlayer("B"));
		}
	}else{
		if(player_two == 1){
			std::unique_ptr<ComputerPlayer> player1(new ComputerPlayer("A"));
			std::unique_ptr<HumanPlayer> player2(new HumanPlayer("B"));
		}else{
			std::unique_ptr<ComputerPlayer> player1(new ComputerPlayer("A"));
			std::unique_ptr<ComputerPlayer> player2(new ComputerPlayer("B"));
		}
	}


	return 0;
}
