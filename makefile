IDIR	=./include
CC      = g++ -std=c++11
CFLAGS  = -Wall -g -I$(IDIR) --coverage 
GCOVFLAGS = $(CFLAGS) --coverage -fPIC  -O0 

ODIR	= ./src/obj
LDIR	=./lib
SDIR	=./src
TDIR	=./tests

LIBS	=-lm
	
_DEPS	= engine.hpp board.hpp square.hpp queen.hpp king.hpp bishop.hpp knight.hpp pawn.hpp rook.hpp restrictedPiece.hpp piece.hpp catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_TOBJ = engine.o board.o square.o queen.o king.o bishop.o knight.o pawn.o rook.o restrictedPiece.o piece.o tests_square.o tests_main.o
TOBJ = $(patsubst %,$(ODIR)/%,$(_TOBJ))

_OBJ = engine.o board.o square.o queen.o king.o bishop.o knight.o pawn.o rook.o restrictedPiece.o piece.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC)	-c	-o 	$@	$<	$(CFLAGS)

$(ODIR)/%.o: $(TDIR)/%.cpp $(DEPS)
	$(CC)	-c	-o 	$@	$<	$(CFLAGS) 

square_tester:$(TOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

gcov_square: $(TOBJ)
	$(CC) $(GCOVFLAGS) -o $@ $^ $(LIBS)


_TOBJ += tests_board.o
TOBJ = $(patsubst %,$(ODIR)/%,$(_TOBJ))

board_tester:$(TOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

gcov_board: $(TOBJ)
	$(CC) -o $@ $^ $(GCOVFLAGS) $(LIBS)


_TOBJ += tests_engine.o
TOBJ = $(patsubst %,$(ODIR)/%,$(_TOBJ))

engine_tester:$(TOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

gcov_engine: $(TOBJ)
	$(CC) -o $@ $^ $(GCOVFLAGS) $(LIBS)


play_game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

gcovr_html:
	gcovr -r . --html --html-details -o ./tests/gcov/tests-detailts.html

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	rm -f $(ODIR)/*.gcno *~ core $(INCDIR)/*~
	rm -f $(ODIR)/*.gcda *~ core $(INCDIR)/*~
