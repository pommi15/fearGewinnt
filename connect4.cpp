/************************
*			 	  0000          *
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

		cout << "Enter width: " << std::endl;
		cin >> width;
		cout << "Enter height: " << std::endl;
		cin >> height;

		std::unique_ptr<Board> fear(new Board(width, height));
		fear->draw();
		return 0;
}
