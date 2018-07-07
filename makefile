IDIR	=./include
#CC      = g++ -std=c++11
CFLAGS  = -I$(IDIR)
#GCOVFLAGS = $(CFLAGS) --coverage -fPIC  -O0 

#ODIR	= ./src/obj
#LDIR	=./lib
#SDIR	=./src
#TDIR	=./tests

#LIBS	=-lm

#OBJS specifies which files to compile as part of the project
OBJS = ./src/main.cpp ./src/display.cpp ./src/LTexture.cpp

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I"D:/UnB/MP/TrabalhoFinal/MP_Final_Project_Chess_Game/i686-w64-mingw32/include/SDL2"

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L"D:/UnB/MP/TrabalhoFinal/MP_Final_Project_Chess_Game/i686-w64-mingw32/lib"

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_Image -lSDL2_ttf

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

