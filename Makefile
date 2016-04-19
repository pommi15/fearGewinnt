# Makefile for mandelbrot
# Thomas Rauhofer and Tobias Watzek
# OOOO

CC=g++
CFLAGS=-g -Wall -std=c++11

all: connect4

connect4: connect4.o board.o player.o humanplayer.o computerplayer.o
	${CC} ${CFLAGS} connect4.o board.o player.o humanplayer.o computerplayer.o -o connect4

connect4.o: connect4.cpp
	${CC} ${CFLAGS} -c connect4.cpp -o connect4.o
board.o: board.cpp
	${CC} ${CFLAGS} -c board.cpp -o board.o
player.o: player.cpp
	${CC} ${CFLAGS} -c player.cpp -o player.o
humanplayer.o: humanplayer.cpp
	${CC} ${CFLAGS} -c humanplayer.cpp -o humanplayer.o
computerplayer.o: computerplayer.cpp
	${CC} ${CFLAGS} -c computerplayer.cpp -o computerplayer.o

.PHONY: clean
clean:
	rm -f *.o connect4
