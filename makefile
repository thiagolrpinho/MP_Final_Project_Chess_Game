IDIR	=./include
CC      = g++ -std=c++11
CFLAGS  = -Wall -g -I$(IDIR) --coverage 
GCOVFLAGS = $(CFLAGS) --coverage -fPIC  -O0 

ODIR	= ./src/obj
LDIR	=./lib
SDIR	=./src
TDIR	=./tests

LIBS	=-lm
	
_DEPS	= board.hpp board_square.hpp catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_TOBJ = board_square.o board.o tests_board.o tests_board_square.o tests_main.o
TOBJ = $(patsubst %,$(ODIR)/%,$(_TOBJ))

_OBJ = board.o board_square.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC)	-c	-o 	$@	$<	$(CFLAGS)

$(ODIR)/%.o: $(TDIR)/%.cpp $(DEPS)
	$(CC)	-c	-o 	$@	$<	$(CFLAGS) 

play_game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

board_square_tester:$(TOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

gcov_board_square: $(TOBJ)
	$(CC) $(GCOVFLAGS) -o $@ $^ $(LIBS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
