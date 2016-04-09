/************************
*       @>--}---        *
*       fearGewinnt     *
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

class Board {
public:
		Board(int width, int height);
		~Board();
		bool drop();
		void draw();
};

#endif  // SRC_INCLUDE_BOARD_H_