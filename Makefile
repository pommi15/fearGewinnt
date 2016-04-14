# Makefile for mandelbrot
# Thomas Rauhofer and Tobias Watzek
# OOOO

OBJDIR=.
OUTDIR=.
SRCDIR=src
VPATH=$(SRCDIR):$(OBJDIR)
CC=g++
CFLAGS=-g -Wall -O -std=c++11

all: directories fearGewinnt

fearGewinnt: connect4.o board.o
	${CC} ${CFLAGS} $(OBJDIR)/connect4.o $(OBJDIR)/connect4.o -o $(OUTDIR)/fearGewinnt

connect4.o: connect4.cpp board.o
	${CC} ${CFLAGS} -c $(SRCDIR)/connect4.cpp -o $(OBJDIR)/connect4.o
board.o: board.cpp $(SRCDIR)/include/board.h
	${CC} ${CFLAGS} -c $(SRCDIR)/board.cpp -o $(OBJDIR)/board.o

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o fearGewinnt

.PHONY: directories
directories:
	mkdir -p $(OBJDIR) $(OUTDIR)
