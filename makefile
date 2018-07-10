

IDIR	=./include
CC      = g++ -std=c++14
CFLAGS  = -Wall -g -I$(IDIR) --coverage 
GCOVFLAGS = $(CFLAGS) --coverage -fPIC  -O0 

ODIR	= ./src/obj
LDIR	=./lib
SDIR	=./src
TDIR	=./tests
PIECESDIR = ./src/pieces
CONTROLLERDIR = ./src/controller

LIBS	=-lm
	
_DEPS	= controller.hpp salvar.hpp player.hpp engine.hpp board.hpp square.hpp king.hpp queen.hpp bishop.hpp rook.hpp knight.hpp pawn.hpp restricted_piece.hpp piece.hpp catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_TOBJ = controller.o salvar.o player.o engine.o board.o square.o king.o queen.o bishop.o rook.o knight.o pawn.o restricted_piece.o piece.o tests_square.o tests_main.o
TOBJ = $(patsubst %,$(ODIR)/%,$(_TOBJ))

_OBJ = controller.o salvar.o player.o engine.o board.o square.o king.o queen.o bishop.o rook.o knight.o pawn.o restricted_piece.o piece.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(CONTROLLERDIR)/%.cpp $(DEPS)
	$(CC)	-c	-o 	$@	$<	$(CFLAGS)

$(ODIR)/%.o: $(PIECESDIR)/%.cpp $(DEPS)
	$(CC)	-c	-o 	$@	$<	$(CFLAGS)

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

_TOBJ += tests_player.o
TOBJ = $(patsubst %,$(ODIR)/%,$(_TOBJ))

player_tester:$(TOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

gcov_player: $(TOBJ)
	$(CC) -o $@ $^ $(GCOVFLAGS) $(LIBS)


_TOBJ += tests_pieces.o
TOBJ = $(patsubst %,$(ODIR)/%,$(_TOBJ))

pieces_tester:$(TOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

gcov_pieces: $(TOBJ)
	$(CC) -o $@ $^ $(GCOVFLAGS) $(LIBS)


_TOBJ += tests_controller.o
TOBJ = $(patsubst %,$(ODIR)/%,$(_TOBJ))

controller_tester:$(TOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

gcov_controller: $(TOBJ)
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

