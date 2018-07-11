IDIR	=./include
CC      = g++ -std=c++14
CFLAGS  = -Wall -g -I$(IDIR) --coverage -no-pie
GCOVFLAGS = $(CFLAGS) --coverage -fPIC  -O0

ODIR	= ./src/obj
LDIR	=./lib
SDIR	=./src
TDIR	=./tests
PIECESDIR = ./src/pieces
CONTROLLERDIR = ./src/controller

#OBJS specifies which files to compile as part of the project
OBJSIG = ./src/main.cpp ./src/display.cpp ./src/LTexture.cpp

#CC specifies which compiler we're using
CCIG = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I"i686-w64-mingw32/include/SDL2"

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L"i686-w64-mingw32/lib"

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_Image -lSDL2_ttf

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game

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

#This is the target that compiles our executable
gameig : $(OBJS)
	$(CCIG) $(OBJSIG) $(CFLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	rm -f $(ODIR)/*.gcno *~ core $(INCDIR)/*~
	rm -f $(ODIR)/*.gcda *~ core $(INCDIR)/*~
